/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_ammo_render_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:34 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:35 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_c_ammo_animation(t_c_ammo *c_ammo)
{
	if (!c_ammo->active)
		return ;
	c_ammo->animation_timer++;
	if (c_ammo->animation_timer >= 10)
	{
		c_ammo->animation_index = (c_ammo->animation_index + 1) % 12;
		c_ammo->animation_timer = 0;
	}
}

void	pixel_to_buffer(t_game *game, int tex_x, int x, t_c_ammo *c_ammo)
{
	int	tex_y;
	int	y;
	int	frame;
	int	color;

	y = c_ammo->draw.start_y;
	while (y < c_ammo->draw.end_y)
	{
		tex_y = (y - c_ammo->draw.start_y) * \
				game->c_ammo_tex[0].height / c_ammo->draw.height;
		if (tex_y < 0 || tex_y >= game->c_ammo_tex[0].height)
		{
			x++;
			continue ;
		}
		frame = c_ammo->animation_index;
		color = 0;
		ft_memcpy(&color, game->c_ammo_tex[frame].addr \
				+ (tex_y * game->c_ammo_tex[frame].line_len) \
				+ (tex_x * (game->c_ammo_tex[frame].bpp / 8)), sizeof(int));
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put_b(game, x, y, color);
		y++;
	}
}

void	render_c_ammo_pixels(t_game *game, t_c_ammo *c_ammo,
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
		tex_x = (x - draw->start_x) * game->c_ammo_tex[0].width / draw->width;
		if (tex_x < 0 || tex_x >= game->c_ammo_tex[0].width || \
		transform_y > game->z_buffer[x])
		{
			x++;
			continue ;
		}
		pixel_to_buffer(game, tex_x, x, c_ammo);
		x++;
	}
}

void	render_c_ammo(t_game *game, t_c_ammo *c_ammo)
{
	double	transform_x;
	double	transform_y;

	if (!game->c_ammo_tex[0].addr || !c_ammo->active)
		return ;
	update_c_ammo_animation(c_ammo);
	c_ammo->distance = pow(game->player.x - c_ammo->x, 2) + \
						pow(game->player.y - c_ammo->y, 2);
	if (!c_ammo->active)
		return ;
	if (!calculate_transform_c_ammo(game, c_ammo, &transform_x, &transform_y))
		return ;
	calculate_draw_positions_c_ammo(transform_x, transform_y, \
									&c_ammo->draw);
	render_c_ammo_pixels(game, c_ammo, &c_ammo->draw, transform_y);
}
