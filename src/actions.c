/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 12:06:42 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/22 23:38:16 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

void	check_exit(t_vars *vars)
{
	if (vars->game_map->collectible_num == 0)
		activate_exit(vars);
}

void	activate_exit(t_vars *vars)
{	
	int					collectible;
	t_map_element_node	*elements;

	collectible = 0;
	elements = vars->game_map->elements;
	while (elements != NULL)
	{
		if (elements->element == 'E')
		{
			collectible = 1;
			elements->is_collectible = collectible;
			return ;
		}
		elements = elements->next;
	}
}

void	validate_map_character(char character)
{
	if (!is_valid_character(character))
	{
		write(1, "Error\n", 6);
		write(1, "Carácter no válido\n", 26);
		exit(EXIT_FAILURE);
	}
}

void	cleanup(t_vars *vars)
{
	int					i;
	t_map_element_node	*current;
	t_map_element_node	*next;

	i = 0;
	current = vars->game_map->elements;
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	while (vars->images[i].character != '\0')
	{
		if (vars->images[i].image)
			mlx_destroy_image(vars->mlx_ptr, vars->images[i].image);
		i++;
	}
	free(vars->images);
	while (current)
	{
		next = current->next;
		free(current);
		current = NULL;
		current = next;
	}
}

int	count_collectibles(t_map_element_node *elements)
{
	int						count;
	t_map_element_node		*current;

	count = 0;
	current = elements;
	while (current != NULL)
	{
		if (current->element == 'C' && current->is_collectible == 1)
			count++;
		current = current->next;
	}
	return (count);
}
