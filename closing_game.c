/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closing_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:38:53 by atyurina          #+#    #+#             */
/*   Updated: 2024/01/17 14:04:45 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_map(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
}

void	free_map_dup(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (data->map_dup[i] != NULL)
	{
		free(data->map_dup[i]);
		i++;
	}
	free(data->map_dup);
}

void	free_maps(t_mlx_data *data)
{
	free_map(data);
	free_map_dup(data);
}

int	close_x(t_mlx_data *data)
{
	if (data->winner == 0)
	{
		mlx_destroy_image(data->mlx, data->img.floor);
		mlx_destroy_image(data->mlx, data->img.cat);
		mlx_destroy_image(data->mlx, data->img.collect);
		mlx_destroy_image(data->mlx, data->img.exit);
		mlx_destroy_image(data->mlx, data->img.wall);
		mlx_destroy_image(data->mlx, data->img.black);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_map(data);
		free_map_dup(data);
		exit(0);
	}
	return (0);
}

int	close_esc(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape && data->winner == 0)
	{
		mlx_destroy_image(data->mlx, data->img.floor);
		mlx_destroy_image(data->mlx, data->img.cat);
		mlx_destroy_image(data->mlx, data->img.collect);
		mlx_destroy_image(data->mlx, data->img.exit);
		mlx_destroy_image(data->mlx, data->img.wall);
		mlx_destroy_image(data->mlx, data->img.black);
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		free_map(data);
		free_map_dup(data);
		exit(0);
	}
	return (0);
}
