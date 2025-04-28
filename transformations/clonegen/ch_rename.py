# Sofia Deichert - Code Transformation Project
# ch-rename: function name and variable renaming

import json
import copy
import os

# transforms all function and variable names
def transform_names(ast_node):
    # deep copy to avoid modifying original
    modified_ast = copy.deepcopy(ast_node)
    
    # find all identifier nodes that need renaming
    identifiers = find_identifiers(modified_ast)
    
    # nothing to change
    if not identifiers:
        return modified_ast
    
    # get root text - modify this directly
    root_text = modified_ast["text"]
    
    # process transformations in reverse order (to avoid position shifting issues)
    # sort by start position so deeper nested identifiers get renamed first
    for identifier in sorted(identifiers, key=lambda x: x["start_byte"], reverse=True):
        # get original name and positions
        original_name = identifier["text"]
        start_pos = identifier["start_byte"]
        end_pos = identifier["end_byte"]
        
        # skip standard library functions and keywords
        if original_name in [
        
    # C/C++ keywords
    "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", "break", 
    "case", "catch", "char", "char8_t", "char16_t", "char32_t", "class", "compl", "concept", 
    "const", "consteval", "constexpr", "constinit", "const_cast", "continue", "co_await", 
    "co_return", "co_yield", "decltype", "default", "delete", "do", "double", "dynamic_cast", 
    "else", "enum", "explicit", "export", "extern", "false", "float", "for", "friend", "goto", 
    "if", "inline", "int", "long", "mutable", "namespace", "new", "noexcept", "not", "not_eq", 
    "nullptr", "operator", "or", "or_eq", "private", "protected", "public", "register", 
    "reinterpret_cast", "requires", "restrict", "return", "short", "signed", "sizeof", "static", 
    "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local", 
    "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", 
    "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq", "_Alignas", "_Alignof", 
    "_Atomic", "_Bool", "_Complex", "_Generic", "_Imaginary", "_Noreturn", "_Static_assert", 
    "_Thread_local",
    
    # Special function names
    "main",
    
    # C standard library - stdio.h
    "printf", "fprintf", "sprintf", "snprintf", "vprintf", "vfprintf", "vsprintf", "vsnprintf",
    "scanf", "fscanf", "sscanf", "vscanf", "vfscanf", "vsscanf", "fgetc", "fgets", "fputc", 
    "fputs", "getc", "getchar", "gets", "putc", "putchar", "puts", "ungetc", "fread", "fwrite",
    "fopen", "fclose", "fflush", "freopen", "setbuf", "setvbuf", "fseek", "ftell", "rewind",
    "fgetpos", "fsetpos", "clearerr", "feof", "ferror", "perror", "remove", "rename", "tmpfile",
    "tmpnam",
    
    # C standard library - stdlib.h
    "atof", "atoi", "atol", "atoll", "strtod", "strtof", "strtol", "strtold", "strtoll", 
    "strtoul", "strtoull", "rand", "srand", "calloc", "free", "malloc", "realloc", "abort", 
    "atexit", "exit", "_Exit", "getenv", "system", "bsearch", "qsort", "abs", "div", "labs", 
    "ldiv", "llabs", "lldiv", "mblen", "mbtowc", "wctomb", "mbstowcs", "wcstombs",
    
    # C standard library - string.h
    "memcpy", "memmove", "memchr", "memcmp", "memset", "strcat", "strncat", "strchr", "strcmp",
    "strncmp", "strcoll", "strcpy", "strncpy", "strspn", "strcspn", "strerror", "strlen", 
    "strpbrk", "strrchr", "strstr", "strtok", "strxfrm",
    
    # C standard library - math.h
    "cos", "sin", "tan", "acos", "asin", "atan", "atan2", "cosh", "sinh", "tanh", "acosh", 
    "asinh", "atanh", "exp", "frexp", "ldexp", "log", "log10", "modf", "exp2", "expm1", "log1p", 
    "log2", "logb", "pow", "sqrt", "cbrt", "hypot", "erf", "erfc", "lgamma", "tgamma", "ceil", 
    "floor", "fmod", "trunc", "round", "lround", "llround", "rint", "lrint", "llrint", 
    "nearbyint", "remainder", "remquo", "copysign", "nan", "nextafter", "nexttoward", "fdim", 
    "fmax", "fmin", "fabs", "fma",
    
    # C standard library - time.h
    "clock", "difftime", "mktime", "time", "asctime", "ctime", "gmtime", "localtime", "strftime",
    
    # C standard library - ctype.h
    "isalnum", "isalpha", "isblank", "iscntrl", "isdigit", "isgraph", "islower", "isprint", 
    "ispunct", "isspace", "isupper", "isxdigit", "tolower", "toupper",
    
    # C standard library - signal.h
    "signal", "raise",
    
    # C standard library - setjmp.h
    "longjmp", "setjmp",
    
    # C standard library - assert.h
    "assert",
    
    # C standard library - errno.h
    "errno",
    
    # C++ standard library - input/output stream
    "cin", "cout", "cerr", "clog", "endl", "ends", "flush", "ws", "dec", "hex", "oct", "fixed", 
    "scientific", "boolalpha", "noboolalpha", "showbase", "noshowbase", "showpoint", 
    "noshowpoint", "showpos", "noshowpos", "skipws", "noskipws", "uppercase", "nouppercase", 
    "unitbuf", "nounitbuf", "internal", "left", "right", "setw", "setfill", "setprecision", 
    "setiosflags", "resetiosflags", "setbase", "get", "getline", "ignore", "peek", "read", 
    "gcount", "seekg", "seekp", "tellg", "tellp", "write", "put", "width", "fill", "precision", 
    "flags", "setf", "unsetf", "good", "eof", "fail", "bad", "clear", "sync", "open", "close",
    
    # C++ standard library - string
    "append", "assign", "at", "back", "begin", "capacity", "cbegin", "cend", "clear", "compare",
    "copy", "crbegin", "crend", "c_str", "data", "empty", "end", "erase", "find", "find_first_not_of",
    "find_first_of", "find_last_not_of", "find_last_of", "front", "insert", "length", "max_size",
    "pop_back", "push_back", "rbegin", "rend", "replace", "reserve", "resize", "shrink_to_fit",
    "size", "substr", "swap",
    
    # C++ standard library - container and algorithm
    "accumulate", "adjacent_difference", "adjacent_find", "all_of", "any_of", "back_inserter",
    "binary_search", "copy_if", "copy_n", "count", "count_if", "equal", "equal_range", "fill",
    "fill_n", "find_if", "find_if_not", "for_each", "front_inserter", "generate", "generate_n",
    "includes", "inplace_merge", "inserter", "is_heap", "is_sorted", "iter_swap", "lexicographical_compare",
    "lower_bound", "make_heap", "max", "max_element", "merge", "min", "min_element", "minmax",
    "minmax_element", "mismatch", "move", "next_permutation", "none_of", "nth_element", "partial_sort",
    "partial_sort_copy", "partition", "pop_heap", "prev_permutation", "push_heap", "random_shuffle",
    "remove", "remove_copy", "remove_copy_if", "remove_if", "replace", "replace_copy", "replace_copy_if",
    "replace_if", "reverse", "reverse_copy", "rotate", "rotate_copy", "search", "search_n", "set_difference",
    "set_intersection", "set_symmetric_difference", "set_union", "shuffle", "sort", "sort_heap",
    "stable_partition", "stable_sort", "swap_ranges", "transform", "unique", "unique_copy", "upper_bound",
    
    # C++ standard library - memory management
    "allocate", "allocate_shared", "allocator", "construct", "deallocate", "default_delete", 
    "destroy", "get_deleter", "get_temporary_buffer", "make_shared", "make_unique", "owner_less",
    "raw_storage_iterator", "return_temporary_buffer", "shared_ptr", "unique_ptr", "weak_ptr",
    
    # C++ standard library - functional
    "bind", "function", "hash", "invoke", "is_bind_expression", "is_placeholder", "mem_fn", 
    "not1", "not2", "plus", "minus", "multiplies", "divides", "modulus", "negate", "equal_to",
    "not_equal_to", "greater", "less", "greater_equal", "less_equal", "logical_and", "logical_or",
    "logical_not", "bit_and", "bit_or", "bit_xor", "bit_not", 
    
    # C++ standard library - threading
    "thread", "mutex", "timed_mutex", "recursive_mutex", "recursive_timed_mutex", "lock_guard",
    "unique_lock", "shared_lock", "condition_variable", "condition_variable_any", "notify_all_at_thread_exit",
    "cv_status", "promise", "packaged_task", "future", "shared_future", "async", "launch", "future_status",
    "future_error", "future_category"
]:
            continue
            
        # create new name
        new_name = original_name + '_new'
        
        # replace in root text
        root_text = root_text[:start_pos] + new_name + root_text[end_pos:]
    
    # update AST root text with all transformations applied
    modified_ast["text"] = root_text
    
    return modified_ast

# recursively find all identifier nodes that should be renamed
def find_identifiers(ast_node, results=None):
    if results is None:
        results = []
    
    # check if this node is an identifier that should be renamed
    if ast_node["type"] == "identifier":
        # add to results
        results.append(ast_node)
    
    # recursively search children
    for child in ast_node.get("children", []):
        find_identifiers(child, results)
    
    return results

# transforms single AST file, renaming all variables and functions
def transform_file(input_ast_path, output_ast_path):
    try:
        # Load AST from file
        with open(input_ast_path, 'r', encoding='utf-8') as f:
            ast = json.load(f)
        
        # Apply transformation
        modified_ast = transform_names(ast)
        
        # Save modified AST
        with open(output_ast_path, 'w', encoding='utf-8') as f:
            json.dump(modified_ast, f, indent=2)
                    
    except Exception as e:
        print(f"Error transforming {input_ast_path}: {e}")
        # Log full error traceback for debugging
        import traceback
        print(traceback.format_exc())

def transform_directory(input_dir, output_dir):
    # Create output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)
    
    # Process each AST file in input directory
    for filename in os.listdir(input_dir):
        if filename.endswith('.json'):
            input_path = os.path.join(input_dir, filename)
            output_path = os.path.join(output_dir, filename)
            transform_file(input_path, output_path)


def apply_ch_rename_transformation(input_dir, output_dir):
    transform_directory(input_dir, output_dir)