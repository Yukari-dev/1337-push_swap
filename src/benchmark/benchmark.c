/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 11:59:53 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 11:59:54 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark/benchmark.h"

void	benchmark_start(t_benchmark *benchmark, const char *name)
{
	int	i;

	if (!benchmark)
		return ;
	benchmark->name = name;
	benchmark->total_moves = 0;
	benchmark->initial_disorder = 0.0;
	benchmark->log_head = 0;
	benchmark->log_count = 0;
	i = -1;
	while (++i < OP_COUNT)
		benchmark->op_moves[i] = 0;
}

void	benchmark_update(t_benchmark *benchmark, t_operator operator)
{
	if (!benchmark || operator < 0 || operator >= OP_COUNT)
		return ;
	benchmark->op_moves[operator]++;
	benchmark->total_moves++;
	benchmark->log[benchmark->log_head] = operator;
	benchmark->log_head = (benchmark->log_head + 1) % BENCH_BUFFER_CAP;
	if (benchmark->log_count < BENCH_BUFFER_CAP)
		benchmark->log_count++;
}

void	benchmark_set_disorder(t_benchmark *benchmark, double disorder)
{
	if (benchmark)
		benchmark->initial_disorder = disorder;
}

void	benchmark_set_strategy(t_benchmark *benchmark, const char *strat)
{
	if (benchmark)
		benchmark->strategy_name = strat;
}

void	benchmark_end(t_benchmark *benchmark)
{
	print_log_tail(benchmark);
}
