/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:15:07 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 11:15:07 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/stack.h"

t_Element	*create_element(int data, int index)
{
	t_Element	*element;

	element = (t_Element *)malloc(sizeof(t_Element));
	if (!element)
		return (NULL);
	element->data = data;
	element->index = index;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}

void	initialize_stack(t_Stack *stack)
{
	stack->start = NULL;
	stack->top = NULL;
	stack->benchmark = NULL;
}

void	clear_stack(t_Stack *stack)
{
	t_Element	*curr;
	t_Element	*saved;

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

void	push(t_Stack *stack, int data, int index)
{
	t_Element	*element;

	element = create_element(data, index);
	if (!element)
		return ;
	if (is_empty(stack))
	{
		stack->start = element;
		stack->top = element;
	}
	else
	{
		stack->top->next = element;
		element->prev = stack->top;
		stack->top = element;
	}
}

void	pop(t_Stack *stack)
{
	t_Element	*element;

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
	free(element);
}
