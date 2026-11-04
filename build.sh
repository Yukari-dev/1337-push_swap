#!/bin/sh

# cc -Iinclude main.c src/stack/stack.c src/stack/instructions/swap_instructions.c src/stack/instructions/push_instructions.c src/stack/instructions/rotate_instructions.c && ./a.out
cc main.c src/algorithms/algorithms.c src/stack/stack.c src/stack/instructions/swap_instructions.c src/stack/instructions/push_instructions.c src/stack/instructions/rotate_instructions.c -Iinclude -I$HOME/lib/raylib/src -L$HOME/lib/raylib/src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 && ./a.out
