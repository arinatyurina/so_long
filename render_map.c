/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:25:36 by atyurina          #+#    #+#             */
/*   Updated: 2024/01/30 12:21:41 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	closed_by_walls(t_mlx_data *data)
{
	int	he;
	int	wi;
	int	j;

	wi = ft_strlen(data->map[1]);
	he = map_height(data);
	data->h = he;
	data->w = wi;
	j = 0;
	while (data->map[0][j] != '\0' && j < wi)
	{
		if (data->map[0][j] != '1' || data->map[he - 1][j] != '1')
			return (1);
		j++;
	}
	j = 0;
	while (j < he)
	{
		if (data->map[j][0] != '1' || data->map[j][wi - 1] != '1')
			return (1);
		j++;
	}
	return (0);
}

void	start_point(t_mlx_data *data, char a)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == a)
			{
				data->p_j = j;
				data->p_i = i;
			}
			j++;
		}
		i++;
	}
}

void	flood_fill(t_mlx_data *data, char **map, int x, int y)
{
	if ((map[x][y] != '1' && map[x][y] != 'b') && (x >= 0 && y >= 0
			&& x < data->h && y < data->w))
	{
		if (map[x][y] == 'C')
			data->collect--;
		if (map[x][y] == 'E')
			data->exit--;
		map[x][y] = 'b';
		flood_fill(data, map, x, y + 1);
		flood_fill(data, map, x, y - 1);
		flood_fill(data, map, x + 1, y);
		flood_fill(data, map, x - 1, y);
	}
}

int	un_ch(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i] != NULL)
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] != '1' && data->map[i][j] != 'C'
				&& data->map[i][j] != '0' && data->map[i][j] != 'E'
				&& data->map[i][j] != 'P')
			{
				ft_printf("Error\nUnknown character");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	render_map(t_mlx_data *data, char **map)
{
	if (invalid_map(data) == 1 || is_rectangle(data) == 1 || un_ch(data) == 1)
		return (1);
	if (closed_by_walls(data) == 1)
	{
		ft_printf("Error\nMap has to be closed by walls");
		return (1);
	}
	start_point(data, 'P');
	data->collect = times_met(data, 'C');
	data->exit = 1;
	data->h = map_height(data);
	while (data->collect != 0)
	{
		flood_fill(data, map, data->p_i, data->p_j);
		if (data->collect != 0 || data->exit != 0)
		{
			ft_printf("Error\nInvalid path");
			return (1);
		}
	}
	return (0);
}
