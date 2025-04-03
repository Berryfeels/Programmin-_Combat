/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sky_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:00:44 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:00:45 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_sky_tile_b(t_game *game, t_tile_coords *coords)
{
	int		tex_x;
	int		tex_y;
	int		tex_color;
	double	angle;
	double	sky_offset;

	angle = atan2(game->player.dir_y, game->player.dir_x);
	sky_offset = (angle / (2 * M_PI)) * game->color[SKY].width;
	tex_x = ((int)((coords->x / (double)SCREEN_WIDTH) * \
		game->color[SKY].width) + (int)sky_offset) % game->color[SKY].width;
	if (tex_x < 0)
		tex_x += game->color[SKY].width;
	tex_y = (int)((coords->y / (double)(SCREEN_HEIGHT / 2)) * \
				game->color[SKY].height) % game->color[SKY].height;
	tex_color = get_cf_texture_pixel_b(game->color, tex_x, tex_y, SKY);
	my_mlx_pixel_put_b(game, coords->x, coords->y, tex_color);
}

static void	draw_sky_row_b(t_game *game, int y)
{
	int				x;
	t_tile_coords	coords;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		coords.x = x;
		coords.y = y;
		draw_sky_tile_b(game, &coords);
		x++;
	}
}

void	draw_sky_texture_b(t_game *game)
{
	int		y;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		draw_sky_row_b(game, y);
		y++;
	}
}
