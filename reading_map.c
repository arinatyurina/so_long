/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atyurina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 13:27:38 by atyurina          #+#    #+#             */
/*   Updated: 2024/01/29 18:37:20 by atyurina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <fcntl.h>

void	ft_message_error(char *str)
{
	ft_printf("%s", str);
	exit(1);
}

static void	check_map_empty(char *map)
{
	if (map[0] == '\0')
		ft_message_error("Map is empty");
}

static char	*read_file_contents(int fd)
{
	char	*line;
	char	*all_lines;
	char	*tmp;

	all_lines = ft_strdup("");
	if (all_lines == NULL)
		ft_message_error("Malloc error");
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
		{
			free(line);
			break ;
		}
		tmp = ft_strjoin(all_lines, line);
		free(all_lines);
		all_lines = tmp;
		free(line);
	}
	return (all_lines);
}

static char	**split_lines(char *all_lines)
{
	char	**spt;

	spt = ft_split(all_lines, '\n');
	free(all_lines);
	return (spt);
}

char	**read_map(char *file)
{
	int		fd;
	char	*all_lines;
	char	**spt;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_message_error("Error while opening fd");
	all_lines = read_file_contents(fd);
	close(fd);
	check_map_empty(all_lines);
	spt = split_lines(all_lines);
	return (spt);
}

/*
char	**read_map(char *file)
{
	char	*line;
	char	*all_lines;
	int		i;
	int		fd;
	char	*tmp;
	char	**spt;

	i = 0;
	line = "";
	all_lines = ft_strdup("");
	if (all_lines == NULL)
		ft_message_error("Malloc error");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_message_error("Error while opening fd");
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		tmp = ft_strjoin(all_lines, line);
		free(all_lines);
		all_lines = tmp;
		free(line);
		i++;
	}
	free(line);
	close(fd);
	if (all_lines[0] == '\0')
		ft_message_error("Map is empty");
	spt = ft_split(all_lines, '\n');
	free(all_lines);
	return (spt);
}
*/