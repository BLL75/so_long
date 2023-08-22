/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:51:54 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/20 23:55:13 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_images(t_images *images)
{
	if (images == NULL)
	{
		write(1, "Error: Failed to initialize graphics.\n", 38);
		return (0);
	}
	return (1);
}

int	check_arguments(int ac)
{
	if (ac != 2)
	{
		write(2, "Usage: <map_file>\n", 19);
		return (0);
	}
	return (1);
}

int	validate_and_run_game(t_vars *vars)
{
	vars->game_map->collectible_num = count_collectibles
		(vars->game_map->elements);
	if (!validate_map(vars))
	{
		write(2, "Error: Map validation failed.\n", 29);
		return (0);
	}
	mlx_key_hook(vars->win_ptr, key_press, vars);
	mlx_hook(vars->win_ptr, 17, 0, &close_program, NULL);
	mlx_loop(vars->mlx_ptr);
	return (1);
}
