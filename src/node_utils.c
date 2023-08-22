/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 13:28:13 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/20 23:46:43 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

t_map_element_node	*get_node_at_position(t_map_element_node *head,
	int x, int y)
{
	t_map_element_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->x == x && current->y == y)
			return (current);
		current = current->next;
	}
	return (NULL);
}

t_map_element_node	*get_exit_node(t_map_element_node *head)
{
	t_map_element_node	*node;

	node = head;
	while (node)
	{
		if (node->element == 'E')
			return (node);
		node = node->next;
	}
	return (NULL);
}

t_map_element_node	*find_player_node(t_map_element_node *head)
{
	t_map_element_node	*current;

	current = head;
	while (current != NULL)
	{
		if (current->element == 'P')
			return (current);
		current = current->next;
	}
	return (NULL);
}
