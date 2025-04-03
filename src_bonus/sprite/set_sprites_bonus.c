/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sprites_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:01:18 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:01:19 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	count_sprites(char **map)
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
			if (map[y][x] == 'Z')
			{
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

static void	init_sprite(t_sprite *sprite, int x, int y)
{
	sprite->distance = 0;
	sprite->visible = 0;
	sprite->health = 100;
	sprite->active = 1;
	sprite->x = x + 0.5;
	sprite->y = y + 0.5;
}

void	set_sprites_cords(t_game *game)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	game->sprite_count = count_sprites(game->map);
	game->sprites = malloc(sizeof(t_sprite) * game->sprite_count);
	if (!game->sprites)
		print_error(RED"Error: Sprite allocation failed!"RESET);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == 'Z')
			{
				init_sprite(&game->sprites[index], x, y);
				index++;
			}
			x++;
		}
		y++;
	}
}
