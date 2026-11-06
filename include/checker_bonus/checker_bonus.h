/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:14:53 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:14:55 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "stack/stack.h"
# include <limits.h>
# include <unistd.h>

# define BUFFER_LINE_MAX 32

typedef struct s_checkerStack
{
	int	*data;
	int	size;
}	t_checkerStack;

typedef struct s_checker
{
	t_checkerStack	a;
	t_checkerStack	b;
}	t_checker;

void	put_msg(int fd, const char *msg, int len);
int		parse_args(t_checker *c, int argc, char **argv);
void	free_checker(t_checker *c);
int		ft_strcmp(const char *a, const char *b);
void	memmove_int(int *dst, int *src, int n);
int		is_stack_sorted(t_checkerStack *s);
void	swap_top(int *d, int size);
void	push_top(int *dst, int *ds, int *src, int *ss);
void	rotate_up(int *d, int size);
void	rotate_down(int *d, int size);
int		apply_op(t_checker *c, char *line);

#endif
