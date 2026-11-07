/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:02:03 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:02:04 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/parse_args.h"

static int	init_args(t_args *args, int argc, char **argv)
{
	int	max;

	max = count_args_bytes(argc, argv);
	args->data = NULL;
	args->cap = 0;
	args->size = 0;
	args->strategy = STRAT_ADAPTIVE;
	args->bench = 0;
	if (max <= 0)
		return (1);
	args->data = malloc((size_t)max * sizeof(int));
	if (!args->data)
		return (0);
	args->cap = max;
	return (1);
}

static int	take_token(t_args *args, char *tok, int *seen)
{
	if (tok[0] == '-' && tok[1] == '-')
		return (handle_flag(args, tok, seen));
	if (args->size >= args->cap)
		return (0);
	if (!parse_whitespace(args, tok))
		return (0);
	return (1);
}

const char	*strategy_name(t_strategy s, int is_adaptive)
{
	if (is_adaptive)
	{
		if (s == STRAT_SIMPLE)
			return ("Adaptive / O(n²)");
		if (s == STRAT_MEDIUM)
			return ("Adaptive / O(n√n)");
		return ("Adaptive / O(n log n)");
	}
	if (s == STRAT_SIMPLE)
		return ("Simple / O(n²)");
	if (s == STRAT_MEDIUM)
		return ("Medium / O(n√n)");
	return ("Complex / O(n log n)");
}

int	parse_args(t_args *args, int argc, char **argv)
{
	int	i;
	int	seen;

	if (!init_args(args, argc, argv))
		return (-1);
	seen = 0;
	i = 0;
	while (i < argc - 1)
	{
		if (!take_token(args, argv[i + 1], &seen))
			return (-1);
		i++;
	}
	if (has_dups(args->data, args->size))
		return (-1);
	return (0);
}

void	free_args(t_args *args)
{
	free(args->data);
	args->data = NULL;
	args->size = 0;
	args->cap = 0;
}
