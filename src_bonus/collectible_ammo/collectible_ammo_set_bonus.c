/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_ammo_set_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:38 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:39 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	count_c_ammo(char **map)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'A')
			{
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

static void	set_info(t_game *game, int x, int y, int index)
{
	game->c_ammo[index].x = x + 0.5;
	game->c_ammo[index].y = y + 0.5;
	game->c_ammo[index].distance = 0;
	game->c_ammo[index].visible = 0;
	game->c_ammo[index].active = 1;
	game->c_ammo[index].animation_index = 0;
	game->c_ammo[index].animation_timer = 0;
}

void	set_c_ammo_cords(t_game *game)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	game->c_ammo_count = count_c_ammo(game->map);
	game->c_ammo = malloc(sizeof(t_c_ammo) * game->c_ammo_count);
	if (!game->c_ammo)
		print_error(RED"Error: Sprite allocation failed!"RESET);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == 'A')
			{
				set_info(game, x, y, index);
				index++;
			}
			x++;
		}
		y++;
	}
}
