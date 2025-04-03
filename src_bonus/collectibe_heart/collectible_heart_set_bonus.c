/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible_heart_set_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:55:29 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:55:30 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	count_hearts(char **map)
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
			if (map[y][x] == 'H')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static void	set_heart_info(t_game *game, int x, int y, int index)
{
	game->heart[index].x = x + 0.5;
	game->heart[index].y = y + 0.5;
	game->heart[index].distance = 0;
	game->heart[index].visible = 0;
	game->heart[index].active = 1;
	game->heart[index].animation_index = 0;
	game->heart[index].animation_timer = 0;
}

void	set_heart_cords(t_game *game)
{
	int	x;
	int	y;
	int	index;

	index = 0;
	game->heart_count = count_hearts(game->map);
	game->heart = malloc(sizeof(t_heart) * game->heart_count);
	if (!game->heart)
		print_error(RED"Error: Memory allocation for hearts failed!"RESET);
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < (int)ft_strlen(game->map[y]))
		{
			if (game->map[y][x] == 'H')
			{
				set_heart_info(game, x, y, index);
				index++;
			}
			x++;
		}
		y++;
	}
}
