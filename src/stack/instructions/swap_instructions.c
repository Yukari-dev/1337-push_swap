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
}

void sb(Stack *b)
{
  swap(b);
}

void ss(Stack *a, Stack *b)
{
  swap(a);
  swap(b);
}
