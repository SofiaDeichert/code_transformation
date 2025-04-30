# Sofia Deichert - Code Transformation Project
# ch-define: modifications to variable definitions
# for example: int b = 0; to int b; b = 0;

import json
import copy
import os

def is_pointer_type(type_specifier, var_name):
    """Check if type is a pointer type (which should be handled carefully)"""
    # check for pointer symbol in type
    if '*' in type_specifier:
        return True
    
    # Sometimes the * is w/ variable name
    if '*' in var_name:
        return True
        
    return False

def is_init_declarator(node):
    """Check if node is an init_declarator (has a variable initialization)"""
    return node["type"] == "init_declarator" and len(node.get("children", [])) >= 3

def is_inside_control_header(node, ast_node):
    """check if a declaration is inside a for/while/if condition or header (we want to skip transformations in these contexts)"""
    def is_inside_node_type(current_node, node_start, node_end, types):
        """Helper function to check if node is inside specific node types"""
        if current_node["type"] in types:
            # Check if current node contains our target node
            if (current_node["start_byte"] <= node_start and 
                current_node["end_byte"] >= node_end):
                
                # for for loops -> check if node is initialization part
                if current_node["type"] == "for_statement":
                    for child in current_node.get("children", []):
                        # skip keyword "for" and parentheses
                        if child["type"] in ["for", "(", ")", ";", "compound_statement"]:
                            continue
                        
                        # If this is the initialization and it contains our node, then our node is in control header
                        if (child["start_byte"] <= node_start and 
                            child["end_byte"] >= node_end):
                            return True
                
                # For if/while statements, check if it's in condition clause
                elif current_node["type"] in ["if_statement", "while_statement"]:
                    for child in current_node.get("children", []):
                        if child["type"] == "condition_clause":
                            if (child["start_byte"] <= node_start and 
                                child["end_byte"] >= node_end):
                                return True
                
            # Check children recursively
            for child in current_node.get("children", []):
                if is_inside_node_type(child, node_start, node_end, types):
                    return True
                    
        # If this node is not a control statement, check all children
        elif current_node.get("children"):
            for child in current_node.get("children", []):
                if is_inside_node_type(child, node_start, node_end, types):
                    return True
                
        return False
    
    # Check if inside for/if/while statements
    return is_inside_node_type(
        ast_node, 
        node["start_byte"], 
        node["end_byte"], 
        ["for_statement", "if_statement", "while_statement"]
    )

def is_eligible_declaration(node, ast_node):
    """
    Check if declaration is eligible for transformation:
    - Must be type declaration
    - Must contain at least one init_declarator
    - Must end with semicolon
    - Must not be in a control structure header/condition
    """
    if node["type"] != "declaration":
        return False
    
    # check if it's inside a control header
    if is_inside_control_header(node, ast_node):
        return False
    
    # Check if there's at least one initialization in declaration
    has_initialization = False
    for child in node.get("children", []):
        if child["type"] == "init_declarator":
            has_initialization = True
            break
    
    if not has_initialization:
        return False
    
    # Make sure it ends with a semicolon (proper statement)
    last_child = node["children"][-1] if node.get("children") else None
    if not last_child or last_child["type"] != ";":
        return False
    
    return True

def has_const_qualifier(type_specifier):
    """Check if type has a const qualifier which should not be transformed"""
    type_tokens = type_specifier.strip().split()
    return "const" in type_tokens or "constexpr" in type_tokens

def has_static_qualifier(type_specifier):
    """Check if type has a static qualifier (for function-local statics that must be initialized at declaration)"""
    type_tokens = type_specifier.strip().split()
    return "static" in type_tokens

def is_reference_type(type_specifier, var_name):
    """Check if the type is a reference type (which must be initialized at declaration)"""
    # check for reference symbol in type
    if '&' in type_specifier:
        return True
    
    # Sometimes the & is with the variable name
    if '&' in var_name and var_name.strip().startswith('&'):
        return True
        
    return False

def has_subscript_expression(node):
    """Check if a node contains subscript_expression (array operations)"""
    if node["type"] == "subscript_expression":
        return True
        
    for child in node.get("children", []):
        if has_subscript_expression(child):
            return True
            
    return False

def is_initializer_list(initializer):
    """Check if an initializer is an initializer list (uses curly braces)"""
    if not initializer:
        return False
        
    # Basic check for curly braces
    initializer = initializer.strip()
    return initializer.startswith('{') and initializer.endswith('}')

def is_constructor_call(initializer):
    """
    Check if an initializer is a constructor call (uses parentheses)
    """
    if not initializer:
        return False
        
    initializer = initializer.strip() # basic check for parentheses
    
    # We want to identify actual constructor calls but not expressions in parentheses, function calls, or casts   
    # Constructor with type name like Type(args)
    if '(' in initializer and ')' in initializer:
        before_paren = initializer[:initializer.find('(')].strip()
        
        # Skip if it looks like a cast (type) expression, which can be safely transformed
        if initializer.startswith('(') and ')' in initializer:
            cast_end = initializer.find(')', 1)
            if cast_end > 0 and cast_end < len(initializer) - 1:
                return False  # This is likely a cast, not a constructor
        
        # If there's text before the parentheses that looks like a type name (starts with uppercase letter or contains ::) and is not a known function
        known_functions = ["GCD", "gcd", "min", "max", "abs", "sin", "cos", "tan", "sqrt", "pow",
                          "log", "exp", "floor", "ceil", "round"]
        
        if (before_paren and (before_paren[0].isupper() or '::' in before_paren) 
                and not before_paren.isdigit() 
                and before_paren not in known_functions):
            return True
    
    return False

def is_template_type(type_specifier):
    """Check if the type specifier contains template syntax like vector<int>
    This excludes comparison operators in expressions"""
    # Simple check for template syntax
    if '<' in type_specifier and '>' in type_specifier:
        # Ensure it's not just comparison operators
        # For expressions like (10 ^ 5), we want to return false
        open_angle_pos = type_specifier.find('<')
        close_angle_pos = type_specifier.find('>')
        
        # Look for word characters before angle bracket
        if open_angle_pos > 0:
            char_before = type_specifier[open_angle_pos - 1]
            if char_before.isalnum() or char_before == '_':
                return True
                
        # If it's a comparison in a more complex expression, return false
        if ' < ' in type_specifier or ' > ' in type_specifier:
            return False
            
        return True
        
    return False

def is_array_type(var_decl, ast_node=None):
    """Check if a variable declaration is for an array type"""
    # Check for traditional array syntax with square brackets
    if '[' in var_decl and ']' in var_decl:
        return True
    
    # Check for array initialization with curly braces
    equals_pos = var_decl.find('=')
    if equals_pos != -1:
        initializer = var_decl[equals_pos+1:].strip()
        if initializer.startswith('{') and initializer.endswith('}'):
            return True
    
    # If we have AST node, check for subscript_expression
    if ast_node:
        # first find init_declarator that matches this var_decl
        for child in ast_node.get("children", []):
            if child["type"] == "init_declarator" and var_decl.startswith(child["text"]):
                return has_subscript_expression(child)
    
    return False

def extract_type_and_identifiers(node):
    """Extract type specifier and all identifiers (initialized and non-initialized) from a declaration node."""
    type_specifier = ""
    identifiers = []
    
    # Find type specifier (first token before any identifier or comma)
    for i, child in enumerate(node.get("children", [])):
        if i == 0 and child["type"] in ["primitive_type", "qualified_identifier", "template_type", "struct", "class", "enum"]:
            type_specifier = child["text"]
            break
    
    # If no specific type node found, try to extract from text
    if not type_specifier and node.get("children"):
        # find first identifier or init_declarator position
        first_var_pos = None
        for child in node.get("children", []):
            if child["type"] in ["identifier", "init_declarator"]:
                first_var_pos = child["start_byte"]
                break
        
        if first_var_pos:
            # extract type from beginning to first variable
            type_text = node["text"][0:first_var_pos - node["start_byte"]].strip()
            type_specifier = type_text
        else:
            # fallback to first child
            type_specifier = node["children"][0]["text"]
    
    # Extract variables from original code text
    orig_text = node["text"]
    
    # Find part after type specifier
    type_end_pos = node["start_byte"] + len(type_specifier)
    for c in orig_text[len(type_specifier):]:
        if not c.isspace():
            break
        type_end_pos += 1
    
    # find position of ending semicolon
    semicolon_pos = orig_text.rfind(';')
    declaration_text = None
    
    if semicolon_pos != -1:
        # extract declaration part (between type and semicolon)
        declaration_text = orig_text[type_end_pos - node["start_byte"]:semicolon_pos]
    
    if declaration_text:
        # Split by commas to get individual variable declarations
        var_declarations = []
        
        # handle nested parentheses, brackets, etc. when splitting by commas
        start = 0
        paren_level = 0
        bracket_level = 0
        brace_level = 0
        
        for i, char in enumerate(declaration_text):
            if char == '(':
                paren_level += 1
            elif char == ')':
                paren_level -= 1
            elif char == '[':
                bracket_level += 1
            elif char == ']':
                bracket_level -= 1
            elif char == '{':
                brace_level += 1
            elif char == '}':
                brace_level -= 1
            elif char == ',' and paren_level == 0 and bracket_level == 0 and brace_level == 0:
                var_declarations.append(declaration_text[start:i])
                start = i + 1
        
        # Add last variable declaration
        var_declarations.append(declaration_text[start:])
        
        # process each variable declaration
        for var_decl in var_declarations:
            var_decl = var_decl.strip()
            if not var_decl:
                continue
                
            # check if it has an initializer
            equals_pos = -1
            paren_level = 0
            bracket_level = 0
            
            for i, char in enumerate(var_decl):
                if char == '(':
                    paren_level += 1
                elif char == ')':
                    paren_level -= 1
                elif char == '[':
                    bracket_level += 1
                elif char == ']':
                    bracket_level -= 1
                elif char == '=' and paren_level == 0 and bracket_level == 0:
                    equals_pos = i
                    break
            
            if equals_pos != -1:
                # Has initializer
                var_name = var_decl[:equals_pos].strip()
                initializer = var_decl[equals_pos+1:].strip()
                is_array = is_array_type(var_name, node)
                is_init_list = is_initializer_list(initializer)
                is_constructor = is_constructor_call(initializer)
                identifiers.append((var_name, initializer, is_array, is_init_list, is_constructor))
            else:
                # No initializer
                is_array = is_array_type(var_decl, node)
                identifiers.append((var_decl.strip(), None, is_array, False, False))
    
    return type_specifier, identifiers

def create_replacement(type_specifier, identifiers):
    """Create replacement text for a declaration with initializations"""
    # extract all variable names for declaration part
    var_names = [ident[0] for ident in identifiers]
    declaration = f"{type_specifier} {', '.join(var_names)} ;"
    
    # Create assignment statements for initialized variables
    assignments = []
    for var_name, initializer, is_array, is_init_list, is_constructor in identifiers:
        if initializer and not is_array and not is_init_list:  # Skip assignments for arrays and initializer lists
            # For array variables, extract base name for assignment
            base_name = var_name.split('[')[0].strip()
            assignments.append(f"{base_name} = {initializer} ;")
    
    # combine declaration and assignments
    if assignments:
        return f"{declaration} {' '.join(assignments)}"
    else:
        return declaration

def should_skip_transformation(type_specifier, var_name, initializer, is_array, is_init_list, is_constructor):
    """Determine if a specific variable initialization should be skipped for transformation"""
    # Skip const variables (must be initialized at declaration)
    if has_const_qualifier(type_specifier):
        return True
        
    # Skip function-local static variables
    if has_static_qualifier(type_specifier):
        return True
        
    # Skip reference types (must be initialized at declaration)
    if is_reference_type(type_specifier, var_name):
        return True
        
    # Skip pointer types (should be handled cautiously)
    if is_pointer_type(type_specifier, var_name):
        return True
        
    # skip array types (complex to transform)
    if is_array:
        return True
        
    # skip initializer lists (complex to transform)
    if is_init_list:
        return True
        
    # skip constructor calls w/ potential side effects
    if is_constructor:
        return True
    
    # use more targeted template detection - only skip for complex template parameters
    if is_template_type(type_specifier):
        # skip only if it's a complex template (has nested templates)
        nested_template_level = type_specifier.count('<')
        if nested_template_level > 1:  # More than one level of template nesting
            return True
        # for single-level templates, check if it's a standard container
        standard_containers = ["vector", "map", "set", "unordered_map", "unordered_set"]
        if any(container in type_specifier for container in standard_containers):
            if ',' in type_specifier:  # has multiple template parameters
                return True
        
    return False

def transform_variable_definitions(ast_node):
    """transform variable definitions in AST from combined declaration with initialization to separate declaration and assignment"""
    # Deep copy to avoid modifying original
    modified_ast = copy.deepcopy(ast_node)
    
    # Find all eligible declarations
    eligible_declarations = find_eligible_declarations(modified_ast, modified_ast)
    
    # nothing to change
    if not eligible_declarations:
        return modified_ast
    
    root_text = modified_ast["text"] # get root text
    
    # process declarations in reverse order (to avoid position shifting issues)
    for decl in sorted(eligible_declarations, key=lambda x: x["start_byte"], reverse=True):
        # extract type and identifiers
        type_specifier, identifiers = extract_type_and_identifiers(decl)
        
        # check if all initializations should be skipped
        all_skipped = True
        has_init = False
        
        for var_name, initializer, is_array, is_init_list, is_constructor in identifiers:
            if initializer:
                has_init = True
                if not should_skip_transformation(type_specifier, var_name, initializer, is_array, is_init_list, is_constructor):
                    all_skipped = False
                    break
        
        # skip if no initializations were found or if all initializations should be skipped
        if not has_init or all_skipped:
            continue
        
        # get original text and its position
        start_pos = decl["start_byte"]
        end_pos = decl["end_byte"]
        
        # create replacement text
        replacement_text = create_replacement(type_specifier, identifiers)
        
        # replace in root text
        root_text = root_text[:start_pos] + replacement_text + root_text[end_pos:]
    
    # update AST root text
    modified_ast["text"] = root_text
    
    return modified_ast

def find_eligible_declarations(ast_node, root_node, results=None):
    """find all declarations that are eligible for transformation"""
    if results is None:
        results = []
    
    # check if this node is eligible declaration
    if is_eligible_declaration(ast_node, root_node):
        results.append(ast_node)
    
    # recursively search children
    for child in ast_node.get("children", []):
        find_eligible_declarations(child, root_node, results)
    
    return results

def transform_file(input_ast_path, output_ast_path):
    try:
        with open(input_ast_path, 'r', encoding='utf-8') as f:
            ast = json.load(f)
        
        modified_ast = transform_variable_definitions(ast)
        
        with open(output_ast_path, 'w', encoding='utf-8') as f:
            json.dump(modified_ast, f, indent=2)
            
    except Exception as e:
        print(f"Error transforming {input_ast_path}: {e}")
        import traceback
        print(traceback.format_exc())

def transform_directory(input_dir, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    
    for filename in os.listdir(input_dir):
        if filename.endswith('.json'):
            input_path = os.path.join(input_dir, filename)
            output_path = os.path.join(output_dir, filename)
            transform_file(input_path, output_path)

def apply_ch_define_transformation(input_dir, output_dir):
    transform_directory(input_dir, output_dir)