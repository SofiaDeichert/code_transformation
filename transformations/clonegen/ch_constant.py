# Sofia Deichert - Code Transformation Project
# ch-constant: modifying constants
# for example: 8 to (12 - 4) 

from transformations.clonegen.expression_generator import generate_equivalent_expression
import json
import copy
import os

def is_safe_to_transform(node, ast_node):
    """check if a number literal is safe to transform"""
    # skip non-integer numbers
    value = node["text"]
    
    # skip floating point, scientific notation
    if '.' in value or 'e' in value.lower():
        return False
        
    # skip hexadecimal/octal/binary literals
    if value.startswith(('0x', '0X', '0b', '0B')) or (len(value) > 1 and value.startswith('0')):
        return False
    
    # check if in preprocessor directive
    if is_in_preprocessor_directive(node, ast_node):
        return False
    
    # Check if in template parameters
    if is_in_template_parameters(node, ast_node):
        return False
    
    # Check if appears to be a bitmask (common bit patterns)
    bitmask_patterns = ['1', '2', '4', '8', '16', '32', '64', '128', '256', '512', '1024', '2048', '4096', '8192']
    if value in bitmask_patterns and could_be_bitmask_context(node, ast_node):
        return False
        
    return True

def is_in_preprocessor_directive(node, ast_node):
    # In Tree-sitter ASTs, preprocessor directives often have types like: preproc_include, preproc_define, etc.
    def check_preprocessor_recursive(current_node):
        if current_node.get("type", "").startswith("preproc_"):
            return True
            
        # If we can identify the position of the node in the source code,
        # we can check if it appears on a line that starts with #
        if "start_line" in current_node and "start_line" in node:
            if current_node["start_line"] == node["start_line"] and current_node["text"].lstrip().startswith("#"):
                return True
        
        # check children
        for child in current_node.get("children", []):
            if check_preprocessor_recursive(child):
                return True
                
        return False
    
    return check_preprocessor_recursive(ast_node)

def is_in_template_parameters(node, ast_node):
    # In Tree-sitter ASTs, template parameters are typically represented by nodes with type like template_argument_list
    def check_template_recursive(current_node, target_start, target_end):
        if current_node["type"] in ["template_argument_list", "template_parameter_list"]:
            # Check if the target node's position is within this template
            if (current_node["start_byte"] <= target_start and 
                current_node["end_byte"] >= target_end):
                return True
                
        # check all children recursively
        for child in current_node.get("children", []):
            if check_template_recursive(child, target_start, target_end):
                return True
                
        return False
    
    return check_template_recursive(ast_node, node["start_byte"], node["end_byte"])

def could_be_bitmask_context(node, ast_node):
    # look for bitwise operators (&, |, ^, ~, <<, >>) in parent expr
    def check_parent_for_bitwise(current_node, target_start, target_end, depth=0):
        if depth > 3:  # limit search depth
            return False
            
        # check if this node contains bitwise operators
        if current_node["type"] == "binary_expression":
            for child in current_node.get("children", []):
                if child["type"] in ["&", "|", "^", "<<", ">>"]:
                    # Check if our target is within this expression
                    if (current_node["start_byte"] <= target_start and 
                        current_node["end_byte"] >= target_end):
                        return True
        
        # check parent recursively
        for child in ast_node.get("children", []):
            if child != current_node and "start_byte" in child and "end_byte" in child:
                if (child["start_byte"] <= current_node["start_byte"] and 
                    child["end_byte"] >= current_node["end_byte"]):
                    return check_parent_for_bitwise(child, target_start, target_end, depth+1)
                    
        return False
    
    return check_parent_for_bitwise(node, node["start_byte"], node["end_byte"])

def transform_number_literals(ast_node):
    """recursively transform number literals in AST"""
    # Deep copy to avoid modifying original
    modified_ast = copy.deepcopy(ast_node)
    
    if modified_ast["type"] == "number_literal":
        original_value = modified_ast["text"]
        
        if is_safe_to_transform(modified_ast, ast_node):
            try:
                expression = generate_equivalent_expression(original_value)
                
                # Update node's text with new expression
                modified_ast["text"] = expression
            except Exception as e:
                # if any error occurs, keep original value
                print(f"Error transforming number {original_value}: {e}")
        
        return modified_ast
    
    # process children recursively
    if "children" in modified_ast:
        for i, child in enumerate(modified_ast["children"]):
            modified_ast["children"][i] = transform_number_literals(child)
    
    # If this is the root node (translation_unit), update its text
    if modified_ast["type"] == "translation_unit":
        # Reconstruct full text from all transformed components
        reconstruct_text(modified_ast)
    
    return modified_ast

def reconstruct_text(node):
    """recursively reconstruct the text property of a node based on its children"""
    if "children" not in node or not node["children"]:
        return
    
    # Update children first
    for child in node["children"]:
        reconstruct_text(child)
    
    # If this is a node with children, reconstruct its text
    if node["type"] == "translation_unit":
        # For root node, we need to update the entire text
        original_text = node["text"]
        
        # Start with the original text
        new_text = original_text
        
        # find all number_literal nodes and replace them in reverse order (to avoid position shifting issues)
        number_nodes = find_number_literals(node)
        for num_node in sorted(number_nodes, key=lambda x: x["start_byte"], reverse=True):
            start_pos = num_node["start_byte"] - node["start_byte"]
            end_pos = num_node["end_byte"] - node["start_byte"]
            
            # replace num with its transformed expression
            new_text = new_text[:start_pos] + num_node["text"] + new_text[end_pos:]
        
        node["text"] = new_text # update node's text

def find_number_literals(node, results=None):
    if results is None:
        results = []
    
    if node["type"] == "number_literal":
        results.append(node)
    
    # recursively search children
    for child in node.get("children", []):
        find_number_literals(child, results)
    
    return results

def transform_file(input_ast_path, output_ast_path):
    try:
        with open(input_ast_path, 'r', encoding='utf-8') as f:
            ast = json.load(f)
        
        modified_ast = transform_number_literals(ast)
        
        # save modified AST
        with open(output_ast_path, 'w', encoding='utf-8') as f:
            json.dump(modified_ast, f, indent=2)
            
    except Exception as e:
        print(f"Error transforming {input_ast_path}: {e}")
        import traceback
        print(traceback.format_exc())

def transform_directory(input_dir, output_dir):
    os.makedirs(output_dir, exist_ok=True)
    
    # process each AST file in input directory
    for filename in os.listdir(input_dir):
        if filename.endswith('.json'):
            input_path = os.path.join(input_dir, filename)
            output_path = os.path.join(output_dir, filename)
            transform_file(input_path, output_path)

def apply_ch_constant_transformation(input_dir, output_dir):
    # Set random seed for reproducibility if desired: random.seed(42)
    transform_directory(input_dir, output_dir)