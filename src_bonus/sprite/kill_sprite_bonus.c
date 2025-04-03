/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:00:56 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:00:57 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	is_wall_or_closed_door(t_game *game, double x, double y)
{
	const int	map_x = (int)x;
	const int	map_y = (int)y;

	if (game->map[map_y][map_x] == '1')
		return (1);
	if (game->map[map_y][map_x] == 'D')
		return (game->door[which_door(game, map_y, map_x)].door_state == 0);
	return (0);
}

static int	is_obstructed(t_game *game, t_point start, t_point end)
{
	const t_point	step = {
		.x = end.x - start.x,
		.y = end.y - start.y
	};
	const double	max_step = fmax(fabs(step.x), fabs(step.y));
	t_point			current;
	int				i;

	current = start;
	i = 0;
	while (i <= (int)max_step)
	{
		if (is_wall_or_closed_door(game, current.x, current.y))
			return (1);
		current.x += step.x / max_step;
		current.y += step.y / max_step;
		i++;
	}
	return (0);
}

static int	is_zombie_visible(t_game *game, t_point player, \
							t_point zombie)
{
	const double	range = 7.0;
	const double	min_angle = 0.3;
	const double	dx = zombie.x - player.x;
	const double	dy = zombie.y - player.y;
	const double	distance = sqrt(dx * dx + dy * dy);

	return (distance < range
		&& ((dx * game->player.dir_x + dy * game->player.dir_y) / \
			distance) > min_angle && !is_obstructed(game, player, zombie));
}

t_sprite	*get_zombie_in_front(t_game *game)
{
	int			i;
	t_point		player_pos;
	t_point		zombie_pos;

	player_pos = (t_point){game->player.x, game->player.y};
	i = -1;
	while (++i < game->sprite_count)
	{
		if (!game->sprites[i].active)
			continue ;
		zombie_pos = (t_point){game->sprites[i].x, game->sprites[i].y};
		if (is_zombie_visible(game, player_pos, zombie_pos))
			return (&game->sprites[i]);
	}
	return (NULL);
}

void	remove_zombie(t_game *game, int index)
{
	int	i;

	i = index;
	if (index < 0 || index >= game->sprite_count)
		return ;
	while (i < game->sprite_count - 1)
	{
		game->sprites[i] = game->sprites[i + 1];
		i++;
	}
	game->sprite_count--;
}
