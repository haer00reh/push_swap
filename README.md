### Introduction
The Push swap project is a simple yet highly structured algorithmic challenge: you
need to sort data.
You have at your disposal a set of integer values, 2 stacks, and a set of instructions to
manipulate both stacks.
Your goal? Write a C program called push_swap that calculates and displays the
shortest sequence of Push_swap instructions needed to sort the given integers.
Easy?
We’ll see...
---

*This project has been created as part of the 42 curriculum by haer-reh.*

# Push_swap

## Description
Push_swap sorts a list of integers on a stack using a constrained set of stack operations (swap, push, rotate, reverse rotate). The goal is to produce a valid sequence of operations that sorts the numbers in ascending order while minimizing the total number of operations. The project includes a checker program to validate operation sequences and ensure the stacks end sorted.

## Instructions
- **Clone & build**
	- `make` builds `push_swap`
	- `make bonus` builds `checker`
- **Run**
	- `./push_swap 2 1 3 6 5 8` prints a sequence of operations to stdout
	- `./push_swap 3 2 1 | ./checker 3 2 1` validates the sequence and outputs `OK` or `KO`
- **Clean**
	- `make clean` removes objects; `make fclean` removes binaries; `make re` rebuilds from scratch

## Resources
- Stack operations refresher: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
- Longest Increasing Subsequence concept: https://cp-algorithms.com/sequences/longest_increasing_subsequence.html
- get_next_line and libft references: prior 42 projects

**AI usage**: AI (GPT-5.1) was used for drafting explanations, spotting norminette/style issues. All algorithm design, code decisions, and testing were performed by the author haer-reh.
