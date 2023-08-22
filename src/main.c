/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:59:54 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/22 23:01:01 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include "../libft/libft.h"

int	initialize_game(t_vars *vars, char *map_file, char *title)
{
	vars->images = init_graphics(vars, title, map_file);
	if (!check_images(vars->images))
		return (1);
	vars->game_map->elements = load_map_from_file(map_file, vars);
	if (vars->game_map->elements == NULL)
	{
		write(1, "Error:\n", 6);
		write(1, "Failed to load map from file.\n", 30);
		return (1);
	}
	*vars->game_map = init_map(vars->game_map->elements,
			vars->game_map->width,
			vars->game_map->height);
	return (0);
}

void	initialize_vars(t_vars *vars)
{
	vars->mlx_ptr = NULL;
	vars->win_ptr = NULL;
	vars->game_map = NULL;
	vars->images = NULL;
}

int	main(int ac, char **av)
{
	t_vars	vars;
	char	*title;
	char	*map_file;

	title = "So_Long";
	if (!check_arguments(ac))
		return (1);
	initialize_vars(&vars);
	map_file = av[1];
	if (initialize_game(&vars, map_file, title))
		return (1);
	validate_and_run_game(&vars);
	cleanup(&vars);
	return (0);
}
