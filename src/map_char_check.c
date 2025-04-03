/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:38:41 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:38:42 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_char(char c)
{
	return (ft_strchr("01NSEW ", c) != NULL);
}

static int	check_chars_and_count_players(t_game *game, int *player_count)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (ft_strchr("NSEW", game->map[y][x]))
				(*player_count)++;
			else if (!is_valid_char(game->map[y][x]))
			{
				print_error(RED"Error: Invalid character");
				print_error("'%c'\n"RESET, game->map[y][x]);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	validate_map_chars(t_game *game)
{
	int	player_count;

	player_count = 0;
	if (!check_chars_and_count_players(game, &player_count))
		return (0);
	if (player_count != 1)
	{
		print_error(RED"Error: Map has more than one player\n"RESET);
		return (0);
	}
	return (1);
}
