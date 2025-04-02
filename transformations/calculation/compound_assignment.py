# Sofia Deichert - Code Transformation Project
# Compound Assignment transformations

# (3) i += j ↔ i = i + j
# (4) i -= j ↔ i = i - j
# (5) i *= j ↔ i = i * j
# (6) i /= j ↔ i = i / j
# (7) i %= j ↔ i = i % j
# (8) i <<= j ↔ i = i << j
# (9) i >>= j ↔ i = i >> j
# (10) i &= j ↔ i = i & j
# (11) i |= j ↔ i = i | j
# (12) i ^= j ↔ i = i ^ j

import json
import copy
import os
import re

COMPOUND_TO_BINARY = {
    "+=": "+",
    "-=": "-",
    "*=": "*",
    "/=": "/",
    "%=": "%",
    "<<=": "<<",
    ">>=": ">>",
    "&=": "&",
    "|=": "|",
    "^=": "^"
}

# Dictionary mapping binary operators --> their compound assignment form
BINARY_TO_COMPOUND = {v: k for k, v in COMPOUND_TO_BINARY.items()}

# reference - all compound operators 
ALL_COMPOUND_OPS = list(COMPOUND_TO_BINARY.keys())

def get_variable_expression(node):
    """
    Extract variable expression text (could be 'i' or 'a[j]' etc.)
    Returns None if not a valid target for transformation
    """
    if node["type"] == "identifier":
        # Simple var like 'i'
        return node["text"]
    elif node["type"] == "subscript_expression":
        # Array access like 'a[j]'
        # Make sure we don't have any assignments inside brackets
        if any(child["type"] == "assignment_expression" for child in node.get("children", [])):
            return None
        return node["text"]
    # Other more complex expressions that could be on left side of an assignment
    elif node["type"] in ["field_expression", "pointer_expression"]:
        # E.g. obj.field, ptr->field
        return node["text"]
    return None

def contains_multiple_compound_assignments(node):
    """
    Check if statement contains multiple compound assignments
    Recursively checks the node and its descendants
    
    Args:
        node: The AST node to check
        
    Returns:
        bool: True if statement contains multiple compound assignments
    """
    # Track # of compound assignments found
    count = 0
    
    # For expression statements, check if they contain multiple compound assignments
    if node["type"] == "expression_statement":
        # Get expression within the statement
        for child in node.get("children", []):
            if child["type"] not in [";", "}"]:  # skip terminators
                count = count_compound_assignments(child)
                break
    else:
        # For other statement types, check all children
        count = count_compound_assignments(node)
    
    return count > 1

def count_compound_assignments(node):
    """
    Count number of compound assignments in a node and its descendants.
    
    Args:
        node: AST node to check
        
    Returns:
        int: num of compound assignments found
    """
    count = 0
    
    # Check if this node is compound assignment
    if node["type"] == "assignment_expression" and len(node["children"]) > 1:
        op_node = node["children"][1]
        if op_node["type"] in ALL_COMPOUND_OPS:
            count += 1
    
    # Recursively check children
    for child in node.get("children", []):
        count += count_compound_assignments(child)
    
    return count

def find_parent_statement(ast_node, target_node, parent=None):
    """
    Find parent statement of a given node in AST
    
    Args:
        ast_node: root AST node to search from
        target_node: node to find the parent statement for
        parent: current parent node (used for recursion)
        
    Returns:
        parent statement node, or None if not found
    """
    # Check if this is target node
    if ast_node == target_node:
        return parent
    
    # Check if this is statement node (potential parent)
    is_statement = ast_node["type"] in [
        "expression_statement", 
        "if_statement", 
        "for_statement", 
        "while_statement",
        "do_statement",
        "compound_statement",
        "declaration"
    ]
    
    current_parent = ast_node if is_statement else parent
    
    # Recursively search children
    for child in ast_node.get("children", []):
        found = find_parent_statement(child, target_node, current_parent)
        if found:
            return found
    
    return None

def is_compound_assignment(node, operator):
    """
    Check if node is a compound assignment expression with specified operator (+=, -=, etc.)
    
    Args:
        node: AST node to check
        operator: compound assignment operator to look for (e.g., "+=")
        
    Returns:
        bool: True if node is a compound assignment with specified operator
    """
    if (node["type"] == "assignment_expression" and 
            len(node["children"]) == 3 and
            node["children"][1]["type"] == operator and
            node["children"][1]["text"] == operator):
        
        # Check if first child is valid variable expression
        var_expr = get_variable_expression(node["children"][0])
        return var_expr is not None
    
    return False

def is_expanded_assignment(node, operator):
    """
    Check if node is an expanded assignment (i = i + j) with specified binary operator
    
    Args:
        node: AST node to check
        operator: binary operator (e.g., "+", "-")
        
    Returns:
        bool: True if node matches the i = i + j pattern w/ specified operator
    """
    if (node["type"] == "assignment_expression" and len(node["children"]) == 3):
        left_node = node["children"][0]
        assign_op = node["children"][1]
        right_node = node["children"][2]
        
        # Get left side variable expression (could be 'i' or 'a[j]')
        left_expr = get_variable_expression(left_node)
        if left_expr is None:
            return False
        
        # Check for simple assignment (=)
        if assign_op["type"] != "=":
            return False
            
        # Check if right side is a binary expression
        if right_node["type"] == "binary_expression" and len(right_node["children"]) == 3:
            # Check pattern: left_expr = left_expr OP something
            right_left = right_node["children"][0]
            right_op = right_node["children"][1]
            
            # Extract right side first operand
            right_left_expr = get_variable_expression(right_left)
            if right_left_expr is None:
                return False
            
            # Check if operator matches and left side appears as first operand on right side
            # Make sure the variable expressions are exactly identical
            if (right_op["type"] == operator and 
                right_op["text"] == operator and
                left_expr == right_left_expr):
                
                # Check if right side of binary expression is a proper self-contained expression
                # If it contains references or operations dependent on outside scope,
                # it's not safe to transform
                right_operand = right_node["children"][2]
                right_operand_text = right_operand["text"]
                
                # Skip transformation if it's not a simple, transformable expression
                if is_non_transformable_expression(right_node):
                    return False
                
                return True
    
    return False

def is_non_transformable_expression(node):
    """
    Check if a binary expression is non-transformable to compound assignment.
    
    e.g., expressions like:
    - i = i % 3 + 5  (multiple operations on right side that involve i)
    - i = i % 3 * 2  (multiple operations on right side that involve i)
    
    Args:
        node: binary expression node
        
    Returns:
        bool: True if it should not be transformed, False if it's safe to transform
    """
    # We're looking at a binary expression on the right side of "="
    if node["type"] == "binary_expression":
        text = node["text"] # Get text of complete expression
        
        # Get variable name (left side of assignment)
        # It's first grandchild of assignment expression
        left_node = node["children"][0]
        var_name = get_variable_expression(left_node)
        if not var_name:
            return False
        
        # Check if there are multiple operations involving variable
        # For example: i = i % 3 + 5 or i = i % 3 * 2
        operator = node["children"][1]["text"]
        right_text = node["children"][2]["text"]
        
        # Remove any parentheses for pattern analysis
        pattern_text = text.replace('(', '').replace(')', '')
        
        # Check for patterns like "i op1 expr1 op2 expr2" where op1 != op2
        # This would indicate a complex expression that can't be safely transformed to a compound assignment
        
        # Count occurrences of var in the expression
        var_count = pattern_text.count(var_name)
        
        # If the var appears more than once, it might be a complex expression
        if var_count > 1:
            # Check if there are additional operations after binary operation
            pattern = re.compile(r'[+\-*/%&|^<>]')
            ops = pattern.findall(pattern_text)
            
            # If there's more than one operator, it's likely a non-transformable expression
            if len(ops) > 1:
                return True
    
    return False

def should_skip_node(node, ast_node):
    """
    Check if a node should be skipped for transformation.
    Skips nodes that are part of statements with multiple compound assignments.
    
    Args:
        node: The node to check
        ast_node: The root node to search from
        
    Returns:
        bool: True if the node should be skipped, False otherwise
    """
    # Find the parent statement of this node
    parent_statement = find_parent_statement(ast_node, node)
    
    # Skip if parent statement contains multiple compound assignments
    if parent_statement and contains_multiple_compound_assignments(parent_statement):
        return True
    
    return False

def find_nodes(ast_node, pattern_func, operator, results=None, parent_root=None):
    """
    find nodes matching a specific pattern
    
    Args:
        ast_node: The AST node to search
        pattern_func: Function that checks if a node matches the pattern
        operator: Operator to look for
        results: List to collect results (internal use)
        parent_root: The root AST node for context checks (internal use)
        
    Returns:
        List of nodes matching pattern
    """
    if results is None:
        results = []
    
    if parent_root is None:
        parent_root = ast_node
    
    # Check if this node matches pattern
    if pattern_func(ast_node, operator):
        # Check if node should be skipped
        if not should_skip_node(ast_node, parent_root):
            results.append(ast_node)
    
    # Recursively search children
    for child in ast_node.get("children", []):
        find_nodes(child, pattern_func, operator, results, parent_root)
    
    return results

def transform_ast(ast_node, find_pattern_func, find_operator, replacement_func):
    """
    transform AST nodes matching a pattern
    
    Args:
        ast_node: AST node to transform
        find_pattern_func: Function to identify pattern
        find_operator: Operator to find
        replacement_func: Function to determine replacement pattern
        
    Returns:
        Transformed AST
    """
    # Deep copy to avoid modifying original
    modified_ast = copy.deepcopy(ast_node)
    
    # Find all expressions to transform
    expressions = find_nodes(modified_ast, find_pattern_func, find_operator)
    
    # Nothing to change
    if not expressions:
        return modified_ast
    
    root_text = modified_ast["text"] # get root text
    
    # Process transformations in reverse order (to avoid position shifting issues)
    for expr in sorted(expressions, key=lambda x: x["start_byte"], reverse=True):
        # Get original text and its position
        start_pos = expr["start_byte"]
        end_pos = expr["end_byte"]
        
        # Create replacement text
        replacement_text = replacement_func(expr, find_operator)
        
        # Replace in root text
        root_text = root_text[:start_pos] + replacement_text + root_text[end_pos:]
        
    modified_ast["text"] = root_text # update root text
    
    return modified_ast

def create_expanded_assignment(node, compound_op):
    """
    Create an expanded assignment (i = i + j) from a compound assignment (i += j)
    
    Args:
        node: The compound assignment node
        compound_op: The compound operator (e.g., "+=")
        
    Returns:
        str: The expanded assignment text
    """
    left_node = node["children"][0]
    right_node = node["children"][2]
    
    var_expr = left_node["text"]
    value_expr = right_node["text"]
    binary_op = COMPOUND_TO_BINARY[compound_op]
    
    # Add parentheses around right operand if it's a complex expression to preserve operator precedence
    needs_parentheses = right_node["type"] in [
        "binary_expression", 
        "conditional_expression", 
        "logical_expression"
    ]
    
    # Also check if right expression starts with an operator that needs parentheses
    if not needs_parentheses and value_expr and value_expr[0] in "+-":
        needs_parentheses = True
    
    if needs_parentheses:
        value_expr = f"({value_expr})"
    
    return f"{var_expr} = {var_expr} {binary_op} {value_expr}"

def create_compound_assignment(node, binary_op):
    """
    Create compound assignment (i += j) from an expanded assignment (i = i + j)
    
    Args:
        node: expanded assignment node
        binary_op: binary operator (e.g., "+")
        
    Returns:
        str: compound assignment text
    """
    left_node = node["children"][0]
    right_node = node["children"][2]  # This is binary expression
    
    var_expr = left_node["text"]
    right_operand_node = right_node["children"][2]  # Second operand of binary expression
    value_expr = right_operand_node["text"]
    compound_op = BINARY_TO_COMPOUND[binary_op]
    
    # Simplified approach for handling parentheses
    # Since compound assignment operators have very low precedence, we can safely remove the outermost parentheses that enclose entire right operand
    if value_expr.startswith("(") and value_expr.endswith(")"):
        # Simple check to make sure we only remove outermost parentheses and only if they enclose entire expression
        inner_expr = value_expr[1:-1].strip()
        
        # Make sure parentheses are balanced within inner expression
        if inner_expr.count("(") == inner_expr.count(")"):
            value_expr = inner_expr
    
    return f"{var_expr} {compound_op} {value_expr}"

# Generic transformation functions for compound assignment
def transform_compound_to_expanded(ast_node, compound_op):
    """Transform compound assignment to expanded form (i += j to i = i + j)"""
    return transform_ast(
        ast_node,
        is_compound_assignment,
        compound_op,
        create_expanded_assignment
    )

def transform_expanded_to_compound(ast_node, binary_op):
    """Transform expanded form to compound assignment (i = i + j to i += j)"""
    return transform_ast(
        ast_node,
        is_expanded_assignment,
        binary_op,
        create_compound_assignment
    )

# Specific transformation functions for each operator
def transform_plus_equal_to_expanded(ast_node):
    """Transform i += j to i = i + j"""
    return transform_compound_to_expanded(ast_node, "+=")

def transform_expanded_to_plus_equal(ast_node):
    """Transform i = i + j to i += j"""
    return transform_expanded_to_compound(ast_node, "+")

def transform_minus_equal_to_expanded(ast_node):
    """Transform i -= j to i = i - j"""
    return transform_compound_to_expanded(ast_node, "-=")

def transform_expanded_to_minus_equal(ast_node):
    """Transform i = i - j to i -= j"""
    return transform_expanded_to_compound(ast_node, "-")

def transform_multiply_equal_to_expanded(ast_node):
    """Transform i *= j to i = i * j"""
    return transform_compound_to_expanded(ast_node, "*=")

def transform_expanded_to_multiply_equal(ast_node):
    """Transform i = i * j to i *= j"""
    return transform_expanded_to_compound(ast_node, "*")

def transform_divide_equal_to_expanded(ast_node):
    """Transform i /= j to i = i / j"""
    return transform_compound_to_expanded(ast_node, "/=")

def transform_expanded_to_divide_equal(ast_node):
    """Transform i = i / j to i /= j"""
    return transform_expanded_to_compound(ast_node, "/")

def transform_modulo_equal_to_expanded(ast_node):
    """Transform i %= j to i = i % j"""
    return transform_compound_to_expanded(ast_node, "%=")

def transform_expanded_to_modulo_equal(ast_node):
    """Transform i = i % j to i %= j"""
    return transform_expanded_to_compound(ast_node, "%")

def transform_left_shift_equal_to_expanded(ast_node):
    """Transform i <<= j to i = i << j"""
    return transform_compound_to_expanded(ast_node, "<<=")

def transform_expanded_to_left_shift_equal(ast_node):
    """Transform i = i << j to i <<= j"""
    return transform_expanded_to_compound(ast_node, "<<")

def transform_right_shift_equal_to_expanded(ast_node):
    """Transform i >>= j to i = i >> j"""
    return transform_compound_to_expanded(ast_node, ">>=")

def transform_expanded_to_right_shift_equal(ast_node):
    """Transform i = i >> j to i >>= j"""
    return transform_expanded_to_compound(ast_node, ">>")

def transform_bitand_equal_to_expanded(ast_node):
    """Transform i &= j to i = i & j"""
    return transform_compound_to_expanded(ast_node, "&=")

def transform_expanded_to_bitand_equal(ast_node):
    """Transform i = i & j to i &= j"""
    return transform_expanded_to_compound(ast_node, "&")

def transform_bitor_equal_to_expanded(ast_node):
    """Transform i |= j to i = i | j"""
    return transform_compound_to_expanded(ast_node, "|=")

def transform_expanded_to_bitor_equal(ast_node):
    """Transform i = i | j to i |= j"""
    return transform_expanded_to_compound(ast_node, "|")

def transform_bitxor_equal_to_expanded(ast_node):
    """Transform i ^= j to i = i ^ j"""
    return transform_compound_to_expanded(ast_node, "^=")

def transform_expanded_to_bitxor_equal(ast_node):
    """Transform i = i ^ j to i ^= j"""
    return transform_expanded_to_compound(ast_node, "^")

def transform_file(input_ast_path, output_ast_path, transformation_function):
    """
    transform single AST file using specified transformation function
    
    Args:
        input_ast_path: Path to input AST file
        output_ast_path: Path to save transformed AST
        transformation_function: Function to apply to AST
    """
    try:
        # Load AST from file
        with open(input_ast_path, 'r', encoding='utf-8') as f:
            ast = json.load(f)
        
        modified_ast = transformation_function(ast) # apply transformation
        
        # Save modified AST
        with open(output_ast_path, 'w', encoding='utf-8') as f:
            json.dump(modified_ast, f, indent=2)
            
        # print(f"Transformed {input_ast_path} -> {output_ast_path}")
        
    except Exception as e:
        print(f"Error transforming {input_ast_path}: {e}")
        # Log full error traceback for debugging
        import traceback
        print(traceback.format_exc())

def transform_directory(input_dir, output_dir, transformation_function):
    """
    Transform all AST files in a directory using specified transformation function
    
    Args:
        input_dir: Directory containing input AST files
        output_dir: Directory to save transformed AST files
        transformation_function: Function to apply to ASTs
    """
    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)
    
    # Process each AST file in input directory
    for filename in os.listdir(input_dir):
        if filename.endswith('.json'):
            input_path = os.path.join(input_dir, filename)
            output_path = os.path.join(output_dir, filename)
            transform_file(input_path, output_path, transformation_function)

# Functions to be called from transform_ast.py
# Compound to expanded form transformations
def apply_plus_equal_to_expanded_transformation(input_dir, output_dir):
    """Apply i += j to i = i + j transformation"""
    transform_directory(input_dir, output_dir, transform_plus_equal_to_expanded)

def apply_minus_equal_to_expanded_transformation(input_dir, output_dir):
    """Apply i -= j to i = i - j transformation"""
    transform_directory(input_dir, output_dir, transform_minus_equal_to_expanded)

def apply_multiply_equal_to_expanded_transformation(input_dir, output_dir):
    """Apply i *= j to i = i * j transformation"""
    transform_directory(input_dir, output_dir, transform_multiply_equal_to_expanded)

def apply_divide_equal_to_expanded_transformation(input_dir, output_dir):
    """Apply i /= j to i = i / j transformation"""
    transform_directory(input_dir, output_dir, transform_divide_equal_to_expanded)

def apply_modulo_equal_to_expanded_transformation(input_dir, output_dir):
    """Apply i %= j to i = i % j transformation"""
    transform_directory(input_dir, output_dir, transform_modulo_equal_to_expanded)

def apply_left_shift_equal_to_expanded_transformation(input_dir, output_dir):
    """Apply i <<= j to i = i << j transformation"""
    transform_directory(input_dir, output_dir, transform_left_shift_equal_to_expanded)

def apply_right_shift_equal_to_expanded_transformation(input_dir, output_dir):
    """Apply i >>= j to i = i >> j transformation"""
    transform_directory(input_dir, output_dir, transform_right_shift_equal_to_expanded)

def apply_bitand_equal_to_expanded_transformation(input_dir, output_dir):
    """Apply i &= j to i = i & j transformation"""
    transform_directory(input_dir, output_dir, transform_bitand_equal_to_expanded)

def apply_bitor_equal_to_expanded_transformation(input_dir, output_dir):
    """Apply i |= j to i = i | j transformation"""
    transform_directory(input_dir, output_dir, transform_bitor_equal_to_expanded)

def apply_bitxor_equal_to_expanded_transformation(input_dir, output_dir):
    """Apply i ^= j to i = i ^ j transformation"""
    transform_directory(input_dir, output_dir, transform_bitxor_equal_to_expanded)

# Expanded form to compound transformations
def apply_expanded_to_plus_equal_transformation(input_dir, output_dir):
    """Apply i = i + j to i += j transformation"""
    transform_directory(input_dir, output_dir, transform_expanded_to_plus_equal)

def apply_expanded_to_minus_equal_transformation(input_dir, output_dir):
    """Apply i = i - j to i -= j transformation"""
    transform_directory(input_dir, output_dir, transform_expanded_to_minus_equal)

def apply_expanded_to_multiply_equal_transformation(input_dir, output_dir):
    """Apply i = i * j to i *= j transformation"""
    transform_directory(input_dir, output_dir, transform_expanded_to_multiply_equal)

def apply_expanded_to_divide_equal_transformation(input_dir, output_dir):
    """Apply i = i / j to i /= j transformation"""
    transform_directory(input_dir, output_dir, transform_expanded_to_divide_equal)

def apply_expanded_to_modulo_equal_transformation(input_dir, output_dir):
    """Apply i = i % j to i %= j transformation"""
    transform_directory(input_dir, output_dir, transform_expanded_to_modulo_equal)

def apply_expanded_to_left_shift_equal_transformation(input_dir, output_dir):
    """Apply i = i << j to i <<= j transformation"""
    transform_directory(input_dir, output_dir, transform_expanded_to_left_shift_equal)

def apply_expanded_to_right_shift_equal_transformation(input_dir, output_dir):
    """Apply i = i >> j to i >>= j transformation"""
    transform_directory(input_dir, output_dir, transform_expanded_to_right_shift_equal)

def apply_expanded_to_bitand_equal_transformation(input_dir, output_dir):
    """Apply i = i & j to i &= j transformation"""
    transform_directory(input_dir, output_dir, transform_expanded_to_bitand_equal)

def apply_expanded_to_bitor_equal_transformation(input_dir, output_dir):
    """Apply i = i | j to i |= j transformation"""
    transform_directory(input_dir, output_dir, transform_expanded_to_bitor_equal)

def apply_expanded_to_bitxor_equal_transformation(input_dir, output_dir):
    """Apply i = i ^ j to i ^= j transformation"""
    transform_directory(input_dir, output_dir, transform_expanded_to_bitxor_equal)