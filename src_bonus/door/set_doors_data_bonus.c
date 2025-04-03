/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_doors_data_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:56:06 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:56:07 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_doors_cords(int count, t_door **door, char **map)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = -1;
	while (map[++y] && i < count)
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'D')
			{
				(*door)[i].x = x;
				(*door)[i].y = y;
				(*door)[i].door_state = 1;
				(*door)[i].transition_time = get_time_of_the_day();
				(*door)[i].trigger = 1;
				i++;
			}
		}
	}
}

int	count_doors(char **map)
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
			if (map[y][x] == 'D')
			{
				count++;
			}
			x++;
		}
		y++;
	}
	return (count);
}

void	set_doors(t_game *game)
{
	if (!game || !game->map)
		return ;
	game->door_count = count_doors(game->map);
	if (game->door_count == 0)
	{
		game->door = NULL;
		return ;
	}
	game->door = (t_door *)malloc(sizeof(t_door) * game->door_count);
	if (!game->door)
	{
		print_error(RED"Error: Memory allocation for doors failed!"RESET);
		close_window_b(game);
		return ;
	}
	set_doors_cords(game->door_count, &game->door, game->map);
}

void	update_doors(t_game *game)
{
	long	current_time;
	int		i;

	current_time = get_time_of_the_day();
	i = 0;
	while (i < game->door_count)
	{
		if (game->door[i].trigger == 0 && game->door[i].door_state < 7)
		{
			if (current_time - game->door[i].transition_time >= 200)
			{
				game->door[i].door_state++;
				game->door[i].transition_time = current_time;
			}
		}
		if (game->door[i].trigger == 1 && game->door[i].door_state > 1)
		{
			if (current_time - game->door[i].transition_time >= 200)
			{
				game->door[i].door_state--;
				game->door[i].transition_time = current_time;
			}
		}
		i++;
	}
}
