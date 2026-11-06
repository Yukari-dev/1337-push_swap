/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_apply_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:13:10 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:13:11 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus/checker_bonus.h"

static int	do_double(t_checker *c, char *line)
{
	if (!ft_strcmp(line, "ss"))
	{
		swap_top(c->a.data, c->a.size);
		swap_top(c->b.data, c->b.size);
	}
	else if (!ft_strcmp(line, "rr"))
	{
		rotate_up(c->a.data, c->a.size);
		rotate_up(c->b.data, c->b.size);
	}
	else if (!ft_strcmp(line, "rrr"))
	{
		rotate_down(c->a.data, c->a.size);
		rotate_down(c->b.data, c->b.size);
	}
	else
		return (0);
	return (1);
}

int	apply_op(t_checker *c, char *line)
{
	if (!line || !*line)
		return (0);
	if (!ft_strcmp(line, "sa"))
		swap_top(c->a.data, c->a.size);
	else if (!ft_strcmp(line, "sb"))
		swap_top(c->b.data, c->b.size);
	else if (!ft_strcmp(line, "pa"))
		push_top(c->a.data, &c->a.size, c->b.data, &c->b.size);
	else if (!ft_strcmp(line, "pb"))
		push_top(c->b.data, &c->b.size, c->a.data, &c->a.size);
	else if (!ft_strcmp(line, "ra"))
		rotate_up(c->a.data, c->a.size);
	else if (!ft_strcmp(line, "rb"))
		rotate_up(c->b.data, c->b.size);
	else if (!ft_strcmp(line, "rra"))
		rotate_down(c->a.data, c->a.size);
	else if (!ft_strcmp(line, "rrb"))
		rotate_down(c->b.data, c->b.size);
	else
		return (do_double(c, line));
	return (1);
}
