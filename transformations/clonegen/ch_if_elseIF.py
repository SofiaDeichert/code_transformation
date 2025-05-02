# Sofia Deichert - Code Transformation Project
# ch_if_elseIF: transformation of if-elseif to if-else
# For example,

# if(grad<60) BodyA
# else if(grad<80) BodyB
# else BodyC

# to:

# if(grad<60) BodyA
# else { if(grad<80) BodyB
# else BodyC }


import json
import copy
import os

def transform_if_elseif(ast_node):
    """
    Transform if-elseif chains into if-else with nested if:
    1. Find all if statements with else_clause containing if_statement
    2. Transform them by adding braces around nested if
    """
    modified_ast = copy.deepcopy(ast_node)
    
    # Find all if_statement nodes with else_if in AST
    if_elseif_nodes = find_if_elseif_statements(modified_ast)
    
    # nothing to change
    if not if_elseif_nodes:
        return modified_ast
    
    # Process transformations in reverse order (to avoid position shifting issues)
    # Sort by start position so deeper nested structures get transformed first
    for if_node in sorted(if_elseif_nodes, key=lambda x: x["start_byte"], reverse=True):
        transform_single_if_elseif(modified_ast, if_node)
    
    return modified_ast

def find_if_elseif_statements(ast_node, results=None):
    """Recursively find all if_statement nodes with else_clause containing if_statement"""
    if results is None:
        results = []
    
    # Check if current node is if_statement with else_if
    if ast_node["type"] == "if_statement":
        # Look for else_clause that contains an if_statement
        for child in ast_node.get("children", []):
            if child["type"] == "else_clause":
                # now look for if_statement inside the else_clause
                for else_child in child.get("children", []):
                    if else_child["type"] == "if_statement":
                        # This is an else-if pattern
                        results.append(ast_node)
                        break
    
    # recursively search children
    for child in ast_node.get("children", []):
        find_if_elseif_statements(child, results)
    
    return results

def find_else_if_statement(if_node):
    """Find the else_clause child and the if_statement within it"""
    else_clause = None
    nested_if = None
    
    # Find else_clause in children
    for child in if_node.get("children", []):
        if child["type"] == "else_clause":
            else_clause = child
            break
    
    # If we found else_clause, find if_statement within it
    if else_clause:
        for child in else_clause.get("children", []):
            if child["type"] == "if_statement":
                nested_if = child
                break
    
    return else_clause, nested_if

def transform_single_if_elseif(ast_root, if_node):
    """Transform a single if-elseif structure by adding braces around the nested if"""
    # Find the else_clause and the if_statement within it
    else_clause, nested_if = find_else_if_statement(if_node)
    
    if not else_clause or not nested_if:
        return  # Not an if-elseif pattern
    
    # Extract "else" keyword
    else_keyword = ""
    for child in else_clause.get("children", []):
        if child["type"] == "else":
            else_keyword = child["text"]
            break
    
    # get nested if statement text
    nested_if_text = nested_if["text"]
    
    # Create new else_clause text w/ braces
    new_else_clause_text = else_keyword + " { " + nested_if_text + " }"
    
    # Replace in root text
    replace_text_in_ast(ast_root, else_clause["start_byte"], else_clause["end_byte"], new_else_clause_text)

def replace_text_in_ast(node, start_pos, end_pos, replacement):
    """Replace a substring of text in AST, starting at deepest node and propagating changes upward"""
    # Check if this node contains replacement range
    node_start = node.get("start_byte")
    node_end = node.get("end_byte")
    
    if node_start is None or node_end is None:
        return False
    
    # If replacement is fully contained in this node
    if node_start <= start_pos and node_end >= end_pos:
        # Check if any child contains replacement
        child_replaced = False
        for child in node.get("children", []):
            if replace_text_in_ast(child, start_pos, end_pos, replacement):
                child_replaced = True
                break
        
        # If no child contained replacement or this node has no children, apply replacement to this node's text
        if not child_replaced or not node.get("children"):
            if node_start == start_pos and node_end == end_pos:
                # direct replacement of node's text
                node["text"] = replacement
                return True
            else:
                # replace portion of node's text
                prefix = node["text"][:start_pos - node_start]
                suffix = node["text"][end_pos - node_start:]
                node["text"] = prefix + replacement + suffix
                return True
        
        # Update this node's text based on its children's text
        if child_replaced and node.get("children"):
            # Reconstruct this node's text from its children
            # Preserve original whitespace as much as possible
            current_pos = node_start
            node_text = ""
            
            for child in node.get("children", []):
                child_start = child.get("start_byte", current_pos)
                # Add any whitespace between the previous child and this one
                if child_start > current_pos:
                    # try to preserve original spacing in the parent node
                    original_spacing = node["text"][current_pos - node_start:child_start - node_start]
                    node_text += original_spacing
                
                # add this child's text
                node_text += child.get("text", "")
                current_pos = child.get("end_byte", child_start + len(child.get("text", "")))
            
            # add any trailing text
            if node_end > current_pos:
                node_text += node["text"][current_pos - node_start:node_end - node_start]
            
            node["text"] = node_text
            return True
    
    return False

def transform_file(input_ast_path, output_ast_path):
    try:
        with open(input_ast_path, 'r', encoding='utf-8') as f:
            ast = json.load(f)
        
        modified_ast = transform_if_elseif(ast)
        
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

def apply_ch_if_elseIF_transformation(input_dir, output_dir):
    transform_directory(input_dir, output_dir)