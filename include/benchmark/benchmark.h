#ifndef BENCHMARK_H
#define BENCHMARK_H
#include <string.h>
#include <stdio.h>

#define BENCH_BUFFER_CAP 512

typedef enum {
  OP_SA, OP_SB, OP_SS,
  OP_PA, OP_PB,
  OP_RA, OP_RB, OP_RR,
  OP_RRA, OP_RRB, OP_RRR,
  OP_COUNT
} Operator;

typedef struct {
  unsigned long total_moves;
  unsigned long op_moves[OP_COUNT];
  unsigned char log[BENCH_BUFFER_CAP];
  int           log_head;
  int           log_count;
  double        initial_disorder;
  const char    *name;
} Benchmark;

void  benchmark_start(Benchmark *benchmark, const char *name);
void  benchmark_update(Benchmark *benchmark, Operator operator);
void  benchmark_output(Benchmark *benchmark);
void  benchmark_end(Benchmark *benchmark);

#endif
