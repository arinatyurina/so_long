/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 13:48:50 by atyurina          #+#    #+#             */
/*   Updated: 2024/01/29 18:15:54 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	destroy_all(t_mlx_data *data)
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
}

void	ft_win(t_mlx_data *data)
{
	int	img_w;
	int	img_h;

	data->winner = 1;
	destroy_all(data);
	data->mlx_n = mlx_init();
	if (data->mlx_n == NULL)
		return ;
	data->win_n = mlx_new_window(data->mlx_n, 400, 400, "Congratulations!");
	if (data->win_n == NULL)
	{
		mlx_destroy_display(data->mlx_n);
		free(data->mlx_n);
		return ;
	}
	data->img.win_pic = mlx_xpm_file_to_image(data->mlx_n, "./ims/win_pic.xpm",
			&img_w, &img_h);
	mlx_put_image_to_window(data->mlx_n, data->win_n, data->img.win_pic, 0, 0);
	mlx_hook(data->win_n, 17, 0, close_x_win, data);
	mlx_key_hook(data->win_n, close_esc_win, data);
	mlx_loop(data->mlx_n);
}

int	close_x_win(t_mlx_data *data)
{
	if (data->mlx_n != NULL)
	{
		mlx_destroy_image(data->mlx_n, data->img.win_pic);
		mlx_destroy_window(data->mlx_n, data->win_n);
		mlx_destroy_display(data->mlx_n);
		free(data->mlx_n);
		exit(0);
	}
	return (0);
}

int	close_esc_win(int keysym, t_mlx_data *data)
{
	if (keysym == XK_Escape && (data->mlx_n != NULL))
	{
		mlx_destroy_image(data->mlx_n, data->img.win_pic);
		mlx_destroy_window(data->mlx_n, data->win_n);
		mlx_destroy_display(data->mlx_n);
		free(data->mlx_n);
		exit(0);
	}
	return (0);
}
