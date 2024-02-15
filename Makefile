# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atyurina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 13:46:31 by atyurina          #+#    #+#              #
#    Updated: 2024/01/22 13:10:03 by atyurina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Это переменная, содержащая имя исполняемого файла
NAME := so_long

# Это переменная, содержащая список  исходных файлов
SRC := main.c closing_game.c open_images.c \
	reading_map.c utils.c render_map.c render_map_dop.c\
	./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
	./ft_printf/ft_format.c ./ft_printf/ft_putnbr_base.c  \
	./ft_printf/ft_putnbr_u.c ./ft_printf/ft_putstr.c ./ft_printf/ft_printf.c  \
	./ft_printf/ft_putchar.c ./ft_printf/ft_putnbr.c ./ft_printf/ft_putptr.c \
	player_move.c ft_itoa.c ft_win.c 
# Это переменная, содержащая список ваших объектных файлов (.o), 
# полученных из исходных файлов.
OBJ := $(SRC:.c=.o) 
# Это переменная, содержащая компилятор, 
# который будет использоваться для компиляции вашего кода.
# -g включает информацию для отладчика.
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
# Это переменные, содержащие путь к библиотеке mlx и ее имя.
MLX_PATH	= minilibx-linux/
MLX_NAME	= libmlx.a
MLX		= $(MLX_PATH)$(MLX_NAME)
# Это переменная, содержащая флаг для указания 
# компилятору на путь к заголовочным файлам.
INC		= -I ./minilibx-linux/
# Эти переменные используются для определения пути к объектным файлам.
OBJ_PATH	= obj/
OBJ		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
# Цель all компилирует mlx и исполняемый файл.
all: $(MLX) $(NAME)

# Это правило компиляции .c файлов в объектные файлы (.o).
# mkdir -p $(dir $@) создаст директорию, 
# если ее нет, перед компиляцией объектного файла
$(OBJ_PATH)%.o: %.c
	@mkdir -p $(dir $@) 
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Это зависимость для объектных файлов от пути к объектам. 
# Обеспечивает создание директории, если ее нет.
$(OBJS): $(OBJ_PATH)

# Это правило создания директории для объектных файлов.
$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
# Это правило, которое компилирует mlx.
$(MLX):
	@make -sC $(MLX_PATH)
# Это правило, которое компилирует исполняемый файл.
$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) -lXext -lX11 -lm

# Цель clean удаляет все объектные файлы и вызывает make clean в mlx.
clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)

# Цель fclean удаляет все объектные файлы и исполняемый файл.
fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean
