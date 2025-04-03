/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health_bar_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:56:45 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:56:46 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	is_sprite_b(t_game *game, double player_x, double player_y)
{
	int		index;
	double	sprite_x;
	double	sprite_y;
	double	tolerance;

	tolerance = 0.5;
	index = 0;
	while (index < game->sprite_count)
	{
		sprite_x = game->sprites[index].x;
		sprite_y = game->sprites[index].y;
		if (fabs(sprite_x - player_x) < tolerance && \
			fabs(sprite_y - player_y) < tolerance)
			return (index);
		index++;
	}
	return (-1);
}

static void	check_player_health(t_game *game)
{
	if (is_sprite_b(game, game->player.x, game->player.y) != -1)
		game->player.health -= 2;
	if (game->player.health < 2)
	{
		game_over();
		close_window_b(game);
	}
}

static int	player_health_index(t_player player)
{
	if (player.health <= 100 && player.health > 80)
		return (0);
	else if (player.health <= 80 && player.health > 60)
		return (1);
	else if (player.health <= 60 && player.health > 40)
		return (2);
	else if (player.health <= 40 && player.health > 20)
		return (3);
	else
		return (4);
}

static void	draw_health_pixel(t_game *game, int index, int x, int y)
{
	int			tex_x;
	int			tex_y;
	int			color;
	t_health	*hb;

	hb = &game->health_bar[index];
	tex_x = x;
	tex_y = y;
	color = *((int *)(hb->addr + (tex_y * hb->line_len + tex_x * \
		(hb->bpp / 8))));
	if ((color & 0xFF000000) != 0xFF000000)
		my_mlx_pixel_put_b(game, hb->screen_x + x, hb->screen_y + y, color);
}

void	render_health_bar_b(t_game *game)
{
	int	index;
	int	x;
	int	y;

	check_player_health(game);
	index = player_health_index(game->player);
	if (!game->health_bar[index].img || !game->health_bar[index].addr)
		return ((void)printf(RED"Error: health bar texture %d not loaded!\n"\
			RESET, index));
	y = -1;
	while (++y < game->health_bar[index].height)
	{
		x = -1;
		while (++x < game->health_bar[index].width)
			draw_health_pixel(game, index, x, y);
	}
}
