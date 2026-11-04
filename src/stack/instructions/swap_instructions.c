#include "stack/instructions/swap.h"

void swap(Stack *stack)
{
  Element *top;
  Element *prev;
  int     data;

  if (is_empty(stack))
    return ;
  top = stack->top;
  prev = top->prev;
  data = top->data;
  top->data = prev->data;
  prev->data = data;
}

void sa(Stack *a)
{
  swap(a);
  benchmark_update(a->benchmark, OP_SA);
}

void sb(Stack *b)
{
  swap(b);
  benchmark_update(b->benchmark, OP_SB);
}

void ss(Stack *a, Stack *b)
{
  swap(a);
  swap(b);
}
