/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:12:56 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:12:57 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus/checker_bonus.h"

static int	parse_sign(char *s, int *i, int *neg)
{
	*neg = 0;
	*i = 0;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*neg = 1;
		(*i)++;
	}
	if (!s[*i])
		return (-1);
	return (0);
}

static int	parse_digits(char *s, int i, int neg, long long *v)
{
	*v = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		*v = *v * 10 + (s[i] - '0');
		if (!neg && *v > INT_MAX)
			return (-1);
		if (neg && *v > (long long)INT_MAX + 1)
			return (-1);
		i++;
	}
	return (0);
}

int	parse_one(char *s, int *out)
{
	int			i;
	int			neg;
	long long	v;

	if (!s || !*s)
		return (-1);
	if (parse_sign(s, &i, &neg) < 0)
		return (-1);
	if (parse_digits(s, i, neg, &v) < 0)
		return (-1);
	if (neg)
		*out = (int)-v;
	else
		*out = (int)v;
	return (0);
}

static int	has_dups(int *data, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (data[i] == data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(t_checker *c, int argc, char **argv)
{
	int	max;
	int	i;

	max = checker_count_bytes(argc, argv);
	c->a.data = malloc((size_t)max * sizeof(int));
	c->b.data = malloc((size_t)max * sizeof(int));
	if (!c->a.data || !c->b.data)
		return (-1);
	c->a.size = 0;
	c->b.size = 0;
	i = 1;
	while (i < argc)
	{
		if (!checker_parse_whitespace(c->a.data, &c->a.size, max, argv[i]))
			return (-1);
		i++;
	}
	if (has_dups(c->a.data, c->a.size))
		return (-1);
	return (0);
}
