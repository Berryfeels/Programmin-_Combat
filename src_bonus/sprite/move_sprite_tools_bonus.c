/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite_tools_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:01:05 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:01:06 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	is_wall_or_closed_door(t_game *game, int x, int y)
{
	int	door_index;

	if (game->map[y][x] == '1')
		return (1);
	if (game->map[y][x] == 'F')
		return (1);
	if (game->map[y][x] == 'D')
	{
		door_index = which_door(game, y, x);
		if (door_index == -1 || game->door[door_index].door_state == 1)
			return (1);
	}
	return (0);
}

static int	is_too_close_to_wall_or_door(t_game *game, double x, double y)
{
	double	offsets[4][2];
	int		i;
	int		new_x;
	int		new_y;

	offsets[0][0] = 0;
	offsets[0][1] = 0.3;
	offsets[1][0] = 0.3;
	offsets[1][1] = 0;
	offsets[2][0] = 0;
	offsets[2][1] = -0.3;
	offsets[3][0] = -0.3;
	offsets[3][1] = 0;
	i = -1;
	while (++i < 4)
	{
		new_x = (int)(x + offsets[i][0]);
		new_y = (int)(y + offsets[i][1]);
		if (is_wall_or_closed_door(game, new_x, new_y))
			return (1);
	}
	return (0);
}

int	can_move_sprite(t_game *game, double new_x, double new_y)
{
	if (is_wall_or_closed_door(game, (int)new_x, (int)new_y))
		return (0);
	if (is_too_close_to_wall_or_door(game, new_x, new_y))
		return (0);
	return (1);
}
