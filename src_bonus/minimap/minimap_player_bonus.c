/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_player_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:57:58 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:57:59 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_player_limits(t_bounds *bounds, int max_w, int max_h)
{
	if (bounds->start_x < 0)
	{
		bounds->end_x += -bounds->start_x;
		bounds->start_x = 0;
	}
	if (bounds->end_x > max_w)
	{
		bounds->start_x -= (bounds->end_x - max_w);
		bounds->end_x = max_w;
	}
	if (bounds->start_y < 0)
	{
		bounds->end_y += -bounds->start_y;
		bounds->start_y = 0;
	}
	if (bounds->end_y > max_h)
	{
		bounds->start_y -= (bounds->end_y - max_h);
		bounds->end_y = max_h;
	}
}

static	void	draw_player_tile_b(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	screen_x;
	int	screen_y;
	int	tile_size;

	tile_size = game->minimap.tile_size;
	j = 0;
	while (j < tile_size)
	{
		i = 0;
		while (i < tile_size)
		{
			screen_x = x + i + game->minimap.offset_x;
			screen_y = y + j + game->minimap.offset_y;
			my_mlx_pixel_put_b(game, screen_x - 3, screen_y - 3, color);
			i++;
		}
		j++;
	}
}

void	set_player_bounds(t_game *game, t_bounds *bounds)
{
	int	half_w;
	int	half_h;

	half_w = MAX_MINIMAP_WIDTH / 2;
	half_h = MAX_MINIMAP_HEIGHT / 2;
	bounds->start_x = (int)game->player.x - half_w;
	bounds->end_x = (int)game->player.x + half_w;
	bounds->start_y = (int)game->player.y - half_h;
	bounds->end_y = (int)game->player.y + half_h;
	set_player_limits(bounds, game->width, game->height);
}

void	draw_player_b(t_game *game)
{
	t_bounds	bounds;
	int			px;
	int			py;

	set_player_bounds(game, &bounds);
	px = (game->player.x - bounds.start_x) * game->minimap.tile_size;
	py = (game->player.y - bounds.start_y) * game->minimap.tile_size;
	if (py >= (MAX_MINIMAP_HEIGHT - 1) * game->minimap.tile_size)
		py = (MAX_MINIMAP_HEIGHT - 1) * game->minimap.tile_size;
	draw_view_angle_b(game, px, py);
	draw_player_tile_b(game, px, py, 0xc33ede);
}

void	draw_tile_b(t_game *game, int x, int y, int color)
{
	int	i;
	int	j;
	int	screen_x;
	int	screen_y;
	int	tile_size;

	tile_size = game->minimap.tile_size;
	j = 0;
	while (j < tile_size)
	{
		i = 0;
		while (i < tile_size)
		{
			screen_x = x + i + game->minimap.offset_x;
			screen_y = y + j + game->minimap.offset_y;
			my_mlx_pixel_put_b(game, screen_x, screen_y, color);
			i++;
		}
		j++;
	}
}
