/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprite_tool_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:01:13 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:01:14 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	sort_sprites(t_game *game)
{
	int			i;
	int			j;
	t_sprite	temp;

	i = 0;
	while (i < game->sprite_count - 1)
	{
		j = i + 1;
		while (j < game->sprite_count)
		{
			if (game->sprites[i].distance < game->sprites[j].distance)
			{
				temp = game->sprites[i];
				game->sprites[i] = game->sprites[j];
				game->sprites[j] = temp;
			}
			j++;
		}
		i++;
	}
}

int	get_tex_x(t_game *game, t_sprite_draw *draw, int x, int index)
{
	return ((x - draw->start_x) * game->textures[index].width / draw->width);
}

int	get_tex_y(t_game *game, t_sprite_draw *draw, int y, int index)
{
	return ((y - draw->start_y) * game->textures[index].height / draw->height);
}

int	transform_sprite(t_game *game, t_sprite *sprite, \
										t_sprite_draw *draw)
{
	double	inv_det;

	draw->sprite_x = sprite->x - game->player.x;
	draw->sprite_y = sprite->y - game->player.y;
	inv_det = 1.0 / (game->player.plane_x * game->player.dir_y \
						- game->player.dir_x * game->player.plane_y);
	draw->transform_x = inv_det * (game->player.dir_y * draw->sprite_x \
						- game->player.dir_x * draw->sprite_y);
	draw->transform_y = inv_det * (-game->player.plane_y * draw->sprite_x \
						+ game->player.plane_x * draw->sprite_y);
	if (draw->transform_y <= 0.01)
		return (0);
	sprite->distance = draw->sprite_x * draw->sprite_x \
						+ draw->sprite_y * draw->sprite_y;
	return (1);
}
