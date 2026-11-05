#include "checker/checker.h"

static void	swap_top(int *d, int size)
{
	int	t;

	if (size < 2)
		return ;
	t = d[0];
	d[0] = d[1];
	d[1] = t;
}

static void	push_top(int *dst, int *ds, int *src, int *ss)
{
	if (*ss == 0)
		return ;
	memmove_int(dst + 1, dst, *ds);
	dst[0] = src[0];
	(*ds)++;
	memmove_int(src, src + 1, *ss - 1);
	(*ss)--;
}

static void	rotate_up(int *d, int size)
{
	int	t;
	int	i;

	if (size < 2)
		return ;
	t = d[0];
	i = 0;
	while (i < size - 1)
	{
		d[i] = d[i + 1];
		i++;
	}
	d[size - 1] = t;
}

static void	rotate_down(int *d, int size)
{
	int	t;
	int	i;

	if (size < 2)
		return ;
	t = d[size - 1];
	i = size - 1;
	while (i > 0)
	{
		d[i] = d[i - 1];
		i--;
	}
	d[0] = t;
}

int	apply_op(t_checker *c, char *line)
{
	int	*a;
	int	*b;
	int	*as;
	int	*bs;

	if (!line || !*line)
		return (0);
	a = c->a.data;
	b = c->b.data;
	as = &c->a.size;
	bs = &c->b.size;
	if (!ft_strcmp(line, "sa")) swap_top(a, *as);
	else if (!ft_strcmp(line, "sb")) swap_top(b, *bs);
	else if (!ft_strcmp(line, "ss")) { swap_top(a, *as); swap_top(b, *bs); }
	else if (!ft_strcmp(line, "pa")) push_top(a, as, b, bs);
	else if (!ft_strcmp(line, "pb")) push_top(b, bs, a, as);
	else if (!ft_strcmp(line, "ra")) rotate_up(a, *as);
	else if (!ft_strcmp(line, "rb")) rotate_up(b, *bs);
	else if (!ft_strcmp(line, "rr")) { rotate_up(a, *as); rotate_up(b, *bs); }
	else if (!ft_strcmp(line, "rra")) rotate_down(a, *as);
	else if (!ft_strcmp(line, "rrb")) rotate_down(b, *bs);
	else if (!ft_strcmp(line, "rrr")) { rotate_down(a, *as); rotate_down(b, *bs); }
	else
		return (0);
	return (1);
}
