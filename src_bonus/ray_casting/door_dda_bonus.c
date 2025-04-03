/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_dda_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:59:25 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:59:26 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	select_door_texture_b(t_ray *ray, t_game *game)
{
	int	door_index;

	door_index = which_door(game, ray->mapy, ray->mapx);
	if (door_index == -1)
		return (DOOR_1);
	if (game->door[door_index].door_state == 1)
		return (DOOR_1);
	if (game->door[door_index].door_state == 2)
		return (DOOR_2);
	if (game->door[door_index].door_state == 3)
		return (DOOR_3);
	if (game->door[door_index].door_state == 4)
		return (DOOR_4);
	if (game->door[door_index].door_state == 5)
		return (DOOR_5);
	if (game->door[door_index].door_state == 6)
		return (DOOR_6);
	return (7);
}

static int	handle_door_state(t_game *game, int door_index)
{
	int	door_state;

	if (door_index == -1)
		return (DOOR_OPEN);
	door_state = game->door[door_index].door_state;
	if (door_state == 1)
		return (DOOR_CLOSED);
	if (door_state >= 2 && door_state <= 6)
		return (DOOR_PARTIAL);
	return (DOOR_OPEN);
}

static int	handle_door_hit_texture(t_ray *ray, t_game *game, int tex_id)
{
	int		tex_x;
	int		tex_y;
	int		color;
	double	hit_pos;

	if (ray->side == 0)
		hit_pos = game->player.y + ray->walldist * ray->diry;
	else
		hit_pos = game->player.x + ray->walldist * ray->dirx;
	hit_pos -= floor(hit_pos);
	tex_x = (int)(hit_pos * game->textures[tex_id].width) % \
								game->textures[tex_id].width;
	tex_y = ((int)(ray->walldist * game->textures[tex_id].height)) % \
										game->textures[tex_id].height;
	color = *((int *)(game->textures[tex_id].addr \
			+ (tex_y * game->textures[tex_id].line_len) \
			+ (tex_x * (game->textures[tex_id].bpp / 8))));
	if ((color & 0xFF000000) == 0x00000000)
		return (1);
	return (0);
}

int	handle_door_hit(t_ray *ray, t_game *game)
{
	int	door_index;
	int	door_state;
	int	tex_id;

	if (game->map[ray->mapy][ray->mapx] == 'F')
	{
		ray->final_door = 1;
		return (1);
	}
	door_index = which_door(game, ray->mapy, ray->mapx);
	door_state = handle_door_state(game, door_index);
	if (door_state == DOOR_CLOSED)
	{
		ray->door = 1;
		return (1);
	}
	if (door_state == DOOR_OPEN)
		return (0);
	tex_id = select_door_texture_b(ray, game);
	if (handle_door_hit_texture(ray, game, tex_id))
	{
		ray->door = 1;
		return (1);
	}
	return (0);
}
