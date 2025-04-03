/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:00:40 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:00:41 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_floor_tile_b(t_game *game, t_tile_coords *coords)
{
	int	tex_color;

	tex_color = get_cf_texture_pixel_b(game->color, \
	abs((int)(coords->tile_x * game->color[FLOOR].width)) % \
	game->color[FLOOR].width, abs((int)(coords->tile_y * \
	game->color[FLOOR].height)) % game->color[FLOOR].height, FLOOR);
	my_mlx_pixel_put_b(game, coords->x, coords->y, tex_color);
}

void	draw_floor_pixel_b(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = SCREEN_HEIGHT / 2;
		while (y < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put_b(game, x, y, game->color[FLOOR].hex_color);
			y++;
		}
		x++;
	}
}

static void	draw_floor_row_b(t_game *game, int y, double step_x, double step_y)
{
	int				x;
	double			floor_x;
	double			floor_y;
	t_tile_coords	coords;

	x = 0;
	floor_x = game->player.x + \
		((0.5 * SCREEN_HEIGHT) / (y - (SCREEN_HEIGHT / 2))) * \
		(game->player.dir_x - game->player.plane_x);
	floor_y = game->player.y + \
		((0.5 * SCREEN_HEIGHT) / (y - (SCREEN_HEIGHT / 2))) * \
		(game->player.dir_y - game->player.plane_y);
	while (x < SCREEN_WIDTH)
	{
		coords.x = x;
		coords.y = y;
		coords.tile_x = floor_x;
		coords.tile_y = floor_y;
		draw_floor_tile_b(game, &coords);
		floor_x += step_x;
		floor_y += step_y;
		x++;
	}
}

void	draw_floor_texture_b(t_game *game)
{
	int		y;
	double	row_distance;
	double	step_x;
	double	step_y;

	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		row_distance = (0.5 * SCREEN_HEIGHT) / (y - (SCREEN_HEIGHT / 2));
		step_x = row_distance * (game->player.dir_x + game->player.plane_x - \
			(game->player.dir_x - game->player.plane_x)) / SCREEN_WIDTH;
		step_y = row_distance * (game->player.dir_y + game->player.plane_y - \
			(game->player.dir_y - game->player.plane_y)) / SCREEN_WIDTH;
		draw_floor_row_b(game, y, step_x, step_y);
		y++;
	}
}
