#include "algorithms/algorithms.h"
#include "stack/instructions/swap.h"
#include "stack/instructions/push.h"
#include "stack/instructions/rotate.h"

static void rotate_till(Stack *stack, int times, void (*rotate)(Stack *stack))
{
  while (times > 0)
  {
    rotate(stack);
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
      rotate_till(a, smallest_p, ra);
    else
      rotate_till(a, a_size - smallest_p, rra);
    pb(b, a);
  }

  while (!is_empty(b))
    pa(a, b);
}

void  bubble_sort(Stack *a)
{
  Element *curr;
  int     stack_size;
  int     i;
  int     swapped;

  if (is_empty(a))
    return ;
  stack_size = size(a);
  while (1)
  {
    swapped = 0;
    i = 0;
    while (i < stack_size - 1)
    {
      if (a->top->data > a->top->prev->data)
      {
        sa(a);
        swapped = 1;
      }
      ra(a);
      i++;
    }

    ra(a);
    if (!swapped)
      break;
  }
}

void  chunk_sort(Stack *a, Stack *b, int chunk_size)
{
  int pushed_count;
  int top_rank;
  int largest_rank;
  int b_size;

  if (is_empty(a))
    return ;
  pushed_count = 0;
  while (!is_empty(a))
  {
    top_rank = a->top->index;
    if (top_rank <= pushed_count)
    {
      pb(b, a);
      rb(b);
      pushed_count++;
    }
    else if (top_rank <= pushed_count + chunk_size)
    {
      pb(b, a);
      pushed_count++;
    }
    else
      ra(a);
  }
  while (!is_empty(b))
  {
    largest_rank = find_max_rank_position(b);
    b_size = size(b);
    if (largest_rank <= b_size / 2)
      rotate_till(b, largest_rank, rb);
    else
      rotate_till(b, b_size - largest_rank, rrb);
    pa(a, b);
  }
}
