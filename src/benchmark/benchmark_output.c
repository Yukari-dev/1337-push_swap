/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:00:04 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:00:04 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark/benchmark.h"

static const char	*get_string_from_op(t_operator op)
{
	static const char	*names[OP_COUNT] = {
		"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"
	};

	if (op < 0 || op >= OP_COUNT)
		return (NULL);
	return (names[op]);
}

static void	put_float_fd(double disorder)
{
	int	percent;
	int	frac;

	percent = (int)(disorder * 100.0);
	frac = (int)((disorder * 10000.0) - (percent * 100));
	ft_putnbr_fd(percent, 2);
	ft_putstr_fd(".", 2);
	if (frac < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(frac, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_log_tail(t_benchmark *benchmark)
{
	long	i;
	long	idx;

	if (benchmark->log_count == 0)
		return ;
	i = 0;
	while (i < benchmark->log_count)
	{
		idx = benchmark->log_head - benchmark->log_count + i;
		idx = (idx + BENCH_BUFFER_CAP) % BENCH_BUFFER_CAP;
		ft_putstr_fd((char *)get_string_from_op(benchmark->log[idx]), 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	benchmark_output(t_benchmark *benchmark)
{
	ft_putstr_fd("[bench]: disorder: ", 1);
	put_float_fd(benchmark->initial_disorder);
	ft_putstr_fd("[bench]: strategy: ", 1);
	ft_putstr_fd(benchmark->strategy_name, 1);
	ft_putstr_fd("\n[bench]: total_ops: ", 1);
	ft_putnbr_fd((int)benchmark->total_moves, 1);
	ft_putstr_fd("\n", 1);
	print_ops(benchmark);
}
