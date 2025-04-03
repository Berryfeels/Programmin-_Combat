/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessibility_check.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:38:37 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:38:38 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

static int	is_inaccessible_tile(t_game *game, int **visited, int x, int y)
{
	char	tile;

	tile = game->map[y][x];
	if ((tile == '0' || tile == 'N' || tile == 'S' || \
		tile == 'E' || tile == 'W') && !visited[y][x])
	{
		print_error(RED"Error: Inaccessible area found at ");
		print_error("(%d, %d)\n"RESET, x, game->height - y - 1);
		return (1);
	}
	return (0);
}

int	check_accessibility(t_game *game, int **visited)
{
	int	y;
	int	x;
	int	row_len;

	y = 0;
	while (y < game->height)
	{
		row_len = 0;
		while (game->map[y][row_len] != '\0')
			row_len++;
		x = 0;
		while (x < row_len)
		{
			if (is_inaccessible_tile(game, visited, x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
