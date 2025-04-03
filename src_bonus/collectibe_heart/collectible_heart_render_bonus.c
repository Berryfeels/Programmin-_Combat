/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_heart_render_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:26 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:27 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	update_heart_animation(t_heart *heart)
{
	if (!heart->active)
		return ;
	heart->animation_timer++;
	if (heart->animation_timer >= 10)
	{
		heart->animation_index = (heart->animation_index + 1) % 12;
		heart->animation_timer = 0;
	}
}

void	pixel_to_buffer_heart(t_game *game, int tex_x, int x, t_heart *heart)
{
	int	tex_y;
	int	y;
	int	frame;
	int	color;

	y = heart->draw.start_y;
	while (y < heart->draw.end_y)
	{
		tex_y = (y - heart->draw.start_y) * \
				game->heart_tex[0].height / heart->draw.height;
		if (tex_y < 0 || tex_y >= game->heart_tex[0].height)
		{
			x++;
			continue ;
		}
		frame = heart->animation_index;
		color = 0;
		ft_memcpy(&color, game->heart_tex[frame].addr \
				+ (tex_y * game->heart_tex[frame].line_len) \
				+ (tex_x * (game->heart_tex[frame].bpp / 8)), sizeof(int));
		if ((color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put_b(game, x, y, color);
		y++;
	}
}

void	render_heart_pixels(t_game *game, t_heart *heart,
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
		tex_x = (x - draw->start_x) * game->heart_tex[0].width / draw->width;
		if (tex_x < 0 || tex_x >= game->heart_tex[0].width || \
		transform_y > game->z_buffer[x])
		{
			x++;
			continue ;
		}
		pixel_to_buffer_heart(game, tex_x, x, heart);
		x++;
	}
}

void	render_hearts(t_game *game, t_heart *heart)
{
	double	transform_x;
	double	transform_y;

	if (!game->heart_tex[0].addr || !heart->active)
		return ;
	update_heart_animation(heart);
	heart->distance = pow(game->player.x - heart->x, 2) + \
						pow(game->player.y - heart->y, 2);
	if (!heart->active)
		return ;
	if (!calculate_transform_heart(game, heart, &transform_x, &transform_y))
		return ;
	calculate_draw_positions_heart(transform_x, transform_y, \
									&heart->draw);
	render_heart_pixels(game, heart, &heart->draw, transform_y);
}
