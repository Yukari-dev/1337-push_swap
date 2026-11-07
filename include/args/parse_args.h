/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:16:01 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:16:03 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGS_H
# define PARSE_ARGS_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>

typedef enum s_Strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}	t_strategy;

typedef struct s_args
{
	int			*data;
	int			size;
	int			cap;
	t_strategy	strategy;
	int			bench;
}	t_args;

int			parse_args(t_args *args, int argc, char **argv);
int			parse_one(char *s, int *out);
int			parse_whitespace(t_args *args, char *tok);
int			count_args_bytes(int argc, char **argv);
int			has_dups(int *arr, int n);
int			handle_flag(t_args *args, char *tok, int *seen);
void		free_args(t_args *args);
const char	*strategy_name(t_strategy s, int is_adaptive);

#endif
