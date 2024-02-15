/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:51:21 by atyurina          #+#    #+#             */
/*   Updated: 2023/11/29 18:07:29 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(char a, va_list ap, int *len)
{
	if (a == 'c')
		ft_putchar(va_arg(ap, int), len);
	if (a == 's')
		ft_putstr(va_arg(ap, char *), len);
	if (a == 'p')
		ft_putptr(va_arg(ap, void *), len);
	if (a == 'd' || a == 'i')
		ft_putnbr(va_arg(ap, int), len);
	if (a == 'u')
		ft_putnbr_u(va_arg(ap, int), len);
	if (a == 'x')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef", len);
	if (a == 'X')
		ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF", len);
	if (a == '%')
		ft_putchar('%', len);
}
