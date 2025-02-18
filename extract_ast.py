# Sofia Deichert - Code Transformation Project
# Extract ASTs from C++ files and save them to new files in json format
import os
import json
from tree_sitter import Language, Parser

# load C++ lang
import tree_sitter_cpp as tscpp
CPP_LANGUAGE = Language(tscpp.language())

parser = Parser(CPP_LANGUAGE) # Initialize parser

# folder to store ASTs
AST_OUTPUT_FOLDER = 'asts'
os.makedirs('asts', exist_ok=True)  

# convert ast to json-like structure
def ast_to_json(node):
    result = {
        "type": node.type,  # e.g., "function_definition"/"identifier"
        "start_byte": node.start_byte,  # Start byte position in source code
        "end_byte": node.end_byte,  # End byte position in source code
        "text": node.text.decode("utf-8"),  # Text content of node
        "children": []  # list to store child nodes
    }

    # recursively add child nodes
    for child in node.children:
        result["children"].append(ast_to_json(child))

    return result

def extract_ast_from_file(file_path):
    try:
        with open(file_path, 'r', encoding='utf-8') as file:
            code = file.read()
            tree = parser.parse(bytes(code, 'utf-8'))

            # Create corresponding AST file path
            file_name = os.path.basename(file_path)  # e.g., code_0000.cpp
            ast_file_name = file_name.replace('.cpp', '.json')  # e.g., code_0000.json
            ast_file_path = os.path.join(AST_OUTPUT_FOLDER, ast_file_name)

            ast_json = ast_to_json(tree.root_node) # ast -> json 

            # Save AST to json file
            with open(ast_file_path, 'w', encoding='utf-8') as ast_file:
                json.dump(ast_json, ast_file, indent=2)

    except Exception as e:
        print(f"Error processing file {file_path}: {e}")

def extract_ast_from_directory(directory):
    if not os.path.exists(directory):
        print(f"Directory not found: {directory}")
        return

    for filename in os.listdir(directory):
        if filename.endswith('.cpp'):
            file_path = os.path.join(directory, filename)
            extract_ast_from_file(file_path)

if __name__ == "__main__":
    # Extract ASTs for all C++ files and save them to 'asts' folder
    extract_ast_from_directory('extracted_code')