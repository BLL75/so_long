/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:59:59 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/22 23:01:44 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initialize_new_node(t_map_element_node *new_node,
		char element,
		int x,
		int y)
{
	new_node->element = element;
	new_node->x = x;
	new_node->y = y;
	new_node->next = NULL;
	if (element == 'C')
		new_node->is_collectible = 1;
	else
		new_node->is_collectible = 0;
}

t_map_element_node	*insert_new_node(t_map_element_node *head,
				t_map_element_node *new_node)
{
	t_map_element_node	*current;

	if (head == NULL)
		head = new_node;
	else
	{
		current = head;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
	return (head);
}

void	create_and_insert_node(t_vars *vars,
		char element,
		int x,
		int y)
{
	t_map_element_node	*new_node;

	new_node = (t_map_element_node *)malloc(sizeof(t_map_element_node));
	if (new_node == NULL)
	{
		write(1, "Error:\n", 6);
		write(1, "Error allocating memory\n", 24);
		exit(EXIT_FAILURE);
	}
	initialize_new_node(new_node, element, x, y);
	vars->game_map->elements = insert_new_node
		(vars->game_map->elements, new_node);
}

void	draw_map_elements(char *line, int y, t_vars *vars)
{
	t_images	*current_image;
	int			x;

	x = 0;
	while (line[x] && x < vars->game_map->width)
	{
		current_image = vars->images;
		while (current_image->character)
		{
			if (current_image->character == line[x])
			{
				mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
					current_image->image, x * TILE_SIZE, y * TILE_SIZE);
				create_and_insert_node(vars, line[x], x, y);
				break ;
			}
			current_image++;
		}
		x++;
	}
}
