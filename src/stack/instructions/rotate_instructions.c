#include "stack/instructions/rotate.h"

void rotate(Stack *stack)
{
  Element *first;

  if (is_empty(stack) || !stack->top || !stack->top->prev)
    return ;
  first = stack->top;
  stack->top = first->prev;
  first->prev = NULL;
  stack->top->next = NULL;
  first->next = stack->start;
  stack->start->prev = first;
  stack->start = first;
}

void  reverse_rotate(Stack *stack)
{
  Element *last;

  if (is_empty(stack) || !stack->start || !stack->start->next)
    return ;
  last = stack->start;
  stack->start = last->next;
  last->next = NULL;
  stack->start->prev = NULL;
  last->prev = stack->top;
  stack->top->next = last;
  stack->top = last;
}

void ra(Stack *a)
{
  rotate(a);
}

void rb(Stack *b)
{
  rotate(b);
}

void rr(Stack *a, Stack *b)
{
  ra(a);
  rb(b);
}

void rra(Stack *a)
{
  reverse_rotate(a);
}

void rrb(Stack *b)
{
  reverse_rotate(b);
}

void rrr(Stack *a, Stack *b)
{
  rra(a);
  rrb(b);
}
