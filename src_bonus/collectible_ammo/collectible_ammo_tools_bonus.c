/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_ammo_tools_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:42 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:43 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	calculate_transform_c_ammo(t_game *game, t_c_ammo *c_ammo, \
	double *transform_x, double *transform_y)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = c_ammo->x - game->player.x;
	sprite_y = c_ammo->y - game->player.y;
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

void	calculate_draw_positions_c_ammo(double transform_x, \
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

void	check_collect_ammo(t_game *game)
{
	int	i;
	int	c_ammo_x;
	int	c_ammo_y;

	i = 0;
	while (i < game->c_ammo_count)
	{
		if (!game->c_ammo[i].active)
		{
			i++;
			continue ;
		}
		c_ammo_x = (int)game->c_ammo[i].x;
		c_ammo_y = (int)game->c_ammo[i].y;
		if ((int)game->player.x == c_ammo_x && \
			(int)game->player.y == c_ammo_y && game->player.ammo < 6)
		{
			game->player.ammo += 3;
			if (game->player.ammo > 6)
				game->player.ammo = 6;
			game->c_ammo[i].active = 0;
		}
		i++;
	}
}
