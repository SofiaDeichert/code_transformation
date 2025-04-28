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

def is_simple_operand(node):
    """
    Check if node is simple operand that's safe to swap in relational expression
    Valid simple operands: identifier, number_literal, subscript_expression
    """
    return node["type"] in ["identifier", "number_literal", "subscript_expression"]

def is_transformable_relational_expression(node):
    """
    Check if node is relational expression that can be safely transformed
    Must be type "binary_expression" with a relational operator (<, >, <=, >=) and simple operands on both sides
    """
    if (node["type"] == "binary_expression" and 
            len(node["children"]) == 3):
        left_node = node["children"][0]
        op_node = node["children"][1]
        right_node = node["children"][2]
        
        # check if operator is a relational operator
        if op_node["type"] in OPPOSITE_OPERATORS and op_node["text"] in OPPOSITE_OPERATORS:
            # Check if both left and right operands are simple (safe to swap)
            return is_simple_operand(left_node) and is_simple_operand(right_node)
    
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
    
    # recursively search children
    for child in ast_node.get("children", []):
        find_relational_expressions(child, results)
    
    return results

def create_reversed_expression(node):
    """
    create reversed relational expression (a < b to b > a)
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
    Transform all relational expressions in the AST
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