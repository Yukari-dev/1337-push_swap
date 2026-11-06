/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:15:26 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 11:15:29 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/stack.h"

int	size(t_Stack *stack)
{
	t_Element	*curr;
	int			size;

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

char	is_empty(t_Stack *stack)
{
	return (stack->start == NULL);
}

void	rank_data(t_Stack *stack)
{
	t_Element	*curr;
	t_Element	*next;
	int			rank;

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

double	compute_disorder(t_Stack *stack)
{
	t_Element	*curr;
	t_Element	*next;
	long		total_pairs;
	long		mistakes;

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
		return (0.0);
	return ((double)mistakes / total_pairs);
}

int	is_sorted(t_Stack *stack)
{
	t_Element	*curr;

	if (is_empty(stack) || size(stack) == 1)
		return (1);
	curr = stack->top;
	while (curr && curr->prev)
	{
		if (curr->data > curr->prev->data)
			return (0);
		curr = curr->prev;
	}
	return (1);
}
