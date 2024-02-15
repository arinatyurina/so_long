/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:59:14 by atyurina          #+#    #+#             */
/*   Updated: 2024/01/29 18:17:15 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//  s_ is used as a prefix for structure (struct) tags. For example,
//	s_prog is a structure tag.
//  t_ is used as a prefix for typedef names. For example,
//	t_map and t_name are typedef names.

#ifndef HEADER_H
# define HEADER_H

# define MALLOC_ERROR 1

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# include "./ft_printf/ft_printf.h"
# include "./gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_img
{
	void	*floor;
	void	*wall;
	void	*collect;
	void	*exit;
	void	*cat;
	void	*black;
	void	*red;
	void	*win_pic;
}			t_img;

typedef struct s_mlx_data
{
	void	*mlx;
	void	*win;
	void	*mlx_n;
	void	*win_n;
	char	**map;
	char	**map_dup;
	int		h;
	int		w;
	int		p_i;
	int		p_j;
	int		p_x;
	int		p_y;
	int		active_img;
	int		moves;
	int		collect;
	int		exit;
	int		winner;
	t_img	img;
}			t_mlx_data;

int			close_x(t_mlx_data *data);
int			close_esc(int keysym, t_mlx_data *data);
void		open_images(t_mlx_data *data);
void		set_images(t_mlx_data *data);
char		**read_map(char *file);
void		read_maps(char *str, t_mlx_data *data);
void		set_images(t_mlx_data *data);
void		choose_images(t_mlx_data *data, char b, int x, int y);

void		free_map(t_mlx_data *data);
void		free_map_dup(t_mlx_data *data);
void		free_maps(t_mlx_data *data);
char		*ft_strdup(const char *s);
char		**ft_split(char const *s, char c);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjoin(char const *s1, char const *s2);

int			render_map(t_mlx_data *data, char **map);
int			invalid_map(t_mlx_data *data);
int			times_met(t_mlx_data *data, char a);
int			map_height(t_mlx_data *data);
int			is_rectangle(t_mlx_data *data);
int			closed_by_walls(t_mlx_data *data);
int			is_wall(int x, int y, t_mlx_data *data);
int			is_collectable(int x, int y, t_mlx_data *data);
int			is_exit(int x, int y, t_mlx_data *data);
void		flood_fill(t_mlx_data *data, char **map, int x, int y);
void		free_map_dup(t_mlx_data *data);
int			ft_strlen_map(char *str);
int			un_ch(t_mlx_data *data);

void		player_move(t_mlx_data *data, int new_x, int new_y);
int			input(int keysym, t_mlx_data *data);
void		print_moves(t_mlx_data *data);
void		move_pics(t_mlx_data *data, int new_x, int new_y);

char		*ft_itoa(int n);

void		ft_init(t_mlx_data *data);
void		ft_message_error(char *str);

void		ft_win(t_mlx_data *data);
void		destroy_all(t_mlx_data *data);
int			close_x_win(t_mlx_data *data);
int			close_esc_win(int keysym, t_mlx_data *data);

#endif
