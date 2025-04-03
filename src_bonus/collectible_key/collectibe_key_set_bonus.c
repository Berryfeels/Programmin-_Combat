/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibe_key_set_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:48 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:49 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	count_key(char **map)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'K')
				count++;
	}
	return (count);
}

static void	set_key_info(t_game *game, int x, int y, int index)
{
	game->key[index].x = x + 0.5;
	game->key[index].y = y + 0.5;
	game->key[index].distance = 0;
	game->key[index].visible = 0;
	game->key[index].active = 1;
	game->key[index].animation_index = 0;
	game->key[index].animation_timer = 0;
}

void	set_key_cords(t_game *game)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	game->key_count = count_key(game->map);
	game->key = malloc(sizeof(t_key) * game->key_count);
	if (!game->key)
		print_error(RED"Error: Key allocation failed!"RESET);
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < (int)ft_strlen(game->map[y]))
			if (game->map[y][x] == 'K')
				set_key_info(game, x, y, index++);
	}
}
