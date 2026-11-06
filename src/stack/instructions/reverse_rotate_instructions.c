/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_instructions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:30:35 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 11:30:35 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/instructions/rotate.h"

void	reverse_rotate(t_Stack *stack)
{
	t_Element	*last;

	if (is_empty(stack) || !stack->start || !stack->start->next)
		return ;
	last = stack->start;
	stack->start = last->next;
	last->next = NULL;
	stack->start->prev = NULL;
	last->prev = stack->top;
	stack->top->next = last;
	stack->top = last;
}

void	rra(t_Stack *a)
{
	reverse_rotate(a);
	ft_putstr_fd("rra\n", 1);
	benchmark_update(a->benchmark, OP_RRA);
}

void	rrb(t_Stack *b)
{
	reverse_rotate(b);
	ft_putstr_fd("rrb\n", 1);
	benchmark_update(b->benchmark, OP_RRB);
}

void	rrr(t_Stack *a, t_Stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_putstr_fd("rrr\n", 1);
	benchmark_update(a->benchmark, OP_RRR);
	benchmark_update(b->benchmark, OP_RRR);
}
