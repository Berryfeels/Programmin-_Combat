/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:42:32 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 16:41:30 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	free_two_dim_b(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	two_dim_len_b(char **arr)
{
	int	count;

	if (!arr)
		return (0);
	count = 0;
	while (arr[count])
		count++;
	return (count);
}

static int	door_tex_index(t_ray *ray, t_game *game)
{
	int	door_index;

	door_index = which_door(game, ray->mapy, ray->mapx);
	ray->door = 0;
	if (game->door[door_index].door_state == 1)
		return (DOOR_1);
	else if (game->door[door_index].door_state == 2)
		return (DOOR_2);
	else if (game->door[door_index].door_state == 3)
		return (DOOR_3);
	else if (game->door[door_index].door_state == 4)
		return (DOOR_4);
	else if (game->door[door_index].door_state == 5)
		return (DOOR_5);
	return (DOOR_6);
}

int	select_texture_b(t_ray *ray, t_game *game)
{
	if (ray->door == 1)
		return (door_tex_index(ray, game));
	if (ray->final_door == 1)
	{
		ray->final_door = 0;
		return (FINAL_DOOR);
	}
	if (ray->side == 0)
	{
		if (ray->dirx > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray->diry > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
	return (EAST);
}

int	rgb_to_hex_b(int r, int g, int b)
{
	int	color;

	color = (r << 16) | (g << 8) | b;
	return (color);
}
