/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceiling_and_floor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:39:11 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:39:12 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling_pixel(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = 0;
		while (y < SCREEN_HEIGHT / 2)
		{
			my_mlx_pixel_put(game, x, y, game->color[CEILING].hex_color);
			y++;
		}
		x++;
	}
}

void	draw_floor_pixel(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < SCREEN_WIDTH)
	{
		y = SCREEN_HEIGHT / 2;
		while (y < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(game, x, y, game->color[FLOOR].hex_color);
			y++;
		}
		x++;
	}
}

void	draw_floor_and_ceiling(t_game *game)
{
	draw_ceiling_pixel(game);
	draw_floor_pixel(game);
}
