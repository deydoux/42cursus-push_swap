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
