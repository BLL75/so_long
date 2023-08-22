/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:22:17 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/23 00:21:39 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_win_condition(t_vars *vars)
{
	cleanup(vars);
	write(1, "¡Has ganado! con : ", 20);
	ft_putnbr(vars->game_map->move_count++);
	write(1, " movimientos\n", 13);
	exit(0);
}

void	handle_move(t_vars *vars, t_map_element_node *player_node,
			t_map_element_node *destination_node)
{
	if (destination_node->is_collectible == 1)
		vars->game_map->collectible_num--;
	player_node->element = '0';
	player_node->is_collectible = 0;
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->images[0].image, player_node->x * TILE_SIZE,
		player_node->y * TILE_SIZE);
	destination_node->element = 'P';
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr, vars->images[4].image,
		destination_node->x * TILE_SIZE,
		destination_node->y * TILE_SIZE);
	write(1, "Número de movimientos: ", 23);
	ft_putnbr(vars->game_map->move_count++);
	write(1, "\n", 1);
}

void	move_character(t_vars *vars, int dx, int dy)
{
	t_map_element_node	*player_node;
	t_map_element_node	*destination_node;
	int					player_x;
	int					player_y;

	player_node = find_player_node(vars->game_map->elements);
	player_x = player_node->x;
	player_y = player_node->y;
	destination_node = get_node_at_position(vars->game_map->elements,
			player_x + dx, player_y + dy);
	if (destination_node && destination_node->element == 'E'
		&& vars->game_map->collectible_num == 0)
		handle_win_condition(vars);
	else if (destination_node && (destination_node->element == '0'
			|| destination_node->is_collectible == 1))
		handle_move(vars, player_node, destination_node);
	refresh_map(vars->game_map->elements, vars->images,
		vars->mlx_ptr, vars->win_ptr);
}
