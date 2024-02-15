/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:46:18 by atyurina          #+#    #+#             */
/*   Updated: 2024/01/30 12:17:41 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
The mlx_xpm_to_image function in the MiniLibX library is used
to convert XPM (X PixMap) data into an image. Here is a brief
explanation of its parameters:
1. mlx_ptr: A pointer to the MiniLibX connection.
2. xpm_data: An array of strings representing the XPM data. 
Each string in the arraytypically corresponds to a row of pixels in the image.
3. width: A pointer to an integer that will be filled 
with the width of the resulting image.
4. height: A pointer to an integer that will be filled 
with the height of the resulting image.
*/

void	set_images(t_mlx_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->h)
	{
		i = 0;
		while (i < data->w)
		{
			choose_images(data, data->map[j][i], i * 32, j * 32);
			i++;
		}
		j++;
	}
}

void	choose_images(t_mlx_data *data, char b, int x, int y)
{
	if (b == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.floor, x, y);
	if (b == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, x, y);
	if (b == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->img.collect, x, y);
	if (b == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit, x, y);
	if (b == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->img.floor, x, y);
		mlx_put_image_to_window(data->mlx, data->win, data->img.cat, x, y);
		data->p_x = x;
		data->p_y = y;
	}
}

void	open_images(t_mlx_data *data)
{
	int	img_w;
	int	img_h;

	data->img.floor = mlx_xpm_file_to_image(data->mlx, "./ims/grass32.xpm",
			&img_w, &img_h);
	data->img.cat = mlx_xpm_file_to_image(data->mlx, "./ims/cat.xpm", &img_w,
			&img_h);
	data->img.collect = mlx_xpm_file_to_image(data->mlx,
			"./ims/collectible.xpm", &img_w, &img_h);
	data->img.exit = mlx_xpm_file_to_image(data->mlx, "./ims/finish.xpm",
			&img_w, &img_h);
	data->img.wall = mlx_xpm_file_to_image(data->mlx, "./ims/wall.xpm", &img_w,
			&img_h);
	data->img.black = mlx_xpm_file_to_image(data->mlx, "./ims/black.xpm",
			&img_w, &img_h);
	set_images(data);
	data->moves = 0;
	data->winner = 0;
	mlx_string_put(data->mlx, data->win, 10, data->h * 32 + 15, 0xFFFFFF,
		"Moves:");
}
