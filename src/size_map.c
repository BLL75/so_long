/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:09:26 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/20 23:59:21 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

int	is_valid_character(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C');
}

static void	check_square_map(int map_width, int map_height)
{
	if (map_width == map_height)
	{
		printf("Error: Square Map\n");
		exit(EXIT_SUCCESS);
	}
}

void	measure_line_and_count(int *width, int *height, char *line)
{
	int	line_length;

	line_length = 0;
	while (line[line_length])
		line_length++;
	if (line_length > *width)
		*width = line_length;
	(*height)++;
	free(line);
}

void	measure_map_size(const char *map_file, int *map_width, int *map_height)
{
	int		width;
	int		height;
	char	*line;
	int		fd;

	fd = open(map_file, O_RDONLY);
	width = 0;
	height = 0;
	if (fd < 0)
	{
		write(2, "Error opening map file\n", 23);
		return ;
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		measure_line_and_count(&width, &height, line);
		line = get_next_line(fd);
	}
	close(fd);
	*map_width = width - 1;
	*map_height = height;
	check_square_map(*map_width, *map_height);
}
