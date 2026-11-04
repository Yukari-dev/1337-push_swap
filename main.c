#include "stack/stack.h"
#include "stack/instructions/swap.h"
#include "stack/instructions/push.h"
#include "stack/instructions/rotate.h"
#include "algorithms/algorithms.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 0
#define MAX 1000

void generate_stack(Stack *stack, int n)
{
  srand(time(NULL));
  
  while (n-- > 0)
    push(stack, (rand() % (MAX - MIN + 1)) + MIN);
}

static long long	now_ns(void)
{
	struct timespec	ts;

	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ((long long)ts.tv_sec * 1000000000LL + ts.tv_nsec);
}

static void	print_elapsed(const char *label, long long ns)
{
	if (ns < 1000)
		fprintf(stderr, "%s: %lld ns\n", label, ns);
	else if (ns < 1000000)
		fprintf(stderr, "%s: %.3f us\n", label, ns / 1000.0);
	else if (ns < 1000000000)
		fprintf(stderr, "%s: %.3f ms\n", label, ns / 1000000.0);
	else
		fprintf(stderr, "%s: %.3f s\n", label, ns / 1000000000.0);
}

#define TIMED(label, call) \
	do { \
		long long	t0_ = now_ns(); \
		call; \
		print_elapsed(label, now_ns() - t0_); \
	} while (0)


int main(){
  Stack a;
  Stack b;

  initialize_stack(&a);
  initialize_stack(&b);
  TIMED("Generate stack", generate_stack(&a, 10000));
  // display_stack(&a);
  
  // TIMED("Selection sort", selection_sort(&a, &b));
  TIMED("Bubble sort", bubble_sort(&a));
  // display_stack(&a);
  // display_stack(&b);
  
  return 0;
}
