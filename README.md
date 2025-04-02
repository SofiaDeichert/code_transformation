# Code Transformation Project

## Dependencies

- Python 3.6+
- tree-sitter
- tree-sitter-cpp

```bash
pip install tree-sitter
pip install tree-sitter-cpp
git clone https://github.com/tree-sitter/tree-sitter-cpp.git
```

## How to Run

1. Open `transform_ast.py` and uncomment the transformations you want to apply:

```python
transformations = [
    # (apply_return_type_deduction, "return_type_deduction"),
    (apply_increment_to_assignment_transformation, "increment_to_assignment"),
    # (apply_assignment_to_increment_transformation, "assignment_to_increment"),
    # ...
]
```

2. Run the pipeline:

```bash
python transformation_pipeline.py
```

3. Enter the input JSONL filename when prompted (e.g., `test 1.jsonl`)

4. Transformed JSONL files will be available in the `pipeline_output` directory