/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 20:33:44 by bluque-l          #+#    #+#             */
/*   Updated: 2023/08/23 00:20:27 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_character_right(t_vars *vars)
{
	move_character(vars, 1, 0);
}

void	move_character_left(t_vars *vars)
{
	move_character(vars, -1, 0);
}

void	move_character_up(t_vars *vars)
{
	move_character(vars, 0, -1);
}

void	move_character_down(t_vars *vars)
{
	move_character(vars, 0, 1);
}
