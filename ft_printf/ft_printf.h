/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:51:34 by atyurina          #+#    #+#             */
/*   Updated: 2023/11/30 12:24:17 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *i);
void	ft_putnbr_base(unsigned long int nbr, char *base, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putptr(void *ptr, int *len);
void	ft_putnbr_u(unsigned int nb, int *len);
void	ft_format(char a, va_list ap, int *len);

#endif
