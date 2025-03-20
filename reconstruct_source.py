# Sofia Deichert - Code Transformation Project
# Reconstruct C++ source code from AST

import json
import os


def reconstruct_source_from_ast(ast_json):
    # convert string -> dict if needed
    if isinstance(ast_json, str):
        ast_dict = json.loads(ast_json)
    else:
        ast_dict = ast_json
    
    # extract text field from root node
    # text from entire translation unit = whole code
    return ast_dict.get("text", "")


def reconstruct_and_save(ast_file_path, output_dir="modernized_code"):
    os.makedirs(output_dir, exist_ok=True)
    
    # load AST from file
    with open(ast_file_path, 'r', encoding='utf-8') as f:
        ast_json = json.load(f)
    
    # reconstruct source from ast
    source_code = reconstruct_source_from_ast(ast_json)
    
    # create output file path
    base_name = os.path.basename(ast_file_path)
    source_file_name = base_name.replace('.json', '.cpp')
    output_file_path = os.path.join(output_dir, source_file_name)
    
    # write reconstructed source to file
    with open(output_file_path, 'w', encoding='utf-8') as f:
        f.write(source_code)
    
    return output_file_path

# default dir = asts, change as necessary
# output dir = modernized_code, change as necessary
# process all AST files in directory + save reconstructed source code
def process_all_asts(ast_dir="transformed_asts/return_type_deduction", output_dir="return_type_deduction_code"):
    output_files = []
    
    for filename in os.listdir(ast_dir):
        if filename.endswith('.json'):
            ast_file_path = os.path.join(ast_dir, filename)
            output_file = reconstruct_and_save(ast_file_path, output_dir)
            output_files.append(output_file)
            # print(f"Reconstructed: {output_file}")
    
    return output_files

if __name__ == "__main__":
    output_files = process_all_asts()  # process all ASTs in asts directory