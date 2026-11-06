/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maoulad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 12:00:09 by maoulad           #+#    #+#             */
/*   Updated: 2026/11/06 12:00:10 by maoulad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "benchmark/benchmark.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(const char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}

void	put_float_fd(double disorder)
{
	int	total;
	int	percent;
	int	frac;

	total = (int)(disorder * 10000.0 + 0.5);
	percent = total / 100;
	frac = total % 100;
	ft_putnbr_fd(percent, 2);
	ft_putstr_fd(".", 2);
	if (frac < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(frac, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_ops(t_benchmark *benchmark)
{
	ft_putstr_fd("[bench]: sa: ", 2);
	ft_putnbr_fd((int)benchmark->op_moves[OP_SA], 1);
	ft_putstr_fd(", sb: ", 1);
	ft_putnbr_fd((int)benchmark->op_moves[OP_SB], 1);
	ft_putstr_fd(", ss: ", 1);
	ft_putnbr_fd((int)benchmark->op_moves[OP_SS], 1);
	ft_putstr_fd(", pa: ", 1);
	ft_putnbr_fd((int)benchmark->op_moves[OP_PA], 1);
	ft_putstr_fd(", pb: ", 1);
	ft_putnbr_fd((int)benchmark->op_moves[OP_PB], 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("[bench]: ra: ", 1);
	ft_putnbr_fd((int)benchmark->op_moves[OP_RA], 1);
	ft_putstr_fd(", rb: ", 1);
	ft_putnbr_fd((int)benchmark->op_moves[OP_RB], 1);
	ft_putstr_fd(", rr: ", 1);
	ft_putnbr_fd((int)benchmark->op_moves[OP_RR], 1);
	ft_putstr_fd(", rra: ", 1);
	ft_putnbr_fd((int)benchmark->op_moves[OP_RRA], 1);
	ft_putstr_fd(", rrb: ", 1);
	ft_putnbr_fd((int)benchmark->op_moves[OP_RRB], 1);
	ft_putstr_fd(", rrr: ", 1);
	ft_putnbr_fd((int)benchmark->op_moves[OP_RRR], 1);
	ft_putstr_fd("\n", 1);
}
