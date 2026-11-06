/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:02:08 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:02:08 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/parse_args.h"

static int	parse_sign(char *s, int *i, int *neg)
{
	*i = 0;
	*neg = 0;
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

int	has_dups(int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
