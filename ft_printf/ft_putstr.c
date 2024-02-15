/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:39:32 by atyurina          #+#    #+#             */
/*   Updated: 2023/06/13 16:10:01 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *str, int *len)
{
	int	index;

	index = 0;
	if (str == NULL)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[index] != 0)
	{
		write(1, &str[index], 1);
		index++;
	}
	(*len) += index;
}
/*
int	main(void)
{
	char	*str;
	
	str = "abc";
	ft_putstr(str);
	return (0);
}
*/
