#include "benchmark/benchmark.h"

void  benchmark_start(Benchmark *benchmark, const char *name)
{
  if (!benchmark) 
    return ;
  benchmark->name = name;
  benchmark->total_moves = 0;
  benchmark->initial_disorder = 0.0;
  benchmark->log_head = 0;
  benchmark->log_count = 0;
  bzero(benchmark->op_moves, sizeof(benchmark->op_moves));
}

static const char *get_string_from_op(Operator op)
{
  static const char *names[OP_COUNT]  = {
    "sa", "sb", "ss",
    "pa", "pb",
    "ra", "rb", "rr",
    "rra", "rrb", "rrr",
  };
  if (op < 0 || op >= OP_COUNT)
    return (NULL);
  return names[op];
}

void  benchmark_update(Benchmark *benchmark, Operator operator)
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
static void print_log_tail(Benchmark *benchmark)
{
  long i, idx;
  long shown;

  if (benchmark->log_count == 0)
    return ;
  shown = benchmark->log_count;
  i = 0;
  while (i < shown)
  {
    idx = (benchmark->log_head - benchmark->log_count + i + BENCH_BUFFER_CAP) % BENCH_BUFFER_CAP;
    printf("%s\n", get_string_from_op((Operator)benchmark->log[idx]));
    i++;
  }
}

void benchmark_output(Benchmark *benchmark)
{
  // print_log_tail(benchmark);
  printf("|-------------------|  %10s  |-------------------|\n", benchmark->name);
  printf("[bench]: disorder: %.2f%%\n", benchmark->initial_disorder * 100.0);
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
