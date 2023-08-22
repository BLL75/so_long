/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_operations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:07:28 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/23 00:15:30 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	check_images_load(t_images images[], void *mlx_ptr)
{
	int	i;

	i = 0;
	while (images[i].character)
	{
		if (images[i].image == NULL)
		{
			cleanup_images(images, mlx_ptr);
			write(2, "Error loading image\n", 19);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	load_images(t_images images[], void *mlx_ptr, int *width, int *height)
{
	images[0] = (t_images){'0', mlx_xpm_file_to_image(mlx_ptr,
			"./textures/sand.xpm", width, height)};
	images[1] = (t_images){'1', mlx_xpm_file_to_image(mlx_ptr,
			"./textures/wall.xpm", width, height)};
	images[2] = (t_images){'C', mlx_xpm_file_to_image(mlx_ptr,
			"./textures/box_1_1.xpm", width, height)};
	images[3] = (t_images){'E', mlx_xpm_file_to_image(mlx_ptr,
			"./textures/helicopter.xpm", width, height)};
	images[4] = (t_images){'P', mlx_xpm_file_to_image(mlx_ptr,
			"./textures/player.xpm", width, height)};
	images[5] = (t_images){0, NULL};
	check_images_load(images, mlx_ptr);
}

t_images	*init_graphics(t_vars *vars, char *title, char *map_file)
{
	int			width;
	int			height;
	t_images	*images;

	vars->game_map = allocate_game_map();
	measure_map_size(map_file, &vars->game_map->width,
		&vars->game_map->height);
	vars->mlx_ptr = mlx_init();
	if (!(vars->mlx_ptr))
	{
		write(1, "Error initializing graphics library\n", 36);
		free(vars->game_map);
		return (NULL);
	}
	vars->win_ptr = mlx_new_window(vars->mlx_ptr, vars->game_map->width
			* TILE_SIZE, vars->game_map->height
			* TILE_SIZE, title);
	if (!(vars->win_ptr))
		result_null(vars);
	images = malloc(sizeof(t_images) * 7);
	if (images == NULL)
		result_null(vars);
	load_images(images, vars->mlx_ptr, &width, &height);
	return (images);
}

t_map	init_map(t_map_element_node *head, int map_width, int map_height)
{
	t_map	game_map;

	game_map.elements = head;
	game_map.width = map_width;
	game_map.height = map_height;
	game_map.move_count = 1;
	game_map.collectible_num = 0;
	return (game_map);
}

void	refresh_map(t_map_element_node *head,
		t_images *images, void *mlx_ptr, void *win_ptr)
{
	t_map_element_node	*current;
	t_images			*current_image;

	mlx_clear_window(mlx_ptr, win_ptr);
	current = head;
	while (current != NULL)
	{
		current_image = images;
		while (current_image->character)
		{
			if (current_image->character == current->element)
			{
				mlx_put_image_to_window(mlx_ptr, win_ptr,
					current_image->image,
					current->x * TILE_SIZE,
					current->y * TILE_SIZE);
				break ;
			}
			current_image++;
		}
		current = current->next;
	}
}
