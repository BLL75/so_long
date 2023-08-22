/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 12:54:20 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/20 19:43:16 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	flood_fill(t_vars *vars, int x, int y, int **visited)
{
	t_map_element_node	*node;

	node = get_node_at_position(vars->game_map->elements, x, y);
	if (node == NULL || visited[x][y] || node->element == '1')
		return ;
	visited[x][y] = 1;
	flood_fill(vars, x + 1, y, visited);
	flood_fill(vars, x - 1, y, visited);
	flood_fill(vars, x, y + 1, visited);
	flood_fill(vars, x, y - 1, visited);
}

static void	fill_visited(t_vars *vars, int **visited)
{
	t_map_element_node	*current;

	current = vars->game_map->elements;
	while (current != NULL)
	{
		if (current->element == 'P')
		{
			flood_fill(vars, current->x, current->y, visited);
			break ;
		}
		current = current->next;
	}
}

static void	free_visited(int **visited, int width)
{
	if (width == 0)
		return ;
	free(visited[width - 1]);
	free_visited(visited, width - 1);
}

static int	check_nodes(t_vars *vars, int **visited)
{
	t_map_element_node	*current;

	current = vars->game_map->elements;
	while (current != NULL)
	{
		if ((current->element == 'C' || current->element == 'E')
			&& !visited[current->x][current->y])
		{
			printf("Inaccessible node found\n");
			return (0);
		}
		current = current->next;
	}
	return (1);
}

int	is_accessible(t_vars *vars)
{
	int	**visited;
	int	i;
	int	result;

	visited = malloc(vars->game_map->width * sizeof(int *));
	i = 0;
	while (i < vars->game_map->width)
	{
		visited[i] = calloc(vars->game_map->height, sizeof(int));
		i++;
	}
	fill_visited(vars, visited);
	result = check_nodes(vars, visited);
	free_visited(visited, vars->game_map->width);
	free(visited);
	return (result);
}
