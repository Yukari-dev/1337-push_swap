#ifndef BENCHMARK_H
#define BENCHMARK_H
#include <string.h>
#include <stdio.h>

typedef enum {
  OP_SA, OP_SB, OP_SS,
  OP_PA, OP_PB,
  OP_RA, OP_RB, OP_RR,
  OP_RRA, OP_RRB, OP_RRR,
  OP_COUNT
} Operator;

typedef struct {
  const char    *name;
  double        initial_disorder;
  unsigned long total_moves;
  unsigned long op_moves[OP_COUNT];
} Benchmark;

void  benchmark_start(Benchmark *benchmark, const char *name);
void  benchmark_update(Benchmark *benchmark, Operator operator);
void  benchmark_output(Benchmark *benchmark);
void  benchmark_end(Benchmark *benchmark);

#endif
