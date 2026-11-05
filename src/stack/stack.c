#include "stack/stack.h"

t_Element *create_element(int data, int index)
{
  t_Element *element = (t_Element *)malloc(sizeof(t_Element));
  if (!element)
    return (NULL);
  element->data = data;
  element->index = index;
  element->next = NULL;
  element->prev = NULL;
  return element;
}

void  initialize_stack(t_Stack *stack)
{
  stack->start = NULL;
  stack->top = NULL;
  stack->benchmark = NULL;
}

void clear_stack(t_Stack *stack)
{
  t_Element *curr;
  t_Element *saved;

  if (is_empty(stack))
    return ;
  curr = stack->top;
  while (curr)
  {
    saved = curr->prev;
    free(curr);
    curr = saved;
  }
  stack->start = NULL;
  stack->top = NULL;
}

void  rank_data(t_Stack *stack)
{
  t_Element *curr;
  t_Element *next;
  int     rank;

  if (is_empty(stack))
    return ;
  curr = stack->top;
  while (curr)
  {
    rank = 0;
    next = stack->top;
    while (next)
    {
      if (next->data < curr->data)
        rank++;
      next = next->prev;
    }
    curr->index = rank;
    curr = curr->prev;
  }
}

void  push(t_Stack *stack, int data, int index)
{
  t_Element *element = create_element(data, index);
  if (!element)
    return ;
  if (is_empty(stack))
  {
    stack->start = element;
    stack->top = element;
  }
  else{
    stack->top->next = element;
    element->prev = stack->top;
    stack->top = element;
  }
  // printf("Pushed element: %d to the stack\n", data);
}

void  pop(t_Stack *stack)
{
  t_Element *element;

  element = stack->top;
  if (is_empty(stack))
    return ;
  else if (stack->top == stack->start)
  {
    stack->start = NULL;
    stack->top = NULL;
  }
  else
  {
    stack->top->prev->next = NULL;
    stack->top = element->prev;
  }
  // printf("Popped element: %d from the stack\n", element->data);
  free(element);
}

int size(t_Stack *stack)
{
  t_Element *curr;
  int size;
  
  if (is_empty(stack))
    return (0);
  curr = stack->start;
  size = 0;
  while (curr)
  {
    size++;
    curr = curr->next;
  }
  return (size);
}

int find_min_position(t_Stack *stack)
{
  t_Element *curr;
  int position;
  int smallest_position;
  int smallest;

  if (is_empty(stack))
    return (-1);
  position = 0;
  curr = stack->top;
  smallest = curr->data;
  smallest_position = 0;
  while (curr)
  {
    if (curr->data < smallest)
    {
      smallest_position = position;
      smallest = curr->data;
    }
    position++;
    curr = curr->prev;
  }
  return (smallest_position);
}

int   find_max_rank_position(t_Stack *stack)
{
  t_Element *curr;
  int position;
  int largest_position;
  int largest;

  if (is_empty(stack))
    return (-1);
  position = 0;
  curr = stack->top;
  largest = -1;
  largest_position = 0;
  while (curr)
  {
    if (curr->index > largest)
    {
      largest_position = position;
      largest = curr->index;
    }
    position++;
    curr = curr->prev;
  }
  return (largest_position);
}

char is_empty(t_Stack *stack)
{
  return (stack->start == NULL); 
}

void iterate(t_Stack *stack, void (*f)(t_Element*))
{
  t_Element *curr;

  curr = stack->top;
  while (curr)
  {
    f(curr);
    curr = curr->prev;
  }
}

double compute_disorder(t_Stack *stack)
{
  t_Element *curr;
  t_Element *next;
  long     total_pairs;
  long     mistakes;

  total_pairs = 0;
  mistakes = 0;
  curr = stack->top;
  while (curr)
  {
    next = curr->prev;
    while (next)
    {
      total_pairs++;
      if (curr->data > next->data)
        mistakes++;
      next = next->prev;
    }
    curr = curr->prev;
  }
  if (total_pairs == 0)
    return 0;
  return ((double)mistakes / total_pairs);
}

static void full_display(t_Element *element){
  printf("|-t_Element Data:  | %-4d|\n", element->data);
  printf("|-t_Element Index: |  %-3d|\n", element->index);
}

static void display(t_Element *element){
  printf("|-t_Element Data:  | %-4d|\n", element->data);
}

void display_full_stack(t_Stack *stack)
{
  printf("\n-----------------\n");
  if (stack->top)
    printf("top element: %d\n", stack->top->data);
  iterate(stack, full_display);
}

void display_stack(t_Stack *stack)
{
  printf("\n-----------------\n");
  if (stack->top)
    printf("top element: %d\n", stack->top->data);
  iterate(stack, display);
}

