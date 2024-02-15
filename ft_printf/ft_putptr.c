/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:24:16 by atyurina          #+#    #+#             */
/*   Updated: 2023/11/28 17:35:52 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ptr in hexadecimap format

#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

void	ft_putptr(void *ptr, int *len)
{
	unsigned long int	adr;

	adr = (unsigned long int)(ptr);
	if (adr == 0)
	{
		ft_putstr("(nil)", len);
		return ;
	}
	ft_putstr("0x", len);
	ft_putnbr_base(adr, "0123456789abcdef", len);
}
