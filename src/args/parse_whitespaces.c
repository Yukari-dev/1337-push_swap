/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_whitespaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:50:47 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/07 17:50:47 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args/parse_args.h"

static int	extract_word(char *tok, int *i, char *buf, int cap)
{
	int	j;

	j = 0;
	while (tok[*i] && tok[*i] != ' ' && tok[*i] != '\t')
	{
		if (j >= cap - 1)
			return (-1);
		buf[j++] = tok[(*i)++];
	}
	buf[j] = '\0';
	return (j);
}

int	parse_whitespace(t_args *args, char *tok)
{
	int		i;
	int		start_size;
	char	buf[32];

	start_size = args->size;
	i = 0;
	while (tok[i])
	{
		while (tok[i] == ' ' || tok[i] == '\t')
			i++;
		if (!tok[i])
			break ;
		if (extract_word(tok, &i, buf, 32) <= 0)
			return (0);
		if (args->size >= args->cap)
			return (0);
		if (parse_one(buf, &args->data[args->size]) < 0)
			return (0);
		args->size++;
	}
	return (args->size > start_size);
}

int	count_args_bytes(int argc, char **argv)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			total++;
			j++;
		}
		i++;
	}
	return (total);
}
