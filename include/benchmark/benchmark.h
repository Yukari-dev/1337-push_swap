/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:26:19 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:26:20 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BENCHMARK_H
# define BENCHMARK_H

# include <unistd.h>

typedef enum e_operator
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT
}	t_operator;

typedef struct s_benchmark
{
	unsigned long	total_moves;
	unsigned long	op_moves[OP_COUNT];
	double			initial_disorder;
	const char		*strategy_name;
}	t_benchmark;

void	benchmark_start(t_benchmark *benchmark);
void	benchmark_update(t_benchmark *benchmark, t_operator operator);
void	benchmark_set_disorder(t_benchmark *benchmark, double disorder);
void	benchmark_set_strategy(t_benchmark *benchmark, const char *strat);
void	benchmark_output(t_benchmark *benchmark);
void	print_ops(t_benchmark *benchmark);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif
