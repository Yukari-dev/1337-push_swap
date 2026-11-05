#ifndef ALGORITHM_H
#define ALGORITHM_H
#include "stack/stack.h"

void  selection_sort(t_Stack *a, t_Stack *b);
void  bubble_sort(t_Stack *a);
void  chunk_sort(t_Stack *a, t_Stack *b, int chunk_size);
void  radix_sort(t_Stack *a, t_Stack *b);
 
#endif
