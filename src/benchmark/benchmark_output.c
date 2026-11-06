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

void	benchmark_output(t_benchmark *benchmark)
{
	ft_putstr_fd("[bench]: disorder: ", 2);
	put_float_fd(benchmark->initial_disorder);
	ft_putstr_fd("[bench]: strategy: ", 2);
	ft_putstr_fd(benchmark->strategy_name, 2);
	ft_putstr_fd("\n[bench]: total_ops: ", 2);
	ft_putnbr_fd((int)benchmark->total_moves, 2);
	ft_putstr_fd("\n", 2);
	print_ops(benchmark);
}
