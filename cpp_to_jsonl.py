# Sofia Deichert - Code Transformation Project
# Takes separate .cpp files and puts them back into single jsonl file
# Does opposite of jsonl_to_cpp.py

import json
import os
import re

#Process all .cpp files in input directory and output them to jsonl file
def process_cpp_directory(input_dir, output_file, original_jsonl=None):
    if not os.path.exists(input_dir):
        print(f"Input directory not found: {input_dir}")
        return
    
    # Get all .cpp files and sort them by their numeric ID
    cpp_files = []
    for filename in os.listdir(input_dir):
        if filename.endswith('.cpp'):
            # Extract ID number from filename (code_XXXX.cpp)
            match = re.match(r'code_(\d+)\.cpp', filename)
            if match:
                file_id = int(match.group(1))
                cpp_files.append((file_id, filename))
    
    # Sort by ID
    cpp_files.sort()
    
    # Load original JSONL for labels and exact original format
    original_lines = {}
    if original_jsonl and os.path.exists(original_jsonl):
        with open(original_jsonl, 'r', encoding='utf-8') as original_f:
            line_number = 0
            for line in original_f:
                try:
                    data = json.loads(line.strip())
                    if 'id' in data:
                        file_id = data['id']
                        # Store exact original line for each file ID
                        original_lines[file_id] = line.strip()
                except json.JSONDecodeError:
                    print(f"Error parsing line {line_number} in original JSONL")
                line_number += 1
    
    # Process each file and write to jsonl
    with open(output_file, 'w', encoding='utf-8') as out_f:
        for file_id, filename in cpp_files:
            file_path = os.path.join(input_dir, filename)
            
            try:
                # Read C++ file exactly as written by jsonl_to_cpp.py
                with open(file_path, 'r', encoding='utf-8') as cpp_file:
                    code = cpp_file.read()
                
                # construct line that matches original format exactly
                if file_id in original_lines:
                    # Get original line to use as template
                    original_line = original_lines[file_id]
                    
                    # Extract original data
                    original_data = json.loads(original_line)
                    
                    # because we did \n -> \\n in jsonl_to_cpp.py 
                    code = code.replace('\\n', '\n')
                    
                    # Create new data object with updated input
                    new_data = original_data.copy()
                    new_data["input"] = code
                    
                    # Let json.dumps handle proper escaping
                    out_f.write(json.dumps(new_data) + '\n')
                else:
                    # If we don't have original, create new line
                    # Also fix newline escaping here
                    code = code.replace('\\n', '\n')
                    json_obj = {
                        "input": code,
                        "label": 0,  # Default label
                        "id": file_id
                    }
                    out_f.write(json.dumps(json_obj) + '\n')
                
                # print(f"Processed file: {filename}")
                
            except Exception as e:
                print(f"Error processing file {filename}: {e}")
    
    print(f"JSONL file created: {output_file}")

def process_modernized_code(input_dir="modernized_code", output_file="modernized_code.jsonl", original_jsonl="test 1.jsonl"):
    process_cpp_directory(input_dir, output_file, original_jsonl)


if __name__ == "__main__":
    # By default, process modernized_code directory
    # Change parameters as needed
    input_directory = "return_type_deduction_code"
    output_jsonl = "return_type_deduction.jsonl"
    original_jsonl = "test 1.jsonl"  # Original JSONL to get formatting
    
    process_cpp_directory(input_directory, output_jsonl, original_jsonl)