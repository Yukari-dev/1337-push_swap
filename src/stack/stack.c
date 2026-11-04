#include "stack/stack.h"

Element *create_element(int data)
{
  Element *element = (Element *)malloc(sizeof(Element));
  if (!element)
    return (NULL);
  element->data = data;
  element->next = NULL;
  element->prev = NULL;
  return element;
}

void  initialize_stack(Stack *stack)
{
  stack->start = NULL;
  stack->top = NULL;
}

void  push(Stack *stack, int data)
{
  Element *element = create_element(data);
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

void  pop(Stack *stack)
{
  Element *element;

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

int size(Stack *stack)
{
  Element *curr;
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

int find_min_position(Stack *stack)
{
  Element *curr;
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

char is_empty(Stack *stack)
{
  return (stack->start == NULL); 
}

void iterate(Stack *stack, void (*f)(Element*))
{
  Element *curr;

  curr = stack->top;
  while (curr)
  {
    f(curr);
    curr = curr->prev;
  }
}

double compute_disorder(Stack *stack)
{
  Element *curr;
  Element *next;
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

static void display(Element *element){
  printf("Element: %d\n", element->data);
}

void display_stack(Stack *stack)
{
  printf("\n-----------------\n");
  if (stack->top)
    printf("Top Element: %d\n", stack->top->data);
  iterate(stack, display);
}

