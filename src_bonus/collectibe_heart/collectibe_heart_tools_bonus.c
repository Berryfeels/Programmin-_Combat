/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibe_heart_tools_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:21 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:22 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	calculate_transform_heart(t_game *game, t_heart *heart, \
	double *transform_x, double *transform_y)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = heart->x - game->player.x;
	sprite_y = heart->y - game->player.y;
	inv_det = 1.0 / (game->player.plane_x * game->player.dir_y
			- game->player.dir_x * game->player.plane_y);
	*transform_x = inv_det * (game->player.dir_y * sprite_x
			- game->player.dir_x * sprite_y);
	*transform_y = inv_det * (-game->player.plane_y * sprite_x
			+ game->player.plane_x * sprite_y);
	if (*transform_y <= 0)
		return (0);
	return (1);
}

void	calculate_draw_positions_heart( double transform_x, \
	double transform_y, t_draw *draw)
{
	double	scale;

	scale = 0.15;
	draw->screen_x = (int)((SCREEN_WIDTH / 2)
			* (1 + transform_x / transform_y));
	draw->height = abs((int)(SCREEN_HEIGHT / transform_y)) * scale;
	draw->width = abs((int)(SCREEN_WIDTH / transform_y)) * scale;
	draw->start_y = SCREEN_HEIGHT / 2 + 20;
	draw->end_y = draw->start_y + draw->height;
	draw->start_x = draw->screen_x - draw->width / 2;
	draw->end_x = draw->screen_x + draw->width / 2;
}

void	check_collect_hearts(t_game *game)
{
	int	i;
	int	heart_x;
	int	heart_y;

	i = 0;
	while (i < game->heart_count)
	{
		if (!game->heart[i].active)
		{
			i++;
			continue ;
		}
		heart_x = (int)game->heart[i].x;
		heart_y = (int)game->heart[i].y;
		if ((int)game->player.x == heart_x && \
			(int)game->player.y == heart_y && game->player.health < 100)
		{
			game->player.health += 20;
			if (game->player.health > 100)
				game->player.health = 100;
			game->heart[i].active = 0;
		}
		i++;
	}
}
