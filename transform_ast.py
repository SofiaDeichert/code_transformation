# Sofia Deichert - Code Transformation Project
# Apply transformation functions to ASTs

import os
import argparse
import sys

# Add project root to python path (for enabling imports)
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

# Import transformations
from transformations.cpp14.return_type_deduction import apply_transformation as apply_return_type_deduction
# from transformations.cpp11.range_based_for import apply_transformation as apply_range_based_for  # Uncomment to use

def apply_transformations(input_dir, output_base_dir):
    """
    Apply all available transformations to ASTs in input directory
    (Each transformation creates its own output folder)
    
    Args:
        input_dir: Directory containing input AST files
        output_base_dir: Base directory where transformation folders will be created
    """
    os.makedirs(output_base_dir, exist_ok=True) 
    
    # -----------------------------------------------
    # Apply C++14 return type deduction transformation
    # -----------------------------------------------
    return_type_deduction_dir = os.path.join(output_base_dir, "return_type_deduction")
    os.makedirs(return_type_deduction_dir, exist_ok=True)
    print(f"Applying return type deduction transformation...")
    apply_return_type_deduction(input_dir, return_type_deduction_dir)
    print(f"Return type deduction transformation complete. Results in {return_type_deduction_dir}")
    
    # -----------------------------------------------
    # Apply C++11 range-based for loop transformation
    # Uncomment these lines to enable this transformation
    # -----------------------------------------------
    # range_based_for_dir = os.path.join(output_base_dir, "range_based_for")
    # os.makedirs(range_based_for_dir, exist_ok=True)
    # print(f"Applying range-based for loop transformation...")
    # apply_range_based_for(input_dir, range_based_for_dir)
    # print(f"Range-based for loop transformation complete. Results in {range_based_for_dir}")
    
    # Add future transformations here, each creating its own directory
    
def main():
    parser = argparse.ArgumentParser(description="Apply C++ modernization transformations to ASTs")
    parser.add_argument("--input", default="asts", help="Directory containing input AST files")
    parser.add_argument("--output", default="transformed_asts", help="Base directory for output ASTs")
    
    args = parser.parse_args()
    
    # Apply all transformations
    apply_transformations(args.input, args.output)
    
    print(f"All transformations completed. Results are in {args.output} directory.")

if __name__ == "__main__":
    main()