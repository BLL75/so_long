/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_maps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:25:36 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/22 23:06:39 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

int	validate_rows(t_vars *vars)
{
	int						width;
	t_map_element_node		*current;
	t_map_element_node		*node;
	int						y;
	int						x;

	width = vars->game_map->width;
	current = vars->game_map->elements;
	y = 0;
	while (y < vars->game_map->height)
	{
		x = 0;
		while (x < width)
		{
			node = get_node_at_position(current, x, y);
			if (node == NULL || node->element != '1')
				return (0);
			x++;
		}
		if (y == 0)
			y = vars->game_map->height - 1;
		else
			break ;
	}
	return (1);
}

int	validate_columns(t_vars *vars)
{
	int						height;
	t_map_element_node		*current;
	t_map_element_node		*node;
	int						x;
	int						y;

	height = vars->game_map->height;
	current = vars->game_map->elements;
	x = 0;
	while (x < vars->game_map->width)
	{
		y = 0;
		while (y < height)
		{
			node = get_node_at_position(current, x, y);
			if (node == NULL || node->element != '1')
				return (0);
			y++;
		}
		if (x == 0)
			x = vars->game_map->width - 1;
		else
			break ;
	}
	return (1);
}

int	validate_walls(t_vars *vars)
{
	if (!validate_rows(vars) || !validate_columns(vars))
	{
		write(1, "Error:\n", 6);
		write(1, "The map must be surrounded by walls\n", 36);
		return (0);
	}
	return (1);
}

int	validate_player_and_exit(t_vars *vars)
{
	int						player_count;
	int						exit_count;
	t_map_element_node		*current;

	player_count = 0;
	exit_count = 0;
	current = vars->game_map->elements;
	while (current != NULL)
	{
		if (current->element == 'P')
			player_count++;
		if (current->element == 'E')
			exit_count++;
		current = current->next;
	}
	if (player_count != 1 || exit_count != 1)
	{
		write(1, "Error\n", 6);
		write(1, "Only 1 P and 1 E\n", 17);
		return (0);
	}
	return (1);
}

int	validate_map(t_vars *vars)
{
	if (!validate_player_and_exit(vars))
	{
		write(1, "Error\n", 6);
		write(1, "Min 1 player - 1 exit.\n", 23);
		exit(EXIT_FAILURE);
	}
	if (!validate_walls(vars))
	{
		write(1, "Error\n", 6);
		write(1, "Map not surrounded by walls\n", 28);
		exit(EXIT_FAILURE);
	}
	if (!is_accessible(vars))
	{
		write(1, "Error\n", 6);
		write(1, "Accessibility error in object or exit.\n", 39);
		exit(EXIT_FAILURE);
	}
	return (1);
}
