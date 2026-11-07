/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 10:49:49 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 10:49:49 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack/stack.h"
#include "stack/instructions/swap.h"
#include "stack/instructions/push.h"
#include "stack/instructions/rotate.h"
#include "algorithms/algorithms.h"
#include "benchmark/benchmark.h"
#include "args/parse_args.h"
#include <stdio.h>
#include <stdlib.h>

void	generate_stack(t_Stack *stack, int *data, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		push(stack, data[n - 1 - i], -1);
}

static t_strategy	resolve_strategy(t_strategy requested, double disorder)
{
	if (requested != STRAT_ADAPTIVE)
		return (requested);
	if (disorder < 0.20)
		return (STRAT_SIMPLE);
	if (disorder < 0.50)
		return (STRAT_MEDIUM);
	return (STRAT_COMPLEX);
}

static void	dispatch(t_Stack *a, t_Stack *b, t_strategy resolved, int size)
{
	if (size < 6)
	{
		bubble_sort(a);
		return ;
	}
	if (resolved == STRAT_SIMPLE)
		selection_sort(a, b);
	else if (resolved == STRAT_MEDIUM)
		chunk_sort(a, b, size);
	else
		radix_sort(a, b);
		// cheapest_sort(a, b);
}

static void	sort(t_Stack *a, t_Stack *b, t_args *args, t_benchmark *bench)
{
	double		disorder;
	t_strategy	resolved;

	initialize_stack(b);
	rank_data(a);
	disorder = compute_disorder(a);
	resolved = resolve_strategy(args->strategy, disorder);
	a->benchmark = bench;
	b->benchmark = bench;
	benchmark_start(bench);
	benchmark_set_disorder(bench, disorder);
	benchmark_set_strategy(bench,
		strategy_name(resolved, args->strategy == STRAT_ADAPTIVE));
	if (!is_sorted(a))
		dispatch(a, b, resolved, args->size);
}

int	main(int argc, char *argv[])
{
	t_args		args;
	t_benchmark	bench;
	t_Stack		a;
	t_Stack		b;

	if (argc == 1)
		return (0);
	if (parse_args(&args, argc, argv) < 0)
	{
		free_args(&args);
		write(2, "Error\n", 6);
		return (1);
	}
	if (args.size == 0)
	{
		free_args(&args);
		return (0);
	}
	initialize_stack(&a);
	generate_stack(&a, args.data, args.size);
	sort(&a, &b, &args, &bench);
	if (args.bench)
		benchmark_output(&bench);
	free_args(&args);
	return (0);
}
