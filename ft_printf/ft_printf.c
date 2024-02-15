/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:18:29 by atyurina          #+#    #+#             */
/*   Updated: 2023/11/30 12:26:00 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		total;

	i = 0;
	total = 0;
	va_start(ap, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i])
		{
			i++;
			ft_format(str[i], ap, &total);
			i++;
		}
		if (str[i] != '%' && str[i])
		{
			ft_putchar(str[i], &total);
			i++;
		}
	}
	va_end(ap);
	return (total);
}
/*
int	main(void)
{
	int	my;
	int	orig;
	void	*ptr;

	my = ft_printf("Hi, %c, %s, %p, %p, %d, %i, %u, %x, %X, %%\n",
'c', "string", &ptr, ((void *)-1), -4242, 325, -45, 16, -676);
	orig = printf("Hi, %c, %s, %p, %p, %d, %i, %u, %x, %X, %%\n",
 'c', "string", &ptr, ((void *)-1), -4242, 325, -45, 16, -676);
	printf("my = %d, orig = %d", my, orig);
	return (0);
}
*/
