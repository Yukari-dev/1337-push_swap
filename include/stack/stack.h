#ifndef STACK_H
#define STACK_H
#include <stdlib.h>
#include <stdio.h>

typedef struct s_Element{
  int data;
  struct s_Element *next;
  struct s_Element *prev;
} Element;

typedef struct s_Stack{
  Element *start;
  Element *top;
} Stack;

Element *create_element(int data);
void initialize_stack(Stack *stack);
char is_empty(Stack *stack);

void  push(Stack *stack, int data);
void  pop(Stack *stack);
int   size(Stack *stack);
int   find_min_position(Stack *a);

void iterate(Stack *stack, void (*f)(Element*));
void display_stack(Stack *stack);

double compute_disorder(Stack *stack);

#endif
