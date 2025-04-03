/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting_effect_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:56:39 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/03 12:12:41 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_gun_shot_pos(t_game *game)
{
	game->gun[GUN_SHUT].screen_x = (SCREEN_WIDTH / 2) - \
		(game->gun[GUN_SHUT].width / 2);
	game->gun[GUN_SHUT].screen_y = SCREEN_HEIGHT / 2 + 50;
}

void	shoot_gun(t_game *game)
{
	t_sprite	*zombie;
	int			index;

	if (game->player.ammo == 0)
		return ;
	game->player.ammo -= 1;
	render_gun_shut_b(game);
	render_gun_shut_b(game);
	zombie = get_zombie_in_front(game);
	if (!zombie)
		return ;
	zombie->health -= 50;
	if (zombie->health <= 0)
	{
		index = zombie - game->sprites;
		remove_zombie(game, index);
	}
}

static void	draw_shot_pixel(t_game *game, int x, int y)
{
	int	tex_x;
	int	tex_y;
	int	color;

	tex_x = x;
	tex_y = y;
	color = *((int *)(game->gun[GUN_SHUT].addr + \
		(tex_y * game->gun[GUN_SHUT].line_len + tex_x * \
		(game->gun[GUN_SHUT].bpp / 8))));
	if ((color & 0xFF000000) != 0xFF000000)
		my_mlx_pixel_put_b(game, game->gun[GUN_SHUT].screen_x + x, \
			game->gun[GUN_SHUT].screen_y + y, color);
}

void	render_gun_shut_b(t_game *game)
{
	int	x;
	int	y;

	if (!game->gun[GUN_SHUT].img || !game->gun[GUN_SHUT].addr)
		return ((void)printf("Error: Gun texture not loaded!\n"));
	set_gun_shot_pos(game);
	y = -1;
	while (++y < game->gun[GUN_SHUT].height)
	{
		x = -1;
		while (++x < game->gun[GUN_SHUT].width)
			draw_shot_pixel(game, x, y);
	}
}
