/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:39:02 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 11:39:03 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms/algorithms.h"
#include "stack/instructions/push.h"
#include "stack/instructions/rotate.h"

static void	chunk_push(t_Stack *a, t_Stack *b, int chunk_size)
{
	int	pushed_count;
	int	top_rank;

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
}

static void	chunk_merge(t_Stack *a, t_Stack *b)
{
	int	largest_rank;
	int	b_size;

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

void	chunk_sort(t_Stack *a, t_Stack *b, int chunk_size)
{
	if (is_empty(a))
		return ;
	chunk_push(a, b, chunk_size);
	chunk_merge(a, b);
}
