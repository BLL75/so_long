/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 22:09:33 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/20 23:56:03 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	process_map_line(char *line, int y, t_vars *vars)
{
	int	x;

	x = 0;
	while (x < vars->game_map->width && line[x])
	{
		validate_map_character(line[x]);
		x++;
	}
	draw_map_elements(line, y, vars);
}

void	process_map_file(int fd, t_vars *vars)
{
	int		y;
	char	*line;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL && y < vars->game_map->height)
	{
		process_map_line(line, y, vars);
		free(line);
		y++;
		line = get_next_line(fd);
	}
}

t_map_element_node	*load_map_from_file(const char *map_file, t_vars *vars)
{
	int	fd;

	vars->game_map->elements = NULL;
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error opening map file\n", 23);
		return (NULL);
	}
	process_map_file(fd, vars);
	close(fd);
	return (vars->game_map->elements);
}
