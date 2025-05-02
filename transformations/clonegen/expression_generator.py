# Sofia Deichert - Code Transformation Project
# Helper file for generating equivalent expression for integer constants (for ch_define.py)
import random

def safe_randint(a, b):
    """handles empty ranges"""
    if a >= b:
        return a
    return random.randint(a, b)

def generate_equivalent_expression(number):
    """generate an equivalent expression for a numeric constant"""
    is_negative = number.startswith('-')
    num_str = number[1:] if is_negative else number
    
    try:
        num = int(num_str)
    except ValueError:
        return number
    
    # Get a transformed expression based on complexity
    complexity = min(3, max(1, (num // 5) + 1))  # Scale complexity with num size
    result = transform_number(num, complexity)
    
    return f"- {result}" if is_negative else result

def transform_number(num, complexity=None):
    """transform an integer number into an equivalent expression with varying complexity"""
    if complexity is None:
        # determine complexity
        if num <= 3:
            complexity = 1
        else:
            complexity = safe_randint(1, min(3, (num // 5) + 1))
    
    # get number of operands based on complexity
    operand_count = safe_randint(2, complexity + 2)
    
    # Choose an operation pattern
    pattern_type = safe_randint(0, 3)
    
    if pattern_type == 0:
        # Addition-based pattern
        return create_addition_pattern(num, operand_count)
    elif pattern_type == 1:
        # Multiplication-division pattern
        return create_multiplicative_pattern(num, operand_count)
    elif pattern_type == 2:
        # Subtraction-based pattern
        return create_subtraction_pattern(num, operand_count)
    else:
        # Mixed operations pattern
        return create_mixed_pattern(num, operand_count)

def create_addition_pattern(num, operand_count):
    """Create an addition-based pattern with given number of operands"""
    if operand_count == 2:
        if num == 0:
            # Special case for 0
            a = safe_randint(1, 10)
            return f"( {a} + {-a} )"
        
        # For all other values
        a = safe_randint(0, num)
        b = num - a
        return f"( {a} + {b} )"
    
    # for more operands, distribute the total among them
    terms = []
    remaining = num
    
    for i in range(operand_count - 1):
        if remaining <= 0:
            terms.append(0)
        else:
            max_term = remaining - (operand_count - i - 2 if operand_count - i - 2 > 0 else 0)
            term = safe_randint(0, max(0, max_term))
            terms.append(term)
            remaining -= term
    
    terms.append(remaining) # add last term
    
    return "( " + " + ".join(str(t) for t in terms) + " )"

def create_multiplicative_pattern(num, operand_count):
    """create a multiplication/division-based pattern"""
    if num == 0:
        # special handling - cannot use division for 0
        return f"( 0 * {safe_randint(1, 10)} )"
    
    if operand_count == 2:
        # Simple division or multiplication
        op_choice = safe_randint(0, 1)
        
        if op_choice == 0 and num > 1:
            # Find factors
            factors = [i for i in range(2, min(num, 20)) if num % i == 0]
            if factors:
                factor = random.choice(factors)
                return f"( {factor} * {num // factor} )"
        
        # Division
        multiplier = safe_randint(2, 10)
        return f"( {num * multiplier} / {multiplier} )"
    
    # For more operands, create more complex patterns
    if safe_randint(0, 1) == 0:
        # Multiplication with adjustment: a * b + c
        factor_found = False
        for attempt in range(5):  # Try a few times to find good factors
            factor = safe_randint(2, min(num, 10))
            if num % factor == 0:
                # Clean division
                return f"( {factor} * {num // factor} )"
            else:
                multiple = (num // factor) * factor
                remainder = num - multiple
                if remainder > 0:
                    if operand_count > 3 and remainder > 1:
                        # break down remainder
                        r1 = safe_randint(1, remainder - 1)
                        r2 = remainder - r1
                        return f"( {factor} * {num // factor} + {r1} + {r2} )"
                    else:
                        return f"( {factor} * {num // factor} + {remainder} )"
                    factor_found = True
                    break
        
        if not factor_found:
            # fallback - nested division
            multiplier1 = safe_randint(2, 5)
            multiplier2 = safe_randint(2, 5)
            return f"( ( {num * multiplier1 * multiplier2} / {multiplier2} ) / {multiplier1} )"
    
    # mixed multiplication/division: (a * b) / c
    multiplier = safe_randint(2, 5)
    divisor = safe_randint(2, 5)
    return f"( ( {num * divisor} * {multiplier} ) / ( {multiplier} * {divisor} ) )"

def create_subtraction_pattern(num, operand_count):
    """create a subtraction-based pattern"""
    if operand_count == 2:
        # Simple subtraction 
        subtractor = safe_randint(1, 20)
        return f"( {num + subtractor} - {subtractor} )"
    
    # For more operands, create a chain of subtractions
    # Start w/ value large enough to ensure no negative operands
    min_base = num + (operand_count - 1)  # Ensure enough room for subtractions
    base = safe_randint(min_base, min_base + 20)
    
    # Generate subtractions that result in the target number
    terms = []
    
    # First term is the base
    terms.append(str(base))
    
    # We need to subtract (base - num) in total across all remaining terms
    total_to_subtract = base - num
    remaining_to_subtract = total_to_subtract
    
    # distribute subtractions across operand_count - 1 terms
    for i in range(operand_count - 2):
        if remaining_to_subtract <= 0:
            # Nothing left to subtract
            terms.append("0")
        else:
            max_subtract = min(10, remaining_to_subtract)
            subtraction = safe_randint(1, max_subtract)
            terms.append(str(subtraction))
            remaining_to_subtract -= subtraction
    
    # Final term to reach exactly num
    if remaining_to_subtract > 0:
        terms.append(str(remaining_to_subtract))
    else:
        terms.append("0")  # add a zero if we've already reached target
    
    return "( " + " - ".join(terms) + " )"

def create_mixed_pattern(num, operand_count):
    """create a pattern with mixed operations, avoiding negative operands"""
    if num == 0 and operand_count <= 2:
        # Special handling for 0 with only 2 operands 
        val = safe_randint(1, 10)
        return f"( {val} - {val} )"
    
    if operand_count <= 2:
        # Simple patterns for small operand counts - works for all non-zero nums
        pattern_choice = safe_randint(0, 2)
        if pattern_choice == 0:
            return create_addition_pattern(num, 2)
        elif pattern_choice == 1:
            return create_subtraction_pattern(num, 2)
        else:
            return create_multiplicative_pattern(num, 2)
    
    # choose mixed operation pattern
    pattern_choice = safe_randint(0, 3)
    
    if pattern_choice == 0:
        # a * b + c pattern
        if num > 1:
            factor = safe_randint(1, max(1, min(num, 10)))
            quotient = num // factor
            remainder = num - (factor * quotient)
            if remainder > 0:
                return f"( {factor} * {quotient} + {remainder} )"
            else:
                return f"( {factor} * {quotient} )"
        else:
            # for 0 and 1, use addition pattern
            return create_addition_pattern(num, operand_count)
    
    elif pattern_choice == 1:
        # (a + b) / c pattern
        if num == 0:
            # special case for 0 - can't meaningfully use division
            return create_addition_pattern(num, operand_count)
            
        divisor = safe_randint(2, 5)
        product = num * divisor
        
        if operand_count > 3:
            # break product into multiple parts
            parts = []
            remaining = product
            
            for i in range(operand_count - 2):
                if remaining <= 1:
                    parts.append(0)
                else:
                    part = safe_randint(1, remaining - 1)
                    parts.append(part)
                    remaining -= part
            
            parts.append(remaining)
            inner_expr = " + ".join(str(p) for p in parts)
            
            return f"( ({inner_expr}) / {divisor} )"
        else:
            a = safe_randint(1, product - 1)
            b = product - a
            return f"( ({a} + {b}) / {divisor} )"
    
    elif pattern_choice == 2:
        # (a - b) + c pattern
        if num >= 2:
            a_minus_b = safe_randint(1, num - 1)
            c = num - a_minus_b
            a = a_minus_b + safe_randint(1, 10)
            b = a - a_minus_b
            return f"( ({a} - {b}) + {c} )"
        else:
            # for 0 and 1, use simpler patterns
            return create_addition_pattern(num, operand_count)
    
    else:
        # nested operations
        if num == 0:
            # Special case for 0 - multiply by 0
            val = safe_randint(1, 10)
            return f"( ({val} - {val}) * {safe_randint(1, 5)} )"
        
        # ((a * b) + c) / d pattern
        divisor = safe_randint(1, 5)
        product = num * divisor
        
        if product > 2:
            factor = safe_randint(2, min(product - 1, 5))
            quotient = product // factor
            remainder = product - (factor * quotient)
            if remainder > 0:
                return f"( ({factor} * {quotient} + {remainder}) / {divisor} )"
            else:
                return f"( ({factor} * {quotient}) / {divisor} )"
        else:
            return f"( {product} / {divisor} )"
    
    # Fallback for any case not handled
    return create_addition_pattern(num, operand_count)