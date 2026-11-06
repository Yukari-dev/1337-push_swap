*This project has been created as part of the 42 curriculum by maoulad, ibelkaid.*

## Description
This project was made to dynamically sort the given input of the program in ascending order, using only 2 stacks:
- stack `A`: the main stack that initializes using the input.
- stack `B`: an empty stack that acts like a workspace, used to help the sorting process

### Sorting process:
The program sorts dynamically based on the given flag or on the disorder of the input:

- **Disorder lower than 20%:**: The program uses a slow but simple sorting algorithm (`O(n²)`).

- **Disorder between 20% and 50%:** The program uses a medium sorting algorithm (`O(n√n)`).

- **Disorder greater is equals 50%:**: The program uses a complex sorting algorithm (`O(n log n)`).

### Instructions used:
All sorting algorithms included aer limited to only using a set of instructions to move elements around, they can be concluded in following base instruction:
- **Swap:** Swap the first and second elements of a stack.
- **Push:** Take an element from a given stack and push it into the target stack.
- **Rotate:** Shifts the stack elements upwards (top element moves to the bottom).
- **Reverse Rotate:** Shifts the stack elements downwards (bottom element moves to the top).

The instructions are:
| Name | Base Instruction | Target |
| :--: | :-- | :-- |
| `sa` | Swap | Stack `A` |
| `sb` | Swap | Stack `B` |
| `ss` | Swap | Stack `A` and `B` |
| `pa` | Push | Stack `A` |
| `pb` | Push | Stack `B` |
| `ra` | Rotate | Stack `A` |
| `rb` | Rotate | Stack `B` |
| `rr` | Rotate | Stack `A` and `B` |
| `rra` | Reverse Rotate | Stack `A` |
| `rrb` | Reverse Rotate | Stack `B` |
| `rrr` | Reverse Rotate | Stack `A` and `B` |

### Sorting algorithms:
- **Simple sorting**: Selection sort. Iterates through the stack to find the minimum elements and moves them systematically. Chosen for its ultra-low overhead on tiny or nearly sorted inputs (O(n²)), avoiding the complex partitioning penalty when element counts are very low.

- **Medium sorting**: Chunk-based sorting. Divides the input range into dynamic value brackets ("chunks") and pushes them across stacks to narrow down the operational scope. Chosen for mid-range disorder (O(n√n)), striking an ideal balance between execution speed and instruction count without heavy divide-and-conquer overhead.

- **Complex sorting**: Radix sort. Processes elements bit-by-bit across their binary representations, shifting numbers between stacks based on bit values from least to most significant. Chosen for high disorder (O(n log n)), offering predictable, hyper-efficient scaling and outperforming standard comparison sorts on large, highly scrambled datasets.

### Checker:
The checker is a separate program that takes the given numbers and a list of instructions (or the output of `./push_swap`) and prints `OK` into `stdout` if the instructions given does sort the stack, or `KO` if it doesn't.
### Bench marking:
Prints information about sorting process (initial disorder, strategy used, total instructions count, each instruction count) into `stderr`.

## Instructions
To use the program, simply run:
```bash
make 		# to compile
make fclean # to remove the program
make re		# to recompile
make bonus  # to compile the checker
```

And now you can feed the program numbers directly to use adaptive sorting:
```bash
./push_swap 7 8 5 -21 6 +5 
```
Or use the given flags:
```bash
./push_swap --simple   [...] # Forces the program to use a simple sorting algorithm.
./push_swap --medium   [...] # Forces the program to use a medium sorting algorithm.
./push_swap --complex  [...] # Forces the program to use a complex sorting algorithm.
./push_swap --adaptive [...] # The default strategy, adapts based on the input.
./push_swap --bench	   [...] # Displays bench marking.
```
The output is all the instruction names as they run into `stdout`.

A few examples:
```bash
$> ./push_swap --simple 5 4 3 2 1
rra
pb
rra
pb
rra
pb
ra
pb
pb
pa
pa
pa
pa
pa
```
```bash
$> ARGS=(shuf -i 0-9999 -n 500); ./push_swap $ARGS | wc -l
6784
```
Bench marking example:
```bash
$> ARGS=(shuf -i 0-9999 -n 500); ./push_swap --bench $ARGS 2> bench.txt | wc -l 
7997
$> cat bench.txt
[bench] disorder:  49.93%
[bench] strategy:  Adaptive / O(n√n)
[bench] total_ops:  7997
[bench] sa:  0  sb:  0  ss:  0  pa:  500  pb:  500  
[bench] ra:  4840  rb:  1098  rr:  0  rra:  0  rrb:  1059  rrr: 0
```
Checker example:
```bash
$> ARGS=$(shuf -i 0-9999 -n 500) > args.txt; ./push_swap --complex $ARGS | ./checker $ARGS
OK
```
In case of an error:
```bash
$> ./push_swap
Error
$> ./push_swap --invalid 1 2 3
Error
$> ./push_swap a b c
Error
```

## Resources:
* [Visualgo](https://visualgo.net/en/sorting?utm_source=chatgpt.com)
### AI USAGE:
* AI was only used to understand sorting algorithms and for testing.