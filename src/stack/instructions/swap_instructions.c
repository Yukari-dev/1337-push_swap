#include "stack/instructions/swap.h"

void swap(t_Stack *stack)
{
  t_Element *top;
  t_Element *prev;
  int     data;

  if (is_empty(stack))
    return ;
  top = stack->top;
  prev = top->prev;
  data = top->data;
  top->data = prev->data;
  prev->data = data;
}

void sa(t_Stack *a)
{
  swap(a);
  benchmark_update(a->benchmark, OP_SA);
}

void sb(t_Stack *b)
{
  swap(b);
  benchmark_update(b->benchmark, OP_SB);
}

void ss(t_Stack *a, t_Stack *b)
{
  swap(a);
  swap(b);
}
