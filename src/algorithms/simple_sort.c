/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:38:54 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 11:38:56 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms/algorithms.h"
#include "stack/instructions/swap.h"
#include "stack/instructions/push.h"
#include "stack/instructions/rotate.h"

void	rotate_till(t_Stack *stack, int times,
	void (*rotate)(t_Stack *stack))
{
	while (times > 0)
	{
		rotate(stack);
		times--;
	}
}

void	selection_sort(t_Stack *a, t_Stack *b)
{
	int	smallest_p;
	int	a_size;

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

void	bubble_sort(t_Stack *a)
{
	int			stack_size;
	int			i;
	int			swapped;

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
			break ;
	}
}
