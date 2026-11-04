#include "algorithms/algorithms.h"
#include "stack/instructions/push.h"
#include "stack/instructions/rotate.h"

static void rotate_till(Stack *stack, int times, int side)
{
  while (times > 0)
  {
    if (side == 1)
      ra(stack);
    else
      rra(stack);
    times--;
  }
}

void  selection_sort(Stack *a, Stack *b)
{
  Element *curr;
  int     smallest_p;
  int     a_size;
  
  if (is_empty(a))
    return ;
  while (!is_empty(a))
  {
    a_size = size(a);
    smallest_p = find_min_position(a);
    if (smallest_p <= a_size / 2)
      rotate_till(a, smallest_p, 1);
    else
      rotate_till(a, a_size - smallest_p, -1);
    pb(b, a);
  }

  while (!is_empty(b))
    pa(a, b);
}

void  insertion_sort(Stack *a, Stack *b)
{
  Element *curr;

  if (is_empty(a))
    return ;

  while (!is_empty(a))
  {
    
  }
}
