/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammo_bar_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:16 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:17 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ammo_pixel(t_game *game, int x, int y, int index)
{
	int	tex_x;
	int	tex_y;
	int	color;

	tex_x = x;
	tex_y = y;
	color = *((int *)(game->ammo[index].addr + \
			(tex_y * game->ammo[index].line_len + tex_x * \
						(game->ammo[index].bpp / 8))));
	if ((color & 0xFF000000) != 0xFF000000)
		my_mlx_pixel_put_b(game, game->ammo[index].screen_x + x, \
				game->ammo[index].screen_y + y, color);
}

void	render_ammo_bar_b(t_game *game)
{
	int	index;
	int	x;
	int	y;

	index = game->player.ammo;
	if (!game->ammo[index].img || !game->ammo[index].addr)
	{
		print_error(RED"Error: Ammo bar texture %d"RESET, index);
		print_error(RED" not loaded properly!\n"RESET);
		return ;
	}
	y = 0;
	while (y < game->ammo[index].height)
	{
		x = 0;
		while (x < game->ammo[index].width)
		{
			ammo_pixel(game, x, y, index);
			x++;
		}
		y++;
	}
}
