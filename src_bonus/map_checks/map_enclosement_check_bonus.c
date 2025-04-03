/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_enclosement_check_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:57:42 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:57:43 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_corners_b(t_game *game, char **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height - 1)
	{
		if (!case_one_b(map, y, game->height) || \
			!case_two_b(map, y, game->height))
			return (0);
		y++;
	}
	x = 0;
	while (x < game->width - 1)
	{
		if (!case_three_b(map, x, game->height) || \
			!case_four_b(map, x, game->height) \
			|| !case_five_b(map, x, game->height))
			return (0);
		x++;
	}
	return (1);
}

static int	is_not_enclosed_b(t_game *game, int x, int y, int row_len)
{
	char	tile;
	char	**map;

	map = game->map;
	tile = map[y][x];
	if ((tile == '0' || tile == 'N' || tile == 'S' || tile == 'E' \
		|| tile == 'H' || tile == 'W' || tile == 'D' || tile == 'Z' \
		|| tile == 'H' || tile == 'A' || tile == 'K' || tile == 'F') \
		&& (x == 0 || y == 0 || x == row_len - 1 || y == game->height - 1 || \
		map[y - 1][x] == ' ' || map[y + 1][x] == ' ' || \
		map[y][x - 1] == ' ' || map[y][x + 1] == ' ' || \
		map[y][x + 1] == '\0' || map[y][x + 1] == '\n'))
	{
		print_error(RED"Error: Map not enclosed at");
		print_error("(%d, %d)\n"RESET, x, game->height - y - 1);
		return (1);
	}
	return (0);
}

int	check_enclosure_b(t_game *game, char **map)
{
	int	y;
	int	x;
	int	row_len;

	y = 0;
	while (y < game->height)
	{
		row_len = 0;
		while (map[y][row_len] != '\0')
			row_len++;
		if (map[y][row_len - 1] == '\n')
			row_len--;
		x = 0;
		while (x < row_len)
		{
			if (is_not_enclosed_b(game, x, y, row_len))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
