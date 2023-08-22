/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:56:52 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/20 23:54:22 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	result_null(t_vars *vars)
{
	write(2, "Error in graphics operations\n", 29);
	mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
	mlx_destroy_display(vars->mlx_ptr);
	free(vars->mlx_ptr);
	free(vars->game_map);
}

t_map	*allocate_game_map(void)
{
	t_map	*game_map;

	game_map = malloc(sizeof(t_map));
	if (game_map == NULL)
	{
		write(2, "Error: Failed to allocate memory for game_map\n", 45);
		exit(EXIT_FAILURE);
	}
	return (game_map);
}

void	cleanup_images(t_images images[], void *mlx_ptr)
{
	int	i;

	i = 0;
	while (images[i].character)
	{
		if (images[i].image != NULL)
			mlx_destroy_image(mlx_ptr, images[i].image);
		i++;
	}
}
