/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:31:29 by atyurina          #+#    #+#             */
/*   Updated: 2024/01/29 18:14:46 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_init(t_mlx_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		return ;
	data->win = mlx_new_window(data->mlx, data->w * 32, data->h * 32 + 20,
			"so_long");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	if (argc > 2 || argc < 2)
		ft_message_error("Error\nThere should be two argc");
	if (argc == 2)
	{
		data.map = read_map(argv[1]);
		data.map_dup = read_map(argv[1]);
		if (render_map(&data, data.map_dup) == 0)
		{
			ft_init(&data);
			open_images(&data);
			if (data.winner == 0)
			{
				mlx_hook(data.win, 17, 0, close_x, &data);
				mlx_hook(data.win, 2, 1L << 0, input, &data);
				mlx_key_hook(data.win, close_esc, &data);
				mlx_loop(data.mlx);
			}
		}
		else
			free_maps(&data);
	}
	return (0);
}
