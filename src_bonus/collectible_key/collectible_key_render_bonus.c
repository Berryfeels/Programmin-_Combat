/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_key_render_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:51 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:52 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_key_animation(t_key *key)
{
	if (!key->active)
		return ;
	key->animation_timer++;
	if (key->animation_timer >= 10)
	{
		key->animation_index = (key->animation_index + 1) % 7;
		key->animation_timer = 0;
	}
}

static void	pixel_to_buffer(t_game *game, int tex_x, int x, t_key *key)
{
	int	tex_y;
	int	y;
	int	frame;
	int	color;

	y = key->draw.start_y;
	while (y < key->draw.end_y)
	{
		tex_y = (y - key->draw.start_y) * \
				game->key_tex[0].height / key->draw.height;
		if (tex_y < 0 || tex_y >= game->key_tex[0].height)
		{
			x++;
			continue ;
		}
		frame = key->animation_index;
		color = 0;
		ft_memcpy(&color, game->key_tex[frame].addr \
				+ (tex_y * game->key_tex[frame].line_len) \
				+ (tex_x * (game->key_tex[frame].bpp / 8)), sizeof(int));
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put_b(game, x, y, color);
		y++;
	}
}

static void	render_key_pixels(t_game *game, t_key *key,
	t_draw *draw, double transform_y)
{
	int	x;
	int	tex_x;

	x = draw->start_x;
	while (x < draw->end_x)
	{
		if (x < 0 || x >= SCREEN_WIDTH)
		{
			x++;
			continue ;
		}
		tex_x = (x - draw->start_x) * game->key_tex[0].width / draw->width;
		if (tex_x < 0 || tex_x >= game->key_tex[0].width || \
		transform_y > game->z_buffer[x])
		{
			x++;
			continue ;
		}
		pixel_to_buffer(game, tex_x, x, key);
		x++;
	}
}

void	render_key(t_game *game, t_key *key)
{
	double	transform_x;
	double	transform_y;

	if (!game->key_tex[0].addr || !key->active)
		return ;
	update_key_animation(key);
	key->distance = pow(game->player.x - key->x, 2) + \
						pow(game->player.y - key->y, 2);
	if (!key->active)
		return ;
	if (!calculate_transform_key(game, key, &transform_x, &transform_y))
		return ;
	calculate_draw_positions_key(transform_x, transform_y, &key->draw);
	render_key_pixels(game, key, &key->draw, transform_y);
}
