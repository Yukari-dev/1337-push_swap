/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_whitespace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 17:50:54 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/07 17:50:55 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus/checker_bonus.h"

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

int	checker_parse_whitespace(int *data, int *size, int cap, char *tok)
{
	int		i;
	int		start;
	char	buf[32];

	start = *size;
	i = 0;
	while (tok[i])
	{
		while (tok[i] == ' ' || tok[i] == '\t')
			i++;
		if (!tok[i])
			break ;
		if (extract_word(tok, &i, buf, 32) <= 0)
			return (0);
		if (*size >= cap)
			return (0);
		if (parse_one(buf, &data[*size]) < 0)
			return (0);
		(*size)++;
	}
	return (*size > start);
}
