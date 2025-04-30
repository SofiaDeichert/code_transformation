# Sofia Deichert - Code Transformation Project
# ch-relation: transformation of relational expressions
# for example:
# 1) a < b to b > a and vice versa
# 2) a <= b to b >= a and vice versa

import json
import copy
import os

# map of relational operators to their opposites
OPPOSITE_OPERATORS = {
    "<": ">",
    ">": "<",
    "<=": ">=",
    ">=": "<="
}

def has_side_effects(node):
    """
    Check if an expression has side effects that modify variables
    """
    # Update expressions (increment/decrement) have side effects
    if node["type"] == "update_expression":
        return True
        
    # Assignment expressions have side effects
    if node["type"] == "assignment_expression":
        return True
        
    # Function calls might have side effects
    if node["type"] == "call_expression":
        return True
    
    # Check for assignment inside array access
    if "text" in node and "=" in node["text"] and node["type"] != "binary_expression":
        return True
        
    # For binary expressions, check both operands
    if node["type"] == "binary_expression":
        # If operator is assignment (=, +=, -=, etc.), it has side effects
        op_node = node["children"][1]
        if "=" in op_node["text"]:
            return True
        
        # Check both sides recursively
        return (has_side_effects(node["children"][0]) or 
                has_side_effects(node["children"][2]))
    
    # For parenthesized expressions, check inside
    if node["type"] == "parenthesized_expression":
        for child in node.get("children", []):
            if child["type"] not in ["(", ")"]:
                return has_side_effects(child)
        return False
    
    # For subscript expressions, check all parts
    if node["type"] == "subscript_expression":
        for child in node.get("children", []):
            if child["type"] in ["[", "]"]:
                continue
                
            if child["type"] == "subscript_argument_list":
                for arg_child in child.get("children", []):
                    if arg_child["type"] in ["[", "]"]:
                        continue
                    if has_side_effects(arg_child):
                        return True
            elif has_side_effects(child):
                return True
        return False
    
    # For pointer expressions, check the operand
    if node["type"] == "pointer_expression":
        for child in node.get("children", []):
            if child["type"] not in ["*", "&"]:  # Skip pointer operators
                return has_side_effects(child)
        return False
    
    # By default, no side effects
    return False

def get_variables(node, vars_set=None):
    """
    Get all variables (identifiers) used in an expression
    """
    if vars_set is None:
        vars_set = set()
    
    # Base case: identifier is a variable
    if node["type"] == "identifier":
        vars_set.add(node["text"])
        return vars_set
    
    # For pointer expressions, get variables from operand
    if node["type"] == "pointer_expression":
        for child in node.get("children", []):
            if child["type"] not in ["*", "&"]:  
                get_variables(child, vars_set)
        return vars_set
    
    # recursively check children
    for child in node.get("children", []):
        get_variables(child, vars_set)
    
    return vars_set

def is_safe_expression(node):
    """
    Check if an expression is safe to transform
    """
    # Base cases: identifiers and literals are safe
    if node["type"] in ["identifier", "number_literal"]:
        return True
        
    # Parenthesized expressions are safe if their content is safe
    if node["type"] == "parenthesized_expression":
        # Find actual expression inside parentheses
        for child in node.get("children", []):
            if child["type"] not in ["(", ")"]:  # Skip brackets
                # Recursively check if inner expression is safe
                return is_safe_expression(child)
        # Empty parentheses or only brackets found (shouldn't happen in valid code)
        return True
        
    # Basic arithmetic operations are safe if operands are safe
    if node["type"] == "binary_expression":
        # Allow only arithmetic operators
        op_node = node["children"][1]
        if op_node["type"] in ["+", "-", "*", "/", "%"] and op_node["text"] in ["+", "-", "*", "/", "%"]:
            # Both operands must be safe
            return (is_safe_expression(node["children"][0]) and 
                    is_safe_expression(node["children"][2]))
        return False
        
    # Subscript expressions are safe if the base and all indices are safe
    if node["type"] == "subscript_expression":
        # check all children
        for child in node.get("children", []):
            # skip brackets
            if child["type"] in ["[", "]"]:
                continue
                
            # For argument lists, check each argument
            if child["type"] == "subscript_argument_list":
                for arg_child in child.get("children", []):
                    # Skip brackets
                    if arg_child["type"] in ["[", "]"]:
                        continue
                    
                    # Check if argument is safe
                    if not is_safe_expression(arg_child):
                        return False
            # Check if base expression is safe
            elif not is_safe_expression(child):
                return False
        return True
    
    # Pointer expressions are safe if their operand is safe
    if node["type"] == "pointer_expression":
        # Check operand (the expression being pointed to or referenced)
        for child in node.get("children", []):
            if child["type"] not in ["*", "&"]:  # skip pointer operators
                return is_safe_expression(child)
        return True
    
    # Expressions w/ side effects require careful analysis but are not automatically unsafe for our purposes
    if node["type"] in ["update_expression", "assignment_expression"]:
        # These are handled differently in is_transformable_relational_expression
        # For individual safety, they're considered safe to appear on one side
        return True
    
    # Function calls are not safe
    if node["type"] == "call_expression":
        return False
    
    # Check for assignment expressions inside array access
    if "text" in node and "=" in node["text"] and node["type"] != "binary_expression":
        return False
        
    # By default, reject anything we don't explicitly recognize as safe
    return False

def is_transformable_relational_expression(node):
    """
    Check if node is relational expression that can be safely transformed
    Must be type "binary_expression" with a relational operator (<, >, <=, >=)
    and safe operands on both sides or a safe side-effect situation
    """
    if (node["type"] == "binary_expression" and 
            len(node["children"]) == 3):
        left_node = node["children"][0]
        op_node = node["children"][1]
        right_node = node["children"][2]
        
        # check if operator is a relational operator
        if op_node["type"] in OPPOSITE_OPERATORS and op_node["text"] in OPPOSITE_OPERATORS:
            # Case 1: Both sides have no side effects - always safe to transform
            if not has_side_effects(left_node) and not has_side_effects(right_node):
                return is_safe_expression(left_node) and is_safe_expression(right_node)
            
            # Case 2: Left side has side effects, right does not
            if has_side_effects(left_node) and not has_side_effects(right_node):
                # Get all variables used on both sides
                left_vars = get_variables(left_node)
                right_vars = get_variables(right_node)
                
                # If there are no shared variables, it's safe to transform
                # This handles cases like: a++ < 5 (safe to transform to: 5 > a++)
                if not left_vars.intersection(right_vars):
                    return True
                return False
            
            # Case 3: Right side has side effects, left does not
            if has_side_effects(right_node) and not has_side_effects(left_node):
                # Get all variables used on both sides
                left_vars = get_variables(left_node)
                right_vars = get_variables(right_node)
                
                # If there are no shared variables, it's safe to transform
                # This handles cases like: 5 < a++ (safe to transform to: a++ > 5)
                if not left_vars.intersection(right_vars):
                    return True
                return False
            
            # Case 4: Both sides have side effects - not safe to transform
            return False
    
    return False

def find_relational_expressions(ast_node, results=None):
    """
    Recursively find all transformable relational expressions in AST
    """
    if results is None:
        results = []
    
    # Check if this node is transformable relational expression
    if is_transformable_relational_expression(ast_node):
        results.append(ast_node)
    
    # Special handling for parenthesized expressions
    if ast_node["type"] == "parenthesized_expression":
        for child in ast_node.get("children", []):
            if child["type"] not in ["(", ")"] and is_transformable_relational_expression(child):
                # Found a relational expression inside parentheses
                child_copy = copy.deepcopy(child)
                child_copy["inside_parentheses"] = True
                child_copy["parent_start"] = ast_node["start_byte"]
                child_copy["parent_end"] = ast_node["end_byte"]
                results.append(child_copy)
    
    # recursively search children
    for child in ast_node.get("children", []):
        find_relational_expressions(child, results)
    
    return results

def create_reversed_expression(node):
    """
    Create reversed relational expression (a < b to b > a)
    """
    left_node = node["children"][0]
    op_node = node["children"][1]
    right_node = node["children"][2]
    
    # get text of operands and operator
    left_expr = left_node["text"]
    op = op_node["text"]
    right_expr = right_node["text"]
    
    # get opposite operator
    opposite_op = OPPOSITE_OPERATORS[op]
    
    # create reversed expression (swap operands and use opposite operator)
    return f"{right_expr} {opposite_op} {left_expr}"

def transform_relational_expressions(ast_node):
    """
    Transform all relational expressions in AST
    Swaps operands and changes operators to their opposites
    """
    # Deep copy to avoid modifying original
    modified_ast = copy.deepcopy(ast_node)
    
    # Find all relational expressions to transform
    expressions = find_relational_expressions(modified_ast)
    
    # nothing to change
    if not expressions:
        return modified_ast
    
    # get root text for direct modification
    root_text = modified_ast["text"]
    
    # process transformations in reverse order (to avoid position shifting issues)
    for expr in sorted(expressions, key=lambda x: x["start_byte"], reverse=True):
        # get original expression and its position
        start_pos = expr["start_byte"]
        end_pos = expr["end_byte"]
        
        # create reversed expression
        reversed_expr = create_reversed_expression(expr)
        
        # replace in root text
        root_text = root_text[:start_pos] + reversed_expr + root_text[end_pos:]
    
    # update root text with all transformations applied
    modified_ast["text"] = root_text
    
    return modified_ast

def transform_file(input_ast_path, output_ast_path):
    try:
        # Load AST from file
        with open(input_ast_path, 'r', encoding='utf-8') as f:
            ast = json.load(f)
        
        # Apply transformation
        modified_ast = transform_relational_expressions(ast)
        
        # Save modified AST
        with open(output_ast_path, 'w', encoding='utf-8') as f:
            json.dump(modified_ast, f, indent=2)
            
    except Exception as e:
        print(f"Error transforming {input_ast_path}: {e}")
        import traceback
        print(traceback.format_exc())

def transform_directory(input_dir, output_dir):
    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)
    
    # Process each AST file in input directory
    for filename in os.listdir(input_dir):
        if filename.endswith('.json'):
            input_path = os.path.join(input_dir, filename)
            output_path = os.path.join(output_dir, filename)
            transform_file(input_path, output_path)

def apply_relational_transformation(input_dir, output_dir):
    transform_directory(input_dir, output_dir)