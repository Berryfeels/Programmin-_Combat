/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_tools_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:56:02 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:56:03 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	which_door(t_game *game, double world_y, double world_x)
{
	int	map_x;
	int	map_y;
	int	i;

	if (!game || !game->door)
		return (-1);
	map_x = (int)world_x;
	map_y = (int)world_y;
	i = 0;
	while (i < game->door_count)
	{
		if (game->door[i].x == map_x && game->door[i].y == map_y)
			return (i);
		i++;
	}
	return (-1);
}

static int	check_door(t_game *game, int new_x, int new_y)
{
	int	door_index;

	if (new_y >= 0 && new_y < game->height
		&& new_x >= 0 && new_x < game->width)
	{
		if (game->map[new_y][new_x] == 'D')
		{
			door_index = which_door(game, new_y, new_x);
			if (door_index != -1)
				return (door_index);
		}
	}
	return (-1);
}

static int	is_zombie_inside_door(t_game *game, int index)
{
	int	i;
	int	z_x;
	int	z_y;

	i = 0;
	while (i < game->sprite_count)
	{
		if (!game->sprites[i].active)
		{
			i++;
			continue ;
		}
		z_x = (int)game->sprites[i].x;
		z_y = (int)game->sprites[i].y;
		if (z_x == game->door[index].x && \
			z_y == game->door[index].y)
			return (1);
		i++;
	}
	return (0);
}

int	is_door_b(t_game *game)
{
	int	px;
	int	py;
	int	offsets[4][2];
	int	i;
	int	door_index;

	px = (int)game->player.x;
	py = (int)game->player.y;
	offsets[0][0] = 0;
	offsets[0][1] = 1;
	offsets[1][0] = 1;
	offsets[1][1] = 0;
	offsets[2][0] = 0;
	offsets[2][1] = -1;
	offsets[3][0] = -1;
	offsets[3][1] = 0;
	i = -1;
	while (++i < 4)
	{
		door_index = check_door(game, px + offsets[i][0], py + offsets[i][1]);
		if (door_index != -1)
			return (door_index);
	}
	return (-1);
}

void	door_door(t_game *game)
{
	int	index;

	index = is_door_b(game);
	if (index != -1 && !is_zombie_inside_door(game, index))
		change_door_state(game, index);
	if (is_final_door(game) && game->player.key > 0)
	{
		victory();
		close_window_b(game);
	}
}
