#include "stack/utils.h"

int find_position(Stack *stack, int value)
{
  Element *curr;
  int     position;

  if (is_empty(stack))
    return -1;
  position = 0;
  curr = stack->top;
  while (curr)
  {
    if (curr->data == value)
      return (position);
    position++;
    curr = curr->prev;
  }
  return (-1);
}

int find_position_under(Stack *stack, int value)
{
  Element *curr;
  int     position;

  if (is_empty(stack))
    return -1;
  position = 0;
  curr = stack->top;
  while (curr)
  {
    if (curr->data < value)
      return (position);
    position++;
    curr = curr->prev;
  }
  return (-1);
}
