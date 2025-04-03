/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceiling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:00:36 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:00:37 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_ceiling_pixel_b(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT / 2)
		{
			my_mlx_pixel_put_b(game, x, y, game->color[CEILING].hex_color);
			y++;
		}
		x++;
	}
}

void	draw_ceiling_tile_b(t_game *game, t_tile_coords *coords)
{
	int	tex_color;

	tex_color = get_cf_texture_pixel_b(game->color, \
	abs((int)(coords->tile_x * game->color[CEILING].width)) % \
	game->color[CEILING].width, abs((int)(coords->tile_y * \
	game->color[CEILING].height)) % game->color[CEILING].height, CEILING);
	my_mlx_pixel_put_b(game, coords->x, coords->y, tex_color);
}

void	draw_ceiling_row_b(t_game *game, int y, double step_x, double step_y)
{
	int				x;
	double			ceil_x;
	double			ceil_y;
	t_tile_coords	coords;

	x = 0;
	ceil_x = game->player.x + \
		((0.5 * SCREEN_HEIGHT) / ((SCREEN_HEIGHT / 2) - y)) * \
		(game->player.dir_x - game->player.plane_x);
	ceil_y = game->player.y + \
		((0.5 * SCREEN_HEIGHT) / ((SCREEN_HEIGHT / 2) - y)) * \
		(game->player.dir_y - game->player.plane_y);
	while (x < SCREEN_WIDTH)
	{
		coords.x = x;
		coords.y = y;
		coords.tile_x = ceil_x;
		coords.tile_y = ceil_y;
		draw_ceiling_tile_b(game, &coords);
		ceil_x += step_x;
		ceil_y += step_y;
		x++;
	}
}

void	draw_ceiling_texture_b(t_game *game)
{
	int		y;
	double	row_distance;
	double	step_x;
	double	step_y;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		row_distance = (0.5 * SCREEN_HEIGHT) / ((SCREEN_HEIGHT / 2) - y);
		step_x = row_distance * (game->player.dir_x + game->player.plane_x - \
			(game->player.dir_x - game->player.plane_x)) / SCREEN_WIDTH;
		step_y = row_distance * (game->player.dir_y + game->player.plane_y - \
			(game->player.dir_y - game->player.plane_y)) / SCREEN_WIDTH;
		draw_ceiling_row_b(game, y, step_x, step_y);
		y++;
	}
}
