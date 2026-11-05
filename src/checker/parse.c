#include "checker/checker.h"

static int	parse_sign(char *s, int *i, int *neg)
{
	*neg = 0;
	*i = 0;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*neg = 1;
		(*i)++;
	}
	if (!s[*i])
		return (-1);
	return (0);
}

static int	parse_digits(char *s, int i, int neg, long long *v)
{
	*v = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		*v = *v * 10 + (s[i] - '0');
		if (!neg && *v > INT_MAX)
			return (-1);
		if (neg && *v > (long long)INT_MAX + 1)
			return (-1);
		i++;
	}
	return (0);
}

static int	parse_one(char *s, int *out)
{
	int			i;
	int			neg;
	long long	v;

	if (!s || !*s)
		return (-1);
	if (parse_sign(s, &i, &neg) < 0)
		return (-1);
	if (parse_digits(s, i, neg, &v) < 0)
		return (-1);
	if (neg)
		*out = (int)-v;
	else
		*out = (int)v;
	return (0);
}

static int	has_dups(int *data, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (data[i] == data[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_args(t_checker *checker, int ac, char *av[])
{
	int	total_count;
	int	i;

	total_count = ac - 1;
	checker->a.data = malloc(sizeof(int) * total_count);
	checker->b.data = malloc(sizeof(int) * total_count);
	if (!checker->a.data || !checker->b.data)
		return (-1);
	checker->a.size = 0;
	checker->b.size = 0;
	i = 0;
	while (i < total_count)
	{
		if (parse_one(av[i + 1], &checker->a.data[i]) < 0)
			return (-1);
		i++;
	}
	if (has_dups(checker->a.data, total_count))
		return (-1);
	checker->a.size = total_count;
	return (0);
}
