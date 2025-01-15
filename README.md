<div align="center">
  <img height="128" src="https://github.com/user-attachments/assets/162afe25-a123-48d5-b8e2-b5e365940997">
  <h1>push_swap</h1>
  <p>This project involves sorting data on a stack, with a limited set of instructions, and the smallest number of moves. To make this happen, you will have to manipulate various sorting algorithms and choose the most appropriate solution(s) for optimized data sorting.</p>
</div>

## About the project
The push_swap project is a challenging algorithmic task that requires implementing a sorting algorithm using two stacks (stack A and stack B) and a limited set of operations. The goal is to sort a random list of integers in ascending order using the minimum number of operations possible.

[Visualization.webm](https://github.com/user-attachments/assets/36dd6e68-f096-4280-b2c4-27ea9b6e2f68)
<p align="center"><em>100 elements sort visualization</em></p>

### Operations set
- **`sa`, `sb` and `ss`:** Swap the first 2 elements at the top of stack A, stack B or both
- **`pa`:** Push the first element at the top of stack B to stack A
- **`pb`:** Push the first element at the top of stack A to stack B
- **`ra`, `rb` and `rr`:** Rotate all elements up by one of stack A, stack B or both (the first element becomes the last one)
- **`rra`, `rrb` and `rrr`:** Rotate all elements down by one of stack A, stack B or both (the last element becomes the first one)

### Algorithm
I implemented an algorithm designed to sort the stack with a minimal number of operations. The algorithm is based on the following steps:
1. Divide **stack A** into 3 chunks and push them to **stack B**
    1. Calculate chunk size based on total elements
    2. For each chunk (starting from smallest numbers):
        - Find elements within chunk range using index comparison
        - Calculate optimal rotation direction (`ra` or `rra`)
        - Rotate **stack A** until target element is at top
        - Push element to **stack B** (`pb`)
        - Repeat until all chunk elements are moved
2. Handle remaining elements in **stack A**
    - If only 2-3 elements remain, sort them directly using `sa` if needed
3. Push elements back to **stack A** optimally
    1. For each push operation:
        - Scan **stack B** to find optimal element to push
        - Calculate total cost (rotations needed) for each possible move
        - Choose element requiring minimum combined rotations
        - Execute optimal rotations on both stacks simultaneously using `rr` or`rrr` when possible
        - Position chosen element at top using remaining individual rotations if needed (`ra`/`rra` and `rb`/`rrb`)
        - Push element to **stack A** (`pa`)
    2. Repeat until **stack B** is empty
4. Final rotations
    - Perform final rotations on **stack A** if needed to ensure smallest element is at top

### Skill learned
- **Algorithm Design:** Developed and optimized a complex sorting algorithm with specific constraints
- **Data Structures:** Deep understanding of stack operations and linked list manipulation
- **Optimization:** Learned to analyze and minimize algorithmic complexity and operation count
- **Problem Solving:** Breaking down a complex problem into manageable sub-problems
- **Code Organization:** Structuring code for maintainability and readability
- **Performance Analysis:** Evaluating and improving algorithm efficiency
- **Testing & Debugging:** Systematic testing and debugging of edge cases

## References
<img align="right" src="https://github.com/user-attachments/assets/b23ea7c1-e3fa-4900-ab91-a3f2fd6524a5">

- [42](https://42.fr/)
- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
