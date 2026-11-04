#ifndef STACK_H
#define STACK_H
#include "benchmark/benchmark.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_Element{
  int data;
  int index;
  struct s_Element *next;
  struct s_Element *prev;
} Element;

typedef struct s_Stack{
  Element *start;
  Element *top;
  Benchmark *benchmark;
} Stack;

Element *create_element(int data, int index);
void  initialize_stack(Stack *stack);
void  clear_stack(Stack *stack);
void  rank_data(Stack *stack);
char is_empty(Stack *stack);

void  push(Stack *stack, int data, int index);
void  pop(Stack *stack);
int   size(Stack *stack);
int   find_min_position(Stack *stack);
int   find_max_rank_position(Stack *stack);

void iterate(Stack *stack, void (*f)(Element*));
void display_full_stack(Stack *stack);
void display_stack(Stack *stack);

double compute_disorder(Stack *stack);

#endif
