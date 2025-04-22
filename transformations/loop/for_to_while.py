# Sofia Deichert - Code Transformation Project
# R1-loop: equivalent transformation among for structure and while structure
# (2) for loop → while loop

import json
import copy
import os

def transform_for_to_while(ast_node):
    """
    Transform for loops into equivalent while loops:
    1. Move initialization before loop
    2. Change for to while with just condition
    3. Move update statements to end of loop body
    4. Enclose whole structure in scope block
    """
    # Deep copy to avoid modifying original
    modified_ast = copy.deepcopy(ast_node)
    
    # Find all for_statement nodes in AST
    for_nodes = find_for_statements(modified_ast)
    
    # Nothing to change
    if not for_nodes:
        return modified_ast
    
    # Process transformations in reverse order (to avoid position shifting issues)
    # Sort by start position so deeper nested loops get transformed first
    for for_node in sorted(for_nodes, key=lambda x: x["start_byte"], reverse=True):
        transform_single_for_loop(modified_ast, for_node)
    
    return modified_ast

def find_for_statements(ast_node, results=None):
    """
    Recursively find all for_statement nodes in the AST
    """
    if results is None:
        results = []
    
    # Check if current node is for_statement
    if ast_node["type"] == "for_statement":
        results.append(ast_node)
    
    # Recursively search children
    for child in ast_node.get("children", []):
        find_for_statements(child, results)
    
    return results

def extract_for_components(for_node):
    """
    extract components of for loop: initialization, condition, update, and body
    """
    components = {
        "initialization": "",
        "condition": "",
        "update": "",
        "body": "",
        "body_node": None
    }
    
    children = for_node["children"]
    found_for = False
    found_open_paren = False
    
    # Extract initialization, condition, and update from for loop header
    semicolon_count = 0
    
    for i, child in enumerate(children):
        # Skip 'for' keyword
        if child["type"] == "for":
            found_for = True
            continue
        
        # Skip opening parenthesis
        if found_for and child["type"] == "(" and not found_open_paren:
            found_open_paren = True
            start_index = i + 1
            continue
        
        # After finding for and open paren, look for components
        if found_open_paren:
            if child["type"] == ";":
                semicolon_count += 1
                continue
            
            if child["type"] == ")":
                end_index = i
                break
            
            # First part is initialization (before first semicolon)
            if semicolon_count == 0:
                components["initialization"] += child["text"]
                if i < len(children) - 1 and children[i+1]["type"] != ";":
                    components["initialization"] += " "
            
            # Second part is condition (between first and second semicolon)
            elif semicolon_count == 1:
                components["condition"] += child["text"]
                if i < len(children) - 1 and children[i+1]["type"] != ";":
                    components["condition"] += " "
            
            # Third part is update (after second semicolon, before closing paren)
            elif semicolon_count == 2:
                components["update"] += child["text"]
                if i < len(children) - 1 and children[i+1]["type"] != ")":
                    components["update"] += " "
    
    # The body is last child (after condition and update)
    for i in range(len(children) - 1, -1, -1):
        if children[i]["type"] not in ["for", "(", ";"]:
            if children[i]["type"] != ")":
                components["body"] = children[i]["text"]
                components["body_node"] = children[i]
            break
    
    return components

def transform_single_for_loop(ast_root, for_node):
    """
    Transform a single for loop into an equivalent while loop
    """
    # Extract for loop components
    components = extract_for_components(for_node)
    initialization = components["initialization"].strip()
    condition = components["condition"].strip()
    update = components["update"].strip()
    body = components["body"]
    body_node = components["body_node"]
    
    # Special handling for empty components
    if not condition:
        condition = "true" # Use true for empty condition (infinite loop)
    
    # Handle compound vs non-compound body
    if body_node and body_node["type"] == "compound_statement":
        # If body is already a compound statement (has { }), insert update at end
        if body.strip().startswith("{") and body.strip().endswith("}"):
            # Extract body content within braces
            body_content = body.strip()[1:-1].strip()
            
            # Create new body with update statement appended
            if update:
                # If body content is not empty, ensure it ends with a semicolon if needed
                if body_content and not body_content.strip().endswith(";"):
                    body_content += " ;"
                
                # Add update statement at end
                new_body = "{ " + body_content
                if body_content:
                    new_body += " "
                new_body += update + " ; }"
            else:
                new_body = "{ " + body_content + " }"
        else:
            # If body doesn't have braces but is still a compound statement
            new_body = "{ " + body + " " + update + " ; }"
    else:
        # If body is single statement (no braces), wrap it and add update
        if update:
            new_body = "{ " + body
            if not body.strip().endswith(";"):
                new_body += " ; "
            new_body += " " + update + " ; }"
        else:
            new_body = "{ " + body + " }"
    
    # Construct while loop replacement
    if initialization:
        replacement = "{ " + initialization + " ; while ( " + condition + " ) " + new_body + " }"
    else:
        replacement = "{ while ( " + condition + " ) " + new_body + " }"
    
    # Replace for loop text in AST
    start_pos = for_node["start_byte"]
    end_pos = for_node["end_byte"]
    
    # Replace in root text by manipulating text field of appropriate nodes
    replace_text_in_ast(ast_root, start_pos, end_pos, replacement)

def replace_text_in_ast(node, start_pos, end_pos, replacement):
    """
    Replace a substring of text in AST, starting at deepest node and propagating changes upward through parent nodes
    """
    # Check if this node contains replacement range
    node_start = node.get("start_byte")
    node_end = node.get("end_byte")
    
    if node_start is None or node_end is None:
        return False
    
    # If replacement is fully contained in this node
    if node_start <= start_pos and node_end >= end_pos:
        # Check if any child contains the replacement
        child_replaced = False
        for child in node.get("children", []):
            if replace_text_in_ast(child, start_pos, end_pos, replacement):
                child_replaced = True
                break
        
        # If no child contained replacement or this node has no children,
        # apply replacement to this node's text
        if not child_replaced or not node.get("children"):
            if node_start == start_pos and node_end == end_pos:
                # Direct replacement of node's text
                node["text"] = replacement
                return True
            else:
                # Replace portion of node's text
                prefix = node["text"][:start_pos - node_start]
                suffix = node["text"][end_pos - node_start:]
                node["text"] = prefix + replacement + suffix
                return True
        
        # Update this node's text based on its children's text
        # This handles propagation of changes upward
        if child_replaced and node.get("children"):
            # Reconstruct this node's text from its children
            node_text = ""
            for child in node.get("children", []):
                node_text += child.get("text", "") + ' '
            node["text"] = node_text
            return True
    return False

def remove_trailing_spaces_before_braces(ast_node):
    """
    Removes spaces between the last bracket and quote in the root node's text
    """
    # Only process root "translation_unit" node
    if ast_node["type"] == "translation_unit" and "text" in ast_node:
        text = ast_node["text"]
        # Remove any trailing spaces after last closing brace
        if text.rstrip().endswith("}"):
            last_brace_index = text.rstrip().rfind("}")
            ast_node["text"] = text[:last_brace_index + 1] + text[last_brace_index + 1:].lstrip()
    
    return ast_node

def transform_file(input_ast_path, output_ast_path):
    """
    Transform single AST file, converting for loops to while loops
    """
    try:
        # Load AST from file
        with open(input_ast_path, 'r', encoding='utf-8') as f:
            ast = json.load(f)
        
        # Apply transformation
        modified_ast = transform_for_to_while(ast)

        # Clean up any trailing spaces before braces in root node
        modified_ast = remove_trailing_spaces_before_braces(modified_ast)
        
        # Save modified AST
        with open(output_ast_path, 'w', encoding='utf-8') as f:
            json.dump(modified_ast, f, indent=2)
        
    except Exception as e:
        print(f"Error transforming {input_ast_path}: {e}")
        # Log full error traceback for debugging
        import traceback
        print(traceback.format_exc())

def transform_directory(input_dir, output_dir):
    """
    Transform all AST files in directory, converting for loops to while loops
    """
    os.makedirs(output_dir, exist_ok=True)
    
    # Process each AST file in input directory
    for filename in os.listdir(input_dir):
        if filename.endswith('.json'):
            input_path = os.path.join(input_dir, filename)
            output_path = os.path.join(output_dir, filename)
            transform_file(input_path, output_path)

def apply_for_to_while_transformation(input_dir, output_dir):
    """
    Apply for loop to while loop transformation
    """
    transform_directory(input_dir, output_dir)