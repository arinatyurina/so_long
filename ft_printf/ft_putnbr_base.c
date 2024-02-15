/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:28:09 by atyurina          #+#    #+#             */
/*   Updated: 2023/11/30 12:24:51 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

static void	print_nbr(unsigned long int nbr,
unsigned long int base_value, char *base, int *len)
{
	unsigned long int	ln;

	ln = nbr;
	if (ln >= base_value)
	{
		print_nbr(ln / base_value, base_value, base, len);
	}
	ft_putchar(base[ln % base_value], len);
}

void	ft_putnbr_base(unsigned long int nbr, char *base, int *len)
{
	unsigned long int	base_value;

	base_value = 0;
	while (base[base_value])
		base_value++;
	print_nbr(nbr, base_value, base, len);
}
/*
int	ft_atoi(const char *nptr)
{
	int			i;
	int			posneg;
	long int	res;

	i = 0;
	posneg = 1;
	res = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			posneg *= (-1);
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * posneg);
}

int	main(int argc, char **argv)
{

	int	nbr;
	char	*base;

	nbr = ft_atoi(argv[1]);
	base = argv[2];
	if (argc > 0)
		ft_putnbr_base(nbr, base);
}
*/
