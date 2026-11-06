/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:25:26 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 11:25:30 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/instructions/push.h"

void	pa(t_Stack *a, t_Stack *b)
{
	if (is_empty(b))
		return ;
	if (b->top)
	{
		push(a, b->top->data, b->top->index);
		pop(b);
		ft_putstr_fd("pa\n", 1);
		benchmark_update(a->benchmark, OP_PA);
	}
}

void	pb(t_Stack *b, t_Stack *a)
{
	if (is_empty(a))
		return ;
	if (a->top)
	{
		push(b, a->top->data, a->top->index);
		pop(a);
		ft_putstr_fd("pb\n", 1);
		benchmark_update(b->benchmark, OP_PB);
	}
}
