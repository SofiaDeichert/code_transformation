# Sofia Deichert - Code Transformation Project
# C++14 transformation for return type deduction with auto

import json
import copy
import os

def transform_return_type_to_auto(ast_node):
    """
    Transforms function return types to 'auto' according to C++14 feature
    Rules:
    - void functions remain void (no change)
    - int main() remains int (no change)
    - All other functions(both declarations and definitions) get auto return type
    
    Args:
        ast_node: The AST node to transform
        
    Returns:
        (modified_node, modified) 
        modified_node = transformed AST
        modified = boolean indicating if any changes were made
    """
    # deep copy to avoid modifying original
    modified_node = copy.deepcopy(ast_node)
    node_modified = False
    
    # Process current node if it's a function declaration or definition
    if modified_node["type"] in ["function_definition", "declaration"]:
        # First, check if this is actually a function (has a function_declarator)
        # -both var and function declarations and have "type":"declaration" in ast 
        # -so this will avoid changing variable decalarations to auto (e.g., int x; to auto x;)
        is_function = False
        function_name = None
        function_declarator = None
        
        for child in modified_node["children"]:
            if child["type"] == "function_declarator":
                is_function = True
                function_declarator = child
                # Get function name to check if it's main
                for func_child in child["children"]:
                    if func_child["type"] == "identifier":
                        function_name = func_child["text"]
                        break
                break
        
        # Only proceed if it's a function and not main
        if is_function and function_name != "main":
            # Find return type node - could be primitive_type, type_identifier, or sized_type_specifier
            # [Check documentation is more types to account for]
            return_type_index = -1
            return_type_node = None
            
            for i, child in enumerate(modified_node["children"]):
                # Check for various return type node patterns
                if child["type"] in ["primitive_type", "type_identifier", "sized_type_specifier"]:
                    # If it's a primitive type, check if it's void
                    if child["type"] == "primitive_type" and child["text"] == "void":
                        # Skip void functions
                        break
                    
                    return_type_index = i
                    return_type_node = child
                    break
            
            # If we found valid return type to change
            if return_type_node is not None:
                # Store original return type text and positions
                original_text = return_type_node["text"]
                original_start = return_type_node["start_byte"]
                original_end = return_type_node["end_byte"]
                
                # Calculate byte difference for adjustment
                byte_diff = len("auto") - len(original_text)
                
                # Update node's full text
                original_full_text = modified_node["text"]
                text_prefix = original_full_text[:return_type_node["start_byte"] - modified_node["start_byte"]]
                text_suffix = original_full_text[return_type_node["end_byte"] - modified_node["start_byte"]:]
                modified_node["text"] = text_prefix + "auto" + text_suffix
                
                # Create new auto node to replace return type
                auto_node = {
                    "type": "primitive_type",
                    "start_byte": original_start,
                    "end_byte": original_start + len("auto"),
                    "text": "auto",
                    "children": []
                }
                
                # Replace return type node
                modified_node["children"][return_type_index] = auto_node
                
                # Adjust byte positions for all nodes after change
                adjust_byte_positions(modified_node, original_end, byte_diff)
                
                node_modified = True
    
    # Recursively process all child nodes
    for i, child in enumerate(modified_node["children"]):
        new_child, child_modified = transform_return_type_to_auto(child)
        modified_node["children"][i] = new_child
        
        # If child was modified, we need to update this node's text
        if child_modified:
            node_modified = True
            
            # If this is the translation_unit (root) node, we need to update its text
            if modified_node["type"] == "translation_unit":
                # Instead of just concatenating, we'll use original text as a template
                # and replace each child's text while preserving spacing
                original_text = ast_node["text"]
                modified_text = original_text
                
                # Process children in reverse order (to avoid position shifting issues)
                for j in range(len(modified_node["children"]) - 1, -1, -1):
                    child_node = modified_node["children"][j]
                    orig_child = ast_node["children"][j]
                    
                    # Only replace if child's text has changed
                    if child_node["text"] != orig_child["text"]:
                        # Calculate positions in the original text
                        start_pos = orig_child["start_byte"] - ast_node["start_byte"]
                        end_pos = orig_child["end_byte"] - ast_node["start_byte"]
                        
                        # Replace just this child's portion of text
                        modified_text = modified_text[:start_pos] + child_node["text"] + modified_text[end_pos:]
                
                modified_node["text"] = modified_text
    
    return modified_node, node_modified

def adjust_byte_positions(node, start_position, byte_diff):
    """
    Recursively adjusts byte positions in AST after a text change.
    
    Args:
        node: The AST node to adjust
        start_position: Positions >= this value will be adjusted
        byte_diff: amount to adjust by
    """
    # Skip node if it doesn't have byte positions
    if "start_byte" not in node or "end_byte" not in node:
        return
    
    # Adjust end position if it's after start position
    if node["end_byte"] >= start_position:
        node["end_byte"] += byte_diff
    
    # Adjust start position if it's after start position
    if node["start_byte"] >= start_position:
        node["start_byte"] += byte_diff
    
    # Recursively adjust children
    for child in node.get("children", []):
        adjust_byte_positions(child, start_position, byte_diff)

def transform_file(input_ast_path, output_ast_path):
    """
    Transforms single AST file to use auto return type deduction for normal functions
    
    Args:
        input_ast_path: Path to input AST file
        output_ast_path: Path to save transformed AST
    """
    try:
        # Load AST from file
        with open(input_ast_path, 'r', encoding='utf-8') as f:
            ast = json.load(f)
        
        # Apply transformation
        modified_ast, _ = transform_return_type_to_auto(ast)
        
        # Save modified AST
        with open(output_ast_path, 'w', encoding='utf-8') as f:
            json.dump(modified_ast, f, indent=2)
            
        print(f"Transformed {input_ast_path} -> {output_ast_path}")
        
    except Exception as e:
        print(f"Error transforming {input_ast_path}: {e}")
        # Log full error traceback (debugging)
        import traceback
        print(traceback.format_exc())

def transform_directory(input_dir, output_dir):
    """
    Transforms all AST files in directory to use auto return type deduction for normal functions
    
    Args:
        input_dir: Directory containing input AST files
        output_dir: Directory to save transformed AST files
    """
    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)
    
    # Process each AST file in input directory
    for filename in os.listdir(input_dir):
        if filename.endswith('.json'):
            input_path = os.path.join(input_dir, filename)
            output_path = os.path.join(output_dir, filename)
            transform_file(input_path, output_path)

# This function will be called from transform_ast.py
def apply_transformation(input_dir, output_dir):
    """
    Apply C++14 return type deduction transformation
    
    Args:
        input_dir: Directory containing input AST files
        output_dir: Directory to save transformed AST files
    """
    print("Applying C++14 return type deduction transformation...")
    transform_directory(input_dir, output_dir)
    print("Transformation complete.")

if __name__ == "__main__":
    # For testing module independently
    input_asts_dir = "asts"
    output_asts_dir = "transformed_asts/cpp14_auto_return"
    
    apply_transformation(input_asts_dir, output_asts_dir)