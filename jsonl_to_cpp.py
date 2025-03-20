# Sofia Deichert - Code Transformation Project
# Takes jsonl file input and puts it into separate .cpp files

import json
import os


def process_jsonl_file(input_file, output_dir):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)

    try:
        with open(input_file, 'r', encoding='utf-8') as f:
            # process files for all IDs
            for line in f:
                try:
                    data = json.loads(line.strip())  # parse JSON line

                    # check if ID in desired range
                    if 0 <= data['id'] <= 6763:
                        # create filename w/ ID using 4 digits
                        output_file = os.path.join(output_dir, f'code_{data["id"]:04d}.cpp')

                        # write code to .cpp file with newlines replaced
                        with open(output_file, 'w', encoding='utf-8') as cpp_file:
                            # preserve the \n character
                            fixed_input = data['input'].replace('\n', '\\n')
                            cpp_file.write(fixed_input)

                        # print(f"Created file: {output_file}")

                except json.JSONDecodeError as e:
                    print(f"Error parsing JSON line: {e}")
                except KeyError as e:
                    print(f"Missing required key in JSON: {e}")
                except Exception as e:
                    print(f"Error processing line: {e}")

    except FileNotFoundError:
        print(f"Input file not found: {input_file}")
    except Exception as e:
        print(f"Error reading input file: {e}")


input_file = 'test 1.jsonl'
output_directory = 'extracted_code'

process_jsonl_file(input_file, output_directory)