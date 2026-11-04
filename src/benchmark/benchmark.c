#include "benchmark/benchmark.h"

void  benchmark_start(Benchmark *benchmark, const char *name)
{
  benchmark->name = name;
  benchmark->total_moves = 0;
  // TODO: replace it with libft ft_memset when available.
  bzero(benchmark->op_moves, sizeof(benchmark->op_moves));
}

void  benchmark_update(Benchmark *benchmark, Operator operator)
{
  if (!benchmark)
    return ;
  benchmark->op_moves[operator]++;
  benchmark->total_moves++;
}

void benchmark_output(Benchmark *benchmark)
{
  printf("|-------------------|  %10s  |-------------------|\n", benchmark->name);
  printf("[bench]: disorder: %.2f%%\n", benchmark->initial_disorder * 100.0);
  // TODO: STRATEGY
  printf("[bench]: total_ops: %ld\n", benchmark->total_moves);
  printf("[bench]: sa: %2ld, sb: %2ld, ss: %2ld, pa: %2ld, pb: %2ld\n", 
         benchmark->op_moves[OP_SA], benchmark->op_moves[OP_SB], benchmark->op_moves[OP_SS],
         benchmark->op_moves[OP_PA], benchmark->op_moves[OP_PB]
  );
  printf("[bench]: ra: %2ld, rb: %2ld, rr: %2ld, rra: %2ld, rrb: %2ld, rrr: %2ld\n", 
         benchmark->op_moves[OP_RA], benchmark->op_moves[OP_RB], benchmark->op_moves[OP_RR],
         benchmark->op_moves[OP_RRA], benchmark->op_moves[OP_RRB], benchmark->op_moves[OP_RRR]
  );
  printf("|------------------------------------------------------|\n");
}

void benchmark_end(Benchmark *benchmark)
{
  // printf("[BENCHMARK]: total_ops: %ld\n", benchmark->total_moves);
}

