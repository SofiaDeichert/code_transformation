# Sofia Deichert - Code Transformation Project
# Unary Operator Transformations

import json
import copy
import os

# transformation types
INCREMENT = "++"
DECREMENT = "--"
PLUS_ONE = "+ 1"
MINUS_ONE = "- 1"

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
        # Make sure we don't have any assignments inside the brackets
        if any(child["type"] == "assignment_expression" for child in node.get("children", [])):
            return None
        return node["text"]
    return None

def is_update_expression(node, operator):
    """Check if node is an update expression with the specified operator (++ or --)"""
    if (node["type"] == "update_expression" and 
            len(node["children"]) == 2 and
            node["children"][1]["type"] == operator and
            node["children"][1]["text"] == operator):
        
        # Check if first child is valid variable expression
        var_expr = get_variable_expression(node["children"][0])
        return var_expr is not None
    
    return False

def is_assignment_expression(node, operator):
    """Check if node is an assignment with the specified operator (+ 1 or - 1)"""
    if (node["type"] == "assignment_expression" and len(node["children"]) == 3):
        left_node = node["children"][0]
        assign_op = node["children"][1]
        right_node = node["children"][2]
        
        # Get var expression (could be 'i' or 'a[j]')
        left_expr = get_variable_expression(left_node)
        if left_expr is None:
            return False
        
        if (assign_op["type"] == "=" and 
            right_node["type"] == "binary_expression" and 
            len(right_node["children"]) == 3):
            
            right_expr = right_node["children"][0]
            right_op = right_node["children"][1]
            right_num = right_node["children"][2]
            
            # Check if it's pattern "var = var + 1" or "var = var - 1"
            op_type = ("+" if operator == PLUS_ONE else "-")
            
            # Extract right side variable expression
            right_var_expr = get_variable_expression(right_expr)
            if right_var_expr is None:
                return False
            
            return (right_op["type"] == op_type and
                    right_num["type"] == "number_literal" and
                    right_num["text"] == "1" and
                    left_expr == right_var_expr)  # Same var on both sides
    
    return False

def should_skip_node(node, ast_node):
    """
    Check if a node should be skipped for transformation.
    This includes:
    1. Nodes inside subscript expressions (array indices)
    2. Nodes that are part of a binary expression (like i++ < T)
    
    Args:
        node: The node to check
        ast_node: The root node to search from
        
    Returns:
        bool: True if the node should be skipped, False otherwise
    """
    def is_in_subscript(current_node, target_start, target_end):
        # Check if current node is subscript_argument_list
        if current_node["type"] == "subscript_argument_list":
            # Check if target node's position is within this subscript
            if (current_node["start_byte"] <= target_start and 
                current_node["end_byte"] >= target_end):
                return True
                
        # Check all children recursively
        for child in current_node.get("children", []):
            if is_in_subscript(child, target_start, target_end):
                return True
                
        return False
    
    def is_part_of_binary_expression(current_node, target_start, target_end):
        # If this is binary expression (like a < b, a + b, etc.)
        if current_node["type"] == "binary_expression":
            # Check if target node is a direct child of this binary expression
            for child in current_node.get("children", []):
                if (child["start_byte"] <= target_start and
                    child["end_byte"] >= target_end):
                    # Target is within this child of a binary expression
                    return True
        
        # Check all children recursively
        for child in current_node.get("children", []):
            if is_part_of_binary_expression(child, target_start, target_end):
                return True
                
        return False
        
    # Run both checks - should skip if either is true
    return (is_in_subscript(ast_node, node["start_byte"], node["end_byte"]) or
            is_part_of_binary_expression(ast_node, node["start_byte"], node["end_byte"]))

def find_nodes(ast_node, pattern_func, operator, results=None, parent_root=None):
    """
    function to find nodes matching a specific pattern
    
    Args:
        ast_node: The AST node to search
        pattern_func: Function that checks if a node matches the pattern
        operator: Operator to look for (++, --, + 1, - 1)
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
        # Skip nodes that should not be transformed (in subscripts or binary expressions)
        if not should_skip_node(ast_node, parent_root):
            results.append(ast_node)
    
    # Recursively search children
    for child in ast_node.get("children", []):
        find_nodes(child, pattern_func, operator, results, parent_root)
    
    return results

def transform_ast(ast_node, find_pattern_func, find_operator, replacement_func, replacement_operator):
    """
    transformation function for AST nodes
    
    Args:
        ast_node: The AST node to transform
        find_pattern_func: Function to identify the pattern (update or assignment)
        find_operator: Operator to find (++, --, + 1, - 1)
        replacement_func: Function to determine replacement pattern
        replacement_operator: Operator for replacement pattern
        
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
        
        # Get var expression - could be 'i' or 'a[j]'
        if find_pattern_func == is_update_expression:
            var_expr = get_variable_expression(expr["children"][0])
        else:  # is_assignment_expression
            var_expr = get_variable_expression(expr["children"][0])
        
        # create replacement text
        replacement_text = replacement_func(var_expr, replacement_operator)
        
        # Replace in root text
        root_text = root_text[:start_pos] + replacement_text + root_text[end_pos:]
        
    modified_ast["text"] = root_text # update root text
    
    return modified_ast

def create_assignment_replacement(var_expr, operator):
    """Create replacement text for assignment expression"""
    return f"{var_expr} = {var_expr} {operator}"

def create_update_replacement(var_expr, operator):
    """Create replacement text for update expression"""
    return f"{var_expr} {operator}"

# four main transformation functions
def transform_increment_to_assignment(ast_node):
    """Transforms var++ to var = var + 1"""
    return transform_ast(
        ast_node,
        is_update_expression,  # Pattern finder
        INCREMENT,             # Find operator
        create_assignment_replacement,  # Replacement creator
        PLUS_ONE               # Replacement operator
    )

def transform_decrement_to_assignment(ast_node):
    """Transforms var-- to var = var - 1"""
    return transform_ast(
        ast_node,
        is_update_expression,  
        DECREMENT,             
        create_assignment_replacement,  
        MINUS_ONE             
    )

def transform_assignment_to_increment(ast_node):
    """Transforms var = var + 1 to var ++"""
    return transform_ast(
        ast_node,
        is_assignment_expression, 
        PLUS_ONE,                  
        create_update_replacement, 
        INCREMENT                 
    )

def transform_assignment_to_decrement(ast_node):
    """Transforms var = var - 1 to var --"""
    return transform_ast(
        ast_node,
        is_assignment_expression,  
        MINUS_ONE,                
        create_update_replacement, 
        DECREMENT                 
    )

def transform_file(input_ast_path, output_ast_path, transformation_function):
    """
    Transforms single AST file using specified transformation function
    
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
        
        # save modified AST
        with open(output_ast_path, 'w', encoding='utf-8') as f:
            json.dump(modified_ast, f, indent=2)
            
        # print(f"Transformed {input_ast_path} -> {output_ast_path}")
        
    except Exception as e:
        print(f"Error transforming {input_ast_path}: {e}")
        # log full error traceback (debugging)
        import traceback
        print(traceback.format_exc())

def transform_directory(input_dir, output_dir, transformation_function):
    """
    Transforms all AST files in directory using specified transformation function
    
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
def apply_increment_to_assignment_transformation(input_dir, output_dir):
    """Apply var++ to var = var + 1 transformation"""
    transform_directory(input_dir, output_dir, transform_increment_to_assignment)

def apply_decrement_to_assignment_transformation(input_dir, output_dir):
    """Apply var-- to var = var - 1 transformation"""
    transform_directory(input_dir, output_dir, transform_decrement_to_assignment)

def apply_assignment_to_increment_transformation(input_dir, output_dir):
    """Apply var = var + 1 to var ++ transformation"""
    transform_directory(input_dir, output_dir, transform_assignment_to_increment)

def apply_assignment_to_decrement_transformation(input_dir, output_dir):
    """Apply var = var - 1 to var -- transformation"""
    transform_directory(input_dir, output_dir, transform_assignment_to_decrement)