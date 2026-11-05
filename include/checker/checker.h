#ifndef CHECKER_H
# define CHECKER_H
# include "stack/stack.h"
# include <limits.h>

# define BUFFER_LINE_MAX 32

typedef struct s_checkerStack
{
  int *data;
  int size;
} t_checkerStack;

typedef struct s_checker
{
  t_checkerStack a;
  t_checkerStack b;
} t_checker;

int		read_line(char *buf, int cap);
void	put_msg(int fd, const char *msg, int len);
int		parse_args(t_checker *c, int argc, char **argv);
void	free_checker(t_checker *c);
int		ft_strcmp(const char *a, const char *b);
void	memmove_int(int *dst, int *src, int n);
int		is_sorted(t_checkerStack *s);
int   apply_op(t_checker *c, char *line);

#endif
