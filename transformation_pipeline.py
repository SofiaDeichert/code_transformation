# Sofia Deichert - Code Transformation Project
# File for complete transformation pipeline
# 1) takes jsonl file input
# 2) applies transformations
# 3) outputs transformed jsonl

import os
import argparse
import sys
import time
from pathlib import Path

# Import functions from individual pipeline steps
from jsonl_to_cpp import process_jsonl_file
from extract_ast import extract_ast_from_directory
from transform_ast import apply_transformations
from reconstruct_source import process_all_asts
from cpp_to_jsonl import process_cpp_directory

def run_pipeline(input_jsonl, output_dir="pipeline_output", transformation_type="return_type_deduction"):
    """
    Run complete transformation pipeline:
    
    Args:
        input_jsonl: Path to input jsonl file
        output_dir: Directory to store all intermediate and final outputs
        transformation_type: Type of transformation to apply (e.g., "return_type_deduction")
    """
    start_time = time.time()
    
    # Create output directory structure
    base_dir = Path(output_dir)
    extracted_code_dir = base_dir / "extracted_code"
    asts_dir = base_dir / "asts"
    transformed_asts_dir = base_dir / "transformed_asts"
    modernized_code_dir = base_dir / f"{transformation_type}_code"
    output_jsonl = base_dir / f"{transformation_type}.jsonl"
    
    base_dir.mkdir(exist_ok=True)
    
    print(f"Starting transformation pipeline on {input_jsonl}")
    print(f"All outputs will be saved to {base_dir.absolute()}")
    
    # Step 1: Extract code from jsonl to .cpp files
    print("\n--- Step 1: Extracting code from JSONL ---")
    process_jsonl_file(input_jsonl, str(extracted_code_dir))
    
    # Step 2: Generate ASTs from .cpp files
    print("\n--- Step 2: Generating ASTs ---")
    extract_ast_from_directory(str(extracted_code_dir))
    
    # Move ASTs to pipeline directory (they're created in 'asts' by default)
    if os.path.exists('asts'):
        # Create destination directory
        asts_dir.mkdir(exist_ok=True)
        
        # Move all files
        for file in os.listdir('asts'):
            src = os.path.join('asts', file)
            dst = os.path.join(str(asts_dir), file)
            
            # Copy instead of move to avoid permission issues
            with open(src, 'r', encoding='utf-8') as src_file:
                content = src_file.read()
                with open(dst, 'w', encoding='utf-8') as dst_file:
                    dst_file.write(content)
            
            # Remove original
            try:
                os.remove(src)
            except:
                print(f"Could not remove {src}, continuing...")
        
        # Remove original directory
        try:
            os.rmdir('asts')
        except:
            print("Could not remove 'asts' directory, continuing...")
    
    # Step 3: Apply transformations to ASTs
    print(f"\n--- Step 3: Applying {transformation_type} transformation ---")
    transformed_asts_base_dir = transformed_asts_dir
    transformed_asts_base_dir.mkdir(exist_ok=True)
    apply_transformations(str(asts_dir), str(transformed_asts_base_dir))
    
    # Step 4: Reconstruct source code from transformed ASTs
    print("\n--- Step 4: Reconstructing source code ---")
    transformation_ast_dir = transformed_asts_base_dir / transformation_type
    modernized_code_dir.mkdir(exist_ok=True)
    process_all_asts(str(transformation_ast_dir), str(modernized_code_dir))
    
    # Step 5: Convert modernized code back to jsonl
    print("\n--- Step 5: Converting modernized code to JSONL ---")
    process_cpp_directory(str(modernized_code_dir), str(output_jsonl), input_jsonl)
    
    elapsed_time = time.time() - start_time
    print(f"\nPipeline completed in {elapsed_time:.2f} seconds!")
    print(f"Transformed JSONL saved to: {output_jsonl}")

def main():
    parser = argparse.ArgumentParser(description="Run the complete C++ modernization pipeline")
    parser.add_argument("--input", default="test 1.jsonl", help="Path to input jsonl file")
    parser.add_argument("--output-dir", default="pipeline_output", help="Directory to store all outputs")
    parser.add_argument("--transform", default="return_type_deduction", 
                        choices=["return_type_deduction"], 
                        help="Type of transformation to apply")
    
    args = parser.parse_args()
    
    run_pipeline(args.input, args.output_dir, args.transform)

if __name__ == "__main__":
    main()