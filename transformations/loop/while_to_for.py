# Sofia Deichert - Code Transformation Project
# R1-loop: equivalent transformation among for structure and while structure
# (1) while loop → for loop

import json
import os
import re

def transform_while_to_for(ast_json):
    """
    Transforms while loops to for loops by modifying text directly.
    Converts while(condition) to for( ; condition ; )
    Preserves do-while loops (doesn't transform them)
    """
    # get original full text from root node
    if "text" not in ast_json:
        return ast_json  # nothing to do if there's no text
    
    full_text = ast_json["text"]
    
    # Step 1: First identify all "do-while" loops to exclude them
    # Pattern: "do" followed by a block, then "while (condition);"
    do_while_positions = []
    
    # find all "do" and all "while" keywords
    do_matches = list(re.finditer(r'\bdo\b', full_text))
    while_matches = list(re.finditer(r'\bwhile\b', full_text))
    
    # For each "do", find matching "while" by counting braces
    for do_match in do_matches:
        do_pos = do_match.start()
        # Find matching closing brace
        open_count = 0
        close_brace_pos = -1
        
        for i in range(do_pos, len(full_text)):
            if full_text[i] == '{':
                open_count += 1
            elif full_text[i] == '}':
                open_count -= 1
                if open_count == 0:
                    close_brace_pos = i
                    break
        
        if close_brace_pos < 0:
            continue  # No matching brace found (shouldn't happen)
        
        # Look for "while" after closing brace
        for while_match in while_matches:
            while_pos = while_match.start()
            if while_pos > close_brace_pos and while_pos < len(full_text):
                # Make sure it's not too far (only whitespace in between)
                between_text = full_text[close_brace_pos:while_pos].strip()
                if between_text == "":
                    do_while_positions.append(while_pos)
                    break
    
    # Step 2: Transform all "while" loops except those in do-while positions
    result_text = full_text
    
    # Find all standalone "while" loops
    pattern = r'while\s*(\([^{;]+\))'
    
    # Process matches in reverse order to maintain positions
    matches = list(re.finditer(pattern, result_text))
    for match in reversed(matches):
        while_pos = match.start()
        
        # Skip if this "while" is part of a do-while loop
        if while_pos in do_while_positions:
            continue
        
        # Extract condition
        condition = match.group(1)[1:-1].strip()  # Remove parentheses
        
        # Replace with "for"
        replacement = f"for ( ; {condition} ; )"
        result_text = result_text[:while_pos] + replacement + result_text[match.end():]
    
    # Update text in AST
    ast_json["text"] = result_text
    
    return ast_json

def transform_file(input_ast_path, output_ast_path):
    """
    Transforms single AST file, converting while loops to for loops
    
    Args:
        input_ast_path: Path to input AST file
        output_ast_path: Path to save transformed AST
    """
    try:
        # Load AST from file
        with open(input_ast_path, 'r', encoding='utf-8') as f:
            ast = json.load(f)
        
        # Apply transformation
        modified_ast = transform_while_to_for(ast)
        
        # Save modified AST
        with open(output_ast_path, 'w', encoding='utf-8') as f:
            json.dump(modified_ast, f, indent=2)
        
    except Exception as e:
        print(f"Error transforming {input_ast_path}: {e}")
        import traceback
        print(traceback.format_exc())

def transform_directory(input_dir, output_dir):
    """
    Transforms all AST files in directory, converting while loops to for loops
    
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

# Function to be called from transform_ast.py
def apply_while_to_for_transformation(input_dir, output_dir):
    """
    Apply while to for loop transformation
    
    Args:
        input_dir: Directory containing input AST files
        output_dir: Directory to save transformed AST files
    """
    transform_directory(input_dir, output_dir)

if __name__ == "__main__":
    # For testing module independently
    input_asts_dir = "asts"
    output_asts_dir = "transformed_asts/while_to_for"
    
    apply_while_to_for_transformation(input_asts_dir, output_asts_dir)