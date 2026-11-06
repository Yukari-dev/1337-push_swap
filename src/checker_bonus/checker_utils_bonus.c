/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:13:05 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:13:06 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus/checker_bonus.h"

int	ft_strcmp(const char *a, const char *b)
{
	while (*a && *a == *b)
	{
		a++;
		b++;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}

void	memmove_int(int *dst, int *src, int n)
{
	int	i;

	if (dst == src || n <= 0)
		return ;
	if (dst < src)
	{
		i = 0;
		while (i < n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (i >= 0)
		{
			dst[i] = src[i];
			i--;
		}
	}
}

int	is_stack_sorted(t_checkerStack *s)
{
	int	i;

	i = 1;
	while (i < s->size)
	{
		if (s->data[i - 1] > s->data[i])
			return (0);
		i++;
	}
	return (1);
}

void	free_checker(t_checker *c)
{
	free(c->a.data);
	free(c->b.data);
	c->a.data = NULL;
	c->b.data = NULL;
}
