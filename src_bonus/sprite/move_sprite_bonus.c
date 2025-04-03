/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sprite_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:01:01 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:01:02 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	normalize_dir(double *dir_x, double *dir_y)
{
	double	length;

	length = sqrt((*dir_x) * (*dir_x) + (*dir_y) * (*dir_y));
	if (length == 0)
		return ;
	*dir_x /= length;
	*dir_y /= length;
}

static void	update_sprite_pos(t_game *game, int i, double dir_x, double dir_y)
{
	double	next_x;
	double	next_y;
	double	move_step;

	move_step = 0.01;
	next_x = game->sprites[i].x + dir_x * move_step;
	next_y = game->sprites[i].y + dir_y * move_step;
	if (can_move_sprite(game, next_x, game->sprites[i].y))
		game->sprites[i].x = next_x;
	if (can_move_sprite(game, game->sprites[i].x, next_y))
		game->sprites[i].y = next_y;
}

void	move_sprites(t_game *game)
{
	int		i;
	double	dir_x;
	double	dir_y;

	i = 0;
	while (i < game->sprite_count)
	{
		dir_x = game->player.x - game->sprites[i].x;
		dir_y = game->player.y - game->sprites[i].y;
		normalize_dir(&dir_x, &dir_y);
		update_sprite_pos(game, i, dir_x, dir_y);
		i++;
	}
}
