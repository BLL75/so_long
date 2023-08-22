/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 11:59:48 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/19 02:27:52 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		exit(0);
	}
	else
	{
		if (keycode == KEY_W)
			move_character_up(vars);
		else if (keycode == KEY_D)
			move_character_right(vars);
		else if (keycode == KEY_A)
			move_character_left(vars);
		else if (keycode == KEY_S)
			move_character_down(vars);
	}
	return (0);
}
