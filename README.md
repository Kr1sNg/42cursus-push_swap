# Push_swap 🔁 because Swap_push isn't as natural

## 📢 Introduction
This is the 42's project ***Push Swap***, about sorting data on a stack, with a set of limited instructions, using the lowest possible number of actions. It requires the manipulation of various types of sorting algorithms and resolving problems.

![image](https://github.com/user-attachments/assets/f80d9469-c400-4c60-bfbd-99e63ec4052f)


### 🎯 Requirement
In the beginning, we have 2 stacks named ***a***  and ***b***. Stack ***a*** contains a random amount of negative and/or positive numbers that cannot be duplicated, while stack ***b*** is empty.

The goal is to sort all numbers in stack ***a*** in ascending order using limited movement instruction.

### ♟ Set of instruction
- `sa` (swap ***a***): Swap the first 2 elements at the top of stack ***a***. Do nothing if there is only one or no element.
- `sb` (swap ***b***): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no element.
- `ss` (swap ***a*** and ***b***): Do `sa` and `sb` at the same time.
- `pa` (push ***a***): Take the first element at the top of ***b*** and put it at the top of ***a***. Do nothing if ***b*** is empty.
- `pb` (push ***b***): Take the first element at the top of ***a*** and put it at the top of ***b***. Do nothing if ***a*** is empty.
- `ra` (rotate ***a***): Shift up all elements of stack ***a*** by 1. The first element becomes the last one.
- `rb` (rotate ***b***): Shift up all elements of stack ***b*** by 1. The first element becomes the last one.
- `rr` (rotate ***a*** and ***b***): Do `ra` and `rb` at the same time.
- `rra` (reverse rotate ***a***): Shift down all elements of stack ***a*** by 1. The last element becomes the first one.
- `rrb` (reverse rotate ***b***): Shift down all elements of stack ***b*** by 1. The last element becomes the first one.
- `rrr` (reverse rotate ***a*** and ***b***): Do `rra` and `rrb` at the same time.

---
## 🔬 Sorting Algorithm
Due to the requirements of the minimum number of actions we could use to sort, [the Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97), which was introduced by A. Yigit Ogun (student of 42 Heilbronn), was chosen to apply in this project.

---
## 🧪 Run and Test
### 1. push_swap ♻️
In the folder **push_swap**, run the command to compile program `push_swap`
```
make
```
Create a list of `n` integers with `python3`
```
import random
print(*random.sample(range(-42000, 42000), <put n here>), end=' ')
```
Run the tests with 100, 500, or any number of random integers
```
ARG="<paste the list of random integers here>"; ./push_swap $ARG
```
`push_swap` will display the list of instructions used to sort the list of random integers.

`Error` will be displayed in case there is a problem with the input

> - non-numeric parameters
> - duplicate numeric parameters
> - parameters including numbers greater than MAXINT or smaller than MININT
> - etc

To count how many instructions were returned, add pipeline to `wc -l` and run
```
ARG="<paste the list of random integers here>"; ./push_swap $ARG | wc -l
```

### 2. checker ✔️
In the same folder of `push_swap`, run the command to compile the program `checker`
```
make bonus
```
Run checker with command
```
./checker <list of random integers>
<list of instructions>
<line>
<by>
<line>
```
To stop input instructions, use `Ctrl` + `D`

`checker` will display `OK` for the valid instruction list, `KO` for invalid, or `Error` in case there's a problem within the input.

---
## 💯 Result
- [x] less than 700 movements for a list of 100 random numbers
- [x] less than 5500 movements for a list of 500 random numbers
- [x] no leak found for both `push_wap` and `checker` in any manner of input parameters
> - `./push_swap 42 1 3`
> - `./push_swap "42 1 3"`
> - `./checker 42 1 3`
> - `./checker "42 1 3"`

---
## 🐛 Issues and Bugs
Please feel free to create a new issue with its title and description on the `issues` page of this [42cursus-push_swap](https://github.com/Kr1sNg/42cursus-push_swap/) repository. If you have already found the solution to the problem, I would love to review your `pull request`!

---
#### References:
- [Turk Algorithm by A. Yigit Ogun](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)
- [Explanation of Push_swap by Thuggonaut](https://www.youtube.com/watch?v=wRvipSG4Mmk)
