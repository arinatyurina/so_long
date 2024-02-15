/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:42:05 by atyurina          #+#    #+#             */
/*   Updated: 2023/11/29 14:58:32 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int nb, int *len)
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
