/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:01:58 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:01:59 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/parse_args.h"

static int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	strategy_from_flag(char *tok, t_strategy *out)
{
	if (ft_strcmp(tok, "--adaptive") == 0)
		*out = STRAT_ADAPTIVE;
	else if (ft_strcmp(tok, "--simple") == 0)
		*out = STRAT_SIMPLE;
	else if (ft_strcmp(tok, "--medium") == 0)
		*out = STRAT_MEDIUM;
	else if (ft_strcmp(tok, "--complex") == 0)
		*out = STRAT_COMPLEX;
	else
		return (0);
	return (1);
}

int	handle_flag(t_args *args, char *tok, int *seen)
{
	t_strategy	s;

	if (ft_strcmp(tok, "--bench") == 0)
	{
		args->bench = 1;
		return (1);
	}
	if (!strategy_from_flag(tok, &s))
		return (0);
	if (*seen && args->strategy != s)
		return (0);
	args->strategy = s;
	*seen = 1;
	return (1);
}
