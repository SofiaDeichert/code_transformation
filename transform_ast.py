# Sofia Deichert - Code Transformation Project
# Apply transformation functions to ASTs

import os
import argparse
import sys

# Add project root to python path (for enabling imports)
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

# Import transformations
from transformations.cpp14.return_type_deduction import apply_transformation as apply_return_type_deduction
# Import unary operator transformations
from transformations.calculation.unary_operator import apply_increment_to_assignment_transformation
from transformations.calculation.unary_operator import apply_assignment_to_increment_transformation
from transformations.calculation.unary_operator import apply_decrement_to_assignment_transformation
from transformations.calculation.unary_operator import apply_assignment_to_decrement_transformation

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
    # Comment out following block to disable transformation
    # -----------------------------------------------
    # return_type_deduction_dir = os.path.join(output_base_dir, "return_type_deduction")
    # os.makedirs(return_type_deduction_dir, exist_ok=True)
    # print(f"Applying return type deduction transformation...")
    # apply_return_type_deduction(input_dir, return_type_deduction_dir)
    # print(f"Return type deduction transformation complete. Results in {return_type_deduction_dir}\n")
    
    # -----------------------------------------------
    # Apply increment to assignment transformation (i++ -> i = i + 1)
    # Comment out following block to disable transformation
    # -----------------------------------------------
    increment_to_assignment_dir = os.path.join(output_base_dir, "increment_to_assignment")
    os.makedirs(increment_to_assignment_dir, exist_ok=True)
    print(f"Applying increment to assignment transformation...")
    apply_increment_to_assignment_transformation(input_dir, increment_to_assignment_dir)
    print(f"Increment to assignment transformation complete. Results in {increment_to_assignment_dir}\n")
    
    # # -----------------------------------------------
    # # Apply assignment to increment transformation (i = i + 1 -> i++)
    # # Comment the following block to disable transformation
    # # -----------------------------------------------
    # assignment_to_increment_dir = os.path.join(output_base_dir, "assignment_to_increment")
    # os.makedirs(assignment_to_increment_dir, exist_ok=True)
    # print(f"Applying assignment to increment transformation...")
    # apply_assignment_to_increment_transformation(input_dir, assignment_to_increment_dir)
    # print(f"Assignment to increment transformation complete. Results in {assignment_to_increment_dir}\n")
    
    # # -----------------------------------------------
    # # Apply decrement to assignment transformation (i-- -> i = i - 1)
    # # Comment out following block to disable transformation
    # # -----------------------------------------------
    # decrement_to_assignment_dir = os.path.join(output_base_dir, "decrement_to_assignment")
    # os.makedirs(decrement_to_assignment_dir, exist_ok=True)
    # print(f"Applying decrement to assignment transformation...")
    # apply_decrement_to_assignment_transformation(input_dir, decrement_to_assignment_dir)
    # print(f"Decrement to assignment transformation complete. Results in {decrement_to_assignment_dir}\n")
    
    # # # # -----------------------------------------------
    # # # # Apply assignment to decrement transformation (i = i - 1 -> i--)
    # # # # Comment out following block to disable transformation
    # # # # -----------------------------------------------
    # assignment_to_decrement_dir = os.path.join(output_base_dir, "assignment_to_decrement")
    # os.makedirs(assignment_to_decrement_dir, exist_ok=True)
    # print(f"Applying assignment to decrement transformation...")
    # apply_assignment_to_decrement_transformation(input_dir, assignment_to_decrement_dir)
    # print(f"Assignment to decrement transformation complete. Results in {assignment_to_decrement_dir}\n")
    
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