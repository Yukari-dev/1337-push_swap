#!/bin/sh

cc main.c src/algorithms/algorithms.c src/benchmark/benchmark.c src/stack/stack.c src/stack/instructions/swap_instructions.c src/stack/instructions/push_instructions.c src/stack/instructions/rotate_instructions.c -Iinclude -o push_swap && ./push_swap
