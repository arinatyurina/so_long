/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_dop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:31:08 by atyurina          #+#    #+#             */
/*   Updated: 2024/01/31 12:27:40 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	map_height(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
		i++;
	return (i);
}

int	times_met(t_mlx_data *data, char a)
{
	int	i;
	int	j;
	int	res;

	res = 0;
	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == a)
				res++;
			j++;
		}
		i++;
	}
	return (res);
}

int	invalid_map(t_mlx_data *data)
{
	int	c;
	int	e;
	int	p;

	c = times_met(data, 'C');
	e = times_met(data, 'E');
	p = times_met(data, 'P');
	if (c < 1 || p != 1 || e != 1)
	{
		ft_printf("Error\nInvalid map");
		return (1);
	}
	else
		return (0);
}

int	ft_strlen_map(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	is_rectangle(t_mlx_data *data)
{
	int	i;
	int	lines;
	int	*lens;

	lens = malloc(map_height(data) * sizeof(int));
	i = 0;
	lines = map_height(data);
	while (i < lines)
	{
		lens[i] = ft_strlen(data->map[i]);
		i++;
	}
	i = 0;
	while (i + 1 < lines)
	{
		if (lens[i] != lens[i + 1])
		{
			ft_printf("Error\nMap is not rectangular");
			return (1);
		}
		i++;
	}
	free(lens);
	return (0);
}

/*
int	is_rectangle(t_mlx_data *data)
{
	int	i;
	int	lines;
	int	*lens;

	i = 0;
	lines = map_height(data);
	lens = (int *)malloc(lines * sizeof(int));
	while (i < lines)
	{
		lens[i] = ft_strlen_map(data->map[i]);
		ft_printf("lens[i]=%i", lens[i]);
		i++;
	}
	i = 0;
	while (i + 1 < lines)
	{
		if (lens[i] != lens[i + 1])
		{
			ft_printf("lens[i] = %i, lens[i + 1] = %i, i = %i", lens[i], lens[i
				+ 1], i);
			ft_printf("Error\nMap is not rectangular");
			return (1);
		}
		i++;
	}
	free(lens);
	return (0);
}
*/
