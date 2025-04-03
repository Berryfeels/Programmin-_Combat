/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_key_tools_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:55 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:56 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	key_found(t_game *game)
{
	char	*phrase;

	if (game->player.key > 0)
	{
		phrase = "Found the Key";
		mlx_string_put(game->mlx, game->win, SCREEN_WIDTH - 150, \
			SCREEN_HEIGHT - 20, 0x660000, phrase);
		mlx_string_put(game->mlx, game->win, SCREEN_WIDTH - 150, \
				SCREEN_HEIGHT - 21, 0x660000, phrase);
	}
}

void	check_collect_key(t_game *game)
{
	int	i;
	int	key_x;
	int	key_y;

	i = -1;
	while (++i < game->key_count)
	{
		if (!game->key[i].active)
			continue ;
		key_x = (int)game->key[i].x;
		key_y = (int)game->key[i].y;
		if ((int)game->player.x == key_x && (int)game->player.y == key_y)
		{
			game->player.key += 1;
			game->key[i].active = 0;
		}
	}
}

int	calculate_transform_key(t_game *game, t_key *key, \
	double *transform_x, double *transform_y)
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;

	sprite_x = key->x - game->player.x;
	sprite_y = key->y - game->player.y;
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

void	calculate_draw_positions_key(double transform_x, \
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
