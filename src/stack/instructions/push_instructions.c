#include "stack/instructions/push.h"

void pa(t_Stack *a, t_Stack *b)
{
  if (is_empty(b))
    return ;
  if (b->top)
  {
    push(a, b->top->data, b->top->index);
    pop(b);
    benchmark_update(a->benchmark, OP_PA);
  }
}

void pb(t_Stack *b, t_Stack *a)
{
  if (is_empty(a))
    return ;
  if (a->top)
  {
    push(b, a->top->data, a->top->index);
    pop(a);
    benchmark_update(b->benchmark, OP_PB);
  }
}
