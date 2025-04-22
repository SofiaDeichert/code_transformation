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
from transformations.calculation.unary_operator import (
    apply_increment_to_assignment_transformation,
    apply_assignment_to_increment_transformation,
    apply_decrement_to_assignment_transformation,
    apply_assignment_to_decrement_transformation
)

# Import loop transformations
from transformations.loop.while_to_for import apply_while_to_for_transformation
from transformations.loop.for_to_while import apply_for_to_while_transformation

# Import compound assignment transformations
from transformations.calculation.compound_assignment import (
    apply_plus_equal_to_expanded_transformation,
    apply_expanded_to_plus_equal_transformation,
    apply_minus_equal_to_expanded_transformation,
    apply_expanded_to_minus_equal_transformation,
    apply_multiply_equal_to_expanded_transformation,
    apply_expanded_to_multiply_equal_transformation,
    apply_divide_equal_to_expanded_transformation,
    apply_expanded_to_divide_equal_transformation,
    apply_modulo_equal_to_expanded_transformation,
    apply_expanded_to_modulo_equal_transformation,
    apply_left_shift_equal_to_expanded_transformation,
    apply_expanded_to_left_shift_equal_transformation,
    apply_right_shift_equal_to_expanded_transformation,
    apply_expanded_to_right_shift_equal_transformation,
    apply_bitand_equal_to_expanded_transformation,
    apply_expanded_to_bitand_equal_transformation,
    apply_bitor_equal_to_expanded_transformation,
    apply_expanded_to_bitor_equal_transformation,
    apply_bitxor_equal_to_expanded_transformation,
    apply_expanded_to_bitxor_equal_transformation
)

def apply_single_transformation(transformation_func, input_dir, output_base_dir, transformation_name):
    """
    Apply single transformation function and output results to specified directory
    
    Args:
        transformation_func: The transformation function to apply
        input_dir: Directory containing input AST files
        output_base_dir: Base directory where transformation folders will be created
        transformation_name: Name of the transformation (used for directory name and logging)
    """
    transformation_dir = os.path.join(output_base_dir, transformation_name)
    os.makedirs(transformation_dir, exist_ok=True)
    
    print(f"Applying {transformation_name} transformation...")
    transformation_func(input_dir, transformation_dir)
    print(f"{transformation_name} transformation complete. Results in {transformation_dir}\n")
    
    return transformation_dir

def apply_transformations(input_dir, output_base_dir):
    """
    Apply all available transformations to ASTs in input directory
    (Each transformation creates its own output folder)
    
    Args:
        input_dir: Directory containing input AST files
        output_base_dir: Base directory where transformation folders will be created
    """
    os.makedirs(output_base_dir, exist_ok=True)
    
    # Define all transformations as (function, name) tuples
    # Comment out functions you don't want to run
    transformations = [
        # C++14 return type deduction transformation
        # (apply_return_type_deduction, "return_type_deduction"),
        
        # Unary operator transformations
        # (apply_increment_to_assignment_transformation, "increment_to_assignment"),
        # (apply_assignment_to_increment_transformation, "assignment_to_increment"),
        # (apply_decrement_to_assignment_transformation, "decrement_to_assignment"),
        # (apply_assignment_to_decrement_transformation, "assignment_to_decrement"),
        
        # Compound assignment transformations
        # (apply_plus_equal_to_expanded_transformation, "plus_equal_to_expanded"),
        # (apply_expanded_to_plus_equal_transformation, "expanded_to_plus_equal"),
        # (apply_minus_equal_to_expanded_transformation, "minus_equal_to_expanded"),
        # (apply_expanded_to_minus_equal_transformation, "expanded_to_minus_equal"),
        # (apply_multiply_equal_to_expanded_transformation, "multiply_equal_to_expanded"),
        # (apply_expanded_to_multiply_equal_transformation, "expanded_to_multiply_equal"),
        # (apply_divide_equal_to_expanded_transformation, "divide_equal_to_expanded"),
        # (apply_expanded_to_divide_equal_transformation, "expanded_to_divide_equal"),
        # (apply_modulo_equal_to_expanded_transformation, "modulo_equal_to_expanded"),
        # (apply_expanded_to_modulo_equal_transformation, "expanded_to_modulo_equal"),
        # (apply_left_shift_equal_to_expanded_transformation, "left_shift_equal_to_expanded"),
        # (apply_expanded_to_left_shift_equal_transformation, "expanded_to_left_shift_equal"),
        # (apply_right_shift_equal_to_expanded_transformation, "right_shift_equal_to_expanded"),
        # (apply_expanded_to_right_shift_equal_transformation, "expanded_to_right_shift_equal"),
        # (apply_bitand_equal_to_expanded_transformation, "bitand_equal_to_expanded"),
        # (apply_expanded_to_bitand_equal_transformation, "expanded_to_bitand_equal"),
        # (apply_bitor_equal_to_expanded_transformation, "bitor_equal_to_expanded"),
        # (apply_expanded_to_bitor_equal_transformation, "expanded_to_bitor_equal"),
        # (apply_bitxor_equal_to_expanded_transformation, "bitxor_equal_to_expanded"),
        # (apply_expanded_to_bitxor_equal_transformation, "expanded_to_bitxor_equal"),

        # Loop transformations
        # (apply_while_to_for_transformation, "while_to_for"),
        (apply_for_to_while_transformation, "for_to_while")
    ]
    
    # Apply each transformation
    for transformation_func, transformation_name in transformations:
        apply_single_transformation(
            transformation_func, 
            input_dir, 
            output_base_dir, 
            transformation_name
        )

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