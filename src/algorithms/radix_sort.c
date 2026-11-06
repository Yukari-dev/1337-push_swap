/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:39:25 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 11:39:26 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms/algorithms.h"
#include "stack/instructions/push.h"
#include "stack/instructions/rotate.h"

static void	radix_pass(t_Stack *a, t_Stack *b, int bit, int total_count)
{
	int	i;

	i = 0;
	while (i < total_count)
	{
		if ((a->top->index >> bit) & 1)
			ra(a);
		else
			pb(b, a);
		i++;
	}
	while (!is_empty(b))
		pa(a, b);
}

void	radix_sort(t_Stack *a, t_Stack *b)
{
	int	bit;
	int	max_bits;
	int	total_count;

	if (is_empty(a))
		return ;
	bit = 0;
	total_count = size(a);
	max_bits = 0;
	while (((total_count - 1) >> max_bits) != 0)
		max_bits++;
	while (bit < max_bits)
	{
		radix_pass(a, b, bit, total_count);
		bit++;
	}
}
