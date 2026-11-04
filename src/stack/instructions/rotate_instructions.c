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
  benchmark_update(a->benchmark, OP_RA);
}

void rb(Stack *b)
{
  rotate(b);
  benchmark_update(b->benchmark, OP_RB);
}

void rr(Stack *a, Stack *b)
{
  ra(a);
  rb(b);
}

void rra(Stack *a)
{
  reverse_rotate(a);
  benchmark_update(a->benchmark, OP_RRA);
}

void rrb(Stack *b)
{
  reverse_rotate(b);
  benchmark_update(b->benchmark, OP_RRB);
}

void rrr(Stack *a, Stack *b)
{
  rra(a);
  rrb(b);
}
