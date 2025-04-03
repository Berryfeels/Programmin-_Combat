/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_char_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:57:26 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:57:27 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	is_valid_char_b(char c)
{
	return (ft_strchr("01NSEWDZHAKF ", c) != NULL);
}

static int	check_chars_and_count_players_b(t_game *game, int *player_count)
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
			else if (!is_valid_char_b(game->map[y][x]))
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

int	validate_map_chars_b(t_game *game)
{
	int	player_count;

	player_count = 0;
	if (!check_chars_and_count_players_b(game, &player_count))
		return (0);
	if (player_count != 1)
	{
		print_error(RED"Error: Map has more than one player\n"RESET);
		return (0);
	}
	return (1);
}
