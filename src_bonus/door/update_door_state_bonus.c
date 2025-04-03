/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_door_state_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:56:10 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:56:11 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

long	get_time_of_the_day(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
	{
		perror("gettimeofday failed");
		return (-1);
	}
	return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
}

void	change_door_state(t_game *game, int index)
{
	if (game->door[index].door_state == 1)
	{
		game->door[index].transition_time = get_time_of_the_day();
		game->door[index].trigger = 0;
		return ;
	}
	if (game->door[index].door_state == 7)
	{
		game->door[index].transition_time = get_time_of_the_day();
		game->door[index].trigger = 1;
		return ;
	}
}

int	is_final_door(t_game *game)
{
	if (game->map[(int)game->player.y + 1][(int)game->player.x + 1] == 'F')
		return (1);
	if (game->map[(int)game->player.y][(int)game->player.x + 1] == 'F')
		return (1);
	if (game->map[(int)game->player.y + 1][(int)game->player.x] == 'F')
		return (1);
	if (game->map[(int)game->player.y - 1][(int)game->player.x - 1] == 'F')
		return (1);
	if (game->map[(int)game->player.y][(int)game->player.x - 1] == 'F')
		return (1);
	if (game->map[(int)game->player.y - 1][(int)game->player.x] == 'F')
		return (1);
	return (0);
}
