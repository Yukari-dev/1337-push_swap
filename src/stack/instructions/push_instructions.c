#include "stack/instructions/push.h"

void pa(Stack *a, Stack *b)
{
  if (is_empty(b))
    return ;
  if (b->top)
  {
    push(a, b->top->data);
    pop(b);
  }
}

void pb(Stack *b, Stack *a)
{
  if (is_empty(a))
    return ;
  if (a->top)
  {
    push(b, a->top->data);
    pop(a);
  }
}
