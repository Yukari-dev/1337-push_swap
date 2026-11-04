#include "stack/stack.h"
#include "stack/instructions/swap.h"
#include "stack/instructions/push.h"
#include "stack/instructions/rotate.h"
#include "algorithms/algorithms.h"
#include "benchmark/benchmark.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 100000

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

typedef void (*t_sort)(Stack *a, Stack *b, int param);

typedef struct {
	const	char	*name;
	t_sort	fn;
	int			param;
} t_test;

static void	run_selection(Stack *a, Stack *b, int p) { (void)p; selection_sort(a, b); }
static void	run_bubble(Stack *a, Stack *b, int p)    { (void)b; (void)p; bubble_sort(a); }
static void	run_chunk(Stack *a, Stack *b, int p)     { chunk_sort(a, b, p); }

void generate_stack(Stack *stack, int n)
{
  srand(42);
  
  while (n-- > 0)
    push(stack, (rand() % (MAX - MIN + 1)) + MIN, -1);
}

static void	build_stack(Stack *s, int n)
{
	initialize_stack(s);
	generate_stack(s, n);
}

static long long	now_ns(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ((long long)ts.tv_sec * 1000000000LL + ts.tv_nsec);
}

static const char	*time_color(long long ns)
{
	if (ns < 1000000LL)
		return (GREEN);
	if (ns < 100000000LL)
		return (YELLOW);
	return (RED);
}

static void	format_elapsed(char *buf, size_t size, long long ns)
{
	if (ns < 1000)
		snprintf(buf, size, "%lld ns", ns);
	else if (ns < 1000000)
		snprintf(buf, size, "%.3f us", ns / 1000.0);
	else if (ns < 1000000000)
		snprintf(buf, size, "%.3f ms", ns / 1000000.0);
	else
		snprintf(buf, size, "%.3f s", ns / 1000000000.0);
}

static void	print_result(const char *name, long long ns, double disorder)
{
	char	elapsed[32];

	format_elapsed(elapsed, sizeof(elapsed), ns);
	fprintf(stderr, BOLD BLUE "%-14s" RESET, name);
	fprintf(stderr, " time: %s%-12s\n" RESET, time_color(ns), elapsed);
}


int main(){
	int		n = 10000;
	t_test	tests[] = {
		{"selection", run_selection, 0},
		{"bubble",    run_bubble,    0},
		{"chunk c=5",   run_chunk,   5},
		{"chunk c=10", run_chunk,   10},
		{"chunk c=15", run_chunk,   15},
		{"chunk c=30", run_chunk,   30},
	};
	Stack	a;
	Stack	b;
	int		i;

	long long	t0;
	long long	ns;

	fprintf(stderr, BOLD CYAN "n = %d, same input for every test\n\n" RESET, n);
	i = 0;

	size_t	tests_size = sizeof(tests) / sizeof(tests[0]);
	Benchmark benchmark[tests_size];
	while (i < tests_size)
	{
		benchmark_start(&benchmark[i], tests[i].name);
		build_stack(&a, n);
		initialize_stack(&b);
		benchmark[i].initial_disorder = compute_disorder(&a);
		a.benchmark = &benchmark[i];
		b.benchmark = &benchmark[i];
		rank_data(&a);
		t0 = now_ns();
		tests[i].fn(&a, &b, tests[i].param);
		ns = now_ns() - t0;
		print_result(tests[i].name, ns, compute_disorder(&a));
		clear_stack(&a);
		clear_stack(&b);
		benchmark_end(&benchmark[i]);
		i++;
	}

	i = 0;
	while (i < tests_size)
	{
		benchmark_output(&benchmark[i]);
		i++;
	}

  return 0;
}
