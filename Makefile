NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude

ALGORITHM_SRCS = src/algorithms/simple_sort.c src/algorithms/chunk_sort.c src/algorithms/radix_sort.c 
BENCHMARK_SRCS = src/benchmark/benchmark.c src/benchmark/benchmark_output.c src/benchmark/benchmark_print.c
STACK_SRCS = src/stack/stack_core.c src/stack/stack_find.c src/stack/stack_utils.c src/stack/utils.c
INSTRUCTION_SRCS = src/stack/instructions/push_instructions.c src/stack/instructions/rotate_instructions.c src/stack/instructions/reverse_rotate_instructions.c \
			 			 				src/stack/instructions/swap_instructions.c 
ARG_SRCS = src/args/parse_args.c src/args/parse_flags.c src/args/parse_utils.c
SRCS = src/push_swap.c $(ALGORITHM_SRCS) $(STACK_SRCS) $(INSTRUCTION_SRCS) $(ARG_SRCS) $(BENCHMARK_SRCS)

BONUS_SRCS = src/checker_bonus/checker_bonus.c src/checker_bonus/checker_ops_bonus.c \
						 src/checker_bonus/checker_parse_bonus.c src/checker_bonus/checker_utils_bonus.c src/checker_bonus/checker_apply_bonus.c

INCLUDES = include/algorithms/algorithms.h include/args/parse_args.h include/benchmark/benchmark.h \
					 include/stack/instructions/push.h include/stack/instructions/rotate.h include/stack/instructions/swap.h \
					 include/stack/stack.h include/stack/utils.h

BONUS_INCLUDES = include/checker_bonus/checker_bonus.h

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS): $(INCLUDES)

$(BONUS_OBJS): $(BONUS_INCLUDES)

clean:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re
