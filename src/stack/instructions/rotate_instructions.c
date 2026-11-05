#include "stack/instructions/rotate.h"

void rotate(t_Stack *stack)
{
  t_Element *first;

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

void  reverse_rotate(t_Stack *stack)
{
  t_Element *last;

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

void ra(t_Stack *a)
{
  rotate(a);
  benchmark_update(a->benchmark, OP_RA);
}

void rb(t_Stack *b)
{
  rotate(b);
  benchmark_update(b->benchmark, OP_RB);
}

void rr(t_Stack *a, t_Stack *b)
{
  rotate(a);
  rotate(b);
  benchmark_update(a->benchmark, OP_RR);
  benchmark_update(b->benchmark, OP_RR);
}

void rra(t_Stack *a)
{
  reverse_rotate(a);
  benchmark_update(a->benchmark, OP_RRA);
}

void rrb(t_Stack *b)
{
  reverse_rotate(b);
  benchmark_update(b->benchmark, OP_RRB);
}

void rrr(t_Stack *a, t_Stack *b)
{
  reverse_rotate(a);
  reverse_rotate(b);
  benchmark_update(a->benchmark, OP_RRR);
  benchmark_update(b->benchmark, OP_RRR);
}
