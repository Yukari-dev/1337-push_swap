/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:11:56 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:11:56 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus/checker_bonus.h"

void	swap_top(int *d, int size)
{
	int	t;

	if (size < 2)
		return ;
	t = d[0];
	d[0] = d[1];
	d[1] = t;
}

void	push_top(int *dst, int *ds, int *src, int *ss)
{
	if (*ss == 0)
		return ;
	memmove_int(dst + 1, dst, *ds);
	dst[0] = src[0];
	(*ds)++;
	memmove_int(src, src + 1, *ss - 1);
	(*ss)--;
}

void	rotate_up(int *d, int size)
{
	int	t;
	int	i;

	if (size < 2)
		return ;
	t = d[0];
	i = 0;
	while (i < size - 1)
	{
		d[i] = d[i + 1];
		i++;
	}
	d[size - 1] = t;
}

void	rotate_down(int *d, int size)
{
	int	t;
	int	i;

	if (size < 2)
		return ;
	t = d[size - 1];
	i = size - 1;
	while (i > 0)
	{
		d[i] = d[i - 1];
		i--;
	}
	d[0] = t;
}
