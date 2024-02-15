/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 13:13:54 by atyurina          #+#    #+#             */
/*   Updated: 2023/06/15 14:07:23 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nb, int *len)
{
	long int	a;

	a = nb;
	if (a < 0)
	{
		ft_putchar(('-'), len);
		a = -a;
	}
	if (a > 9)
	{
		ft_putnbr((a / 10), len);
		ft_putnbr((a % 10), len);
	}
	if (a < 10)
	{
		ft_putchar((a + '0'), len);
	}
}
