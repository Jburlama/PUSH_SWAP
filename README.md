![image](https://github.com/user-attachments/assets/0f2c1510-430f-4f83-9cff-deee38b08391)

# Challenge

1. Sort a random list of integers using the smallest number of moves, 2 stacks, and a limited set of operations.
2. You start with two empty stacks: a and b. You are given a random list of integers via command line arguments.

3. Only these moves are allowed:

    - sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
    - sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
    - ss : sa and sb at the same time.
    - pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
    - pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
    - ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
    - rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
    - rr : ra and rb at the same time.
    - rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
    - rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
    - rrr : rra and rrb at the same time.

4. At the end, stack b must empty empty and all integers must be in stack a, sorted in ascending order.
-------------------------

**Push_Swap** must conform to the [42 Norm](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf).

**Install** [norminette](https://github.com/42School/norminette).

# Credits

I was able to make this project thanks to the help of [A. Yigit Ogun](https://github.com/ayogun) blog's post about the [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).
