/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:15:37 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 11:15:38 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/stack.h"

int	find_min_position(t_Stack *stack)
{
	t_Element	*curr;
	int			position;
	int			smallest_position;
	int			smallest;

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

int	find_max_rank_position(t_Stack *stack)
{
	t_Element	*curr;
	int			position;
	int			largest_position;
	int			largest;

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
