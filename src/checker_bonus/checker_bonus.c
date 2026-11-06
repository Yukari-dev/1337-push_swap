/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:08:37 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:08:38 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus/checker_bonus.h"

void	put_msg(int fd, const char *msg, int len)
{
	int	sent;
	int	r;

	sent = 0;
	while (sent < len)
	{
		r = write(fd, msg + sent, (size_t)(len - sent));
		if (r <= 0)
			exit(1);
		sent += r;
	}
}

static int	next_char(void)
{
	static char	buf[4096];
	static int	pos = 0;
	static int	len = 0;
	int			r;

	if (pos >= len)
	{
		r = (int)read(0, buf, sizeof(buf));
		if (r <= 0)
			return (r);
		len = r;
		pos = 0;
	}
	return ((unsigned char)buf[pos++]);
}

int	read_line(char *out, int cap)
{
	int	n;
	int	c;

	n = 0;
	while (1)
	{
		c = next_char();
		if (c == 0 && n == 0)
			return (0);
		if (c < 0)
			return (-1);
		if (c == 0 || c == '\n')
			break ;
		if (n >= cap - 1)
			return (-1);
		out[n++] = (char)c;
	}
	out[n] = '\0';
	return (1);
}

static int	die(t_checker *checker)
{
	free_checker(checker);
	put_msg(2, "Error\n", 6);
	return (1);
}

int	main(int ac, char *av[])
{
	t_checker	checker;
	char		line[BUFFER_LINE_MAX];
	int			r;

	if (ac == 1)
		return (0);
	checker.a.data = NULL;
	checker.b.data = NULL;
	if (parse_args(&checker, ac, av) < 0)
		return (die(&checker));
	r = 1;
	while (r > 0)
	{
		if (!apply_op(&checker, line))
			return (die(&checker));
	}
	if (r < 0)
		return (die(&checker));
	if (is_sorted(&checker.a) && checker.b.size == 0)
		put_msg(1, "OK\n", 3);
	else
		put_msg(1, "KO\n", 3);
	free_checker(&checker);
	return (0);
}
