/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:32:19 by atyurina          #+#    #+#             */
/*   Updated: 2024/01/29 18:21:40 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_moves(t_mlx_data *data)
{
	char	*str;

	str = ft_itoa(data->moves);
	mlx_put_image_to_window(data->mlx, data->win, data->img.black, 50, data->h
		* 32);
	mlx_string_put(data->mlx, data->win, 50, data->h * 32 + 15, 0xFFFFFF, str);
	free(str);
}

void	move_pics(t_mlx_data *data, int new_x, int new_y)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img.floor, data->p_x,
		data->p_y);
	data->p_x = new_x;
	data->p_y = new_y;
	mlx_put_image_to_window(data->mlx, data->win, data->img.cat, data->p_x,
		data->p_y);
	data->moves++;
	print_moves(data);
}

void	player_move(t_mlx_data *data, int new_x, int new_y)
{
	if ((new_x >= 0 && new_x < data->w * 32 && new_y >= 0 && new_y < data->h
			* 32) && data->map[new_y / 32][new_x / 32] != '1')
	{
		if (data->map[new_y / 32][new_x / 32] == 'C')
			data->map[new_y / 32][new_x / 32] = '0';
		if (data->map[new_y / 32][new_x / 32] == 'E')
		{
			if (times_met(data, 'C') != 0)
			{
				ft_printf("You can't go to exit. Collectibles left!\n");
				return ;
			}
			else
			{
				move_pics(data, new_x, new_y);
				ft_printf("You won!\n");
				ft_win(data);
			}
		}
		move_pics(data, new_x, new_y);
	}
}

int	input(int keysym, t_mlx_data *data)
{
	int	new[2];

	new[0] = data->p_x;
	new[1] = data->p_y;
	if (keysym == KEY_LEFT || keysym == KEY_A)
	{
		new[0] -= 32;
		player_move(data, new[0], new[1]);
	}
	else if (keysym == KEY_RIGHT || keysym == KEY_D)
	{
		new[0] += 32;
		player_move(data, new[0], new[1]);
	}
	else if (keysym == KEY_UP || keysym == KEY_W)
	{
		new[1] -= 32;
		player_move(data, new[0], new[1]);
	}
	else if (keysym == KEY_DOWN || keysym == KEY_S)
	{
		new[1] += 32;
		player_move(data, new[0], new[1]);
	}
	return (1);
}
