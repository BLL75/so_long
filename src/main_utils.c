/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:51:54 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/22 23:06:52 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_images(t_images *images)
{
	if (images == NULL)
	{
		write(1, "Error:\n", 6);
		write(1, "Failed to initialize graphics.\n", 31);
		return (0);
	}
	return (1);
}

int	check_arguments(int ac)
{
	if (ac != 2)
	{
		write(1, "Error:\n", 6);
		write(1, "Usage: <map_file>\n", 18);
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
		write(1, "Error:\n", 6);
		write(1, "Map validation failed.\n", 22);
		return (0);
	}
	mlx_key_hook(vars->win_ptr, key_press, vars);
	mlx_hook(vars->win_ptr, 17, 0, &close_program, NULL);
	mlx_loop(vars->mlx_ptr);
	return (1);
}
