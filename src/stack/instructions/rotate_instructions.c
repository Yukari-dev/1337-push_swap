/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:26:01 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 11:26:11 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/instructions/rotate.h"

void	rotate(t_Stack *stack)
{
	t_Element	*first;

	if (is_empty(stack) || !stack->top || !stack->top->prev)
		return ;
	first = stack->top;
	stack->top = first->prev;
	first->prev = NULL;
	stack->top->next = NULL;
	first->next = stack->start;
	stack->start->prev = first;
	stack->start = first;
}

void	ra(t_Stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", 1);
	benchmark_update(a->benchmark, OP_RA);
}

void	rb(t_Stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", 1);
	benchmark_update(b->benchmark, OP_RB);
}

void	rr(t_Stack *a, t_Stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr`n", 1);
	benchmark_update(a->benchmark, OP_RR);
	benchmark_update(b->benchmark, OP_RR);
}
