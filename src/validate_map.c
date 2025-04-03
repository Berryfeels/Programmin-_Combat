/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:12:24 by mcheragh          #+#    #+#             */
/*   Updated: 2025/03/25 14:53:05 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_edge(char **m, int check_row, int edge_row)
{
	int	x;
	int	row_len;

	x = 1;
	row_len = ft_strlen(m[check_row]);
	while (x < row_len - 1)
	{
		if (m[check_row][x] == '0')
		{
			if (x - 1 < 0 || x + 1 >= row_len)
			{
				print_error("Error: Unclosed map near (%d, %d)\n", x, edge_row);
				return (0);
			}
			if (m[edge_row][x - 1] != '1' || m[edge_row][x] != '1'
				|| m[edge_row][x + 1] != '1')
			{
				print_error("Error: Unclosed map near (%d, %d)\n", x, edge_row);
				return (0);
			}
		}
		x++;
	}
	return (1);
}

int	check_walls(t_game *game, char **map)
{
	const int	height = game->height;

	if (!check_edge(map, height - 2, height - 1))
		return (0);
	if (!check_edge(map, 1, 0))
		return (0);
	return (1);
}

static int	find_player(t_game **game)
{
	int	x;
	int	y;

	y = (*game)->height - 1;
	while (y >= 0)
	{
		x = 0;
		while ((*game)->map[y][x] != '\0')
		{
			if ((*game)->map[y][x] == 'N' || (*game)->map[y][x] == 'S' ||
				(*game)->map[y][x] == 'E' || (*game)->map[y][x] == 'W')
			{
				(*game)->player.ini_dir = malloc(2 * sizeof(char));
				(*game)->player.ini_dir[0] = (*game)->map[y][x];
				(*game)->player.ini_dir[1] = '\0';
				(*game)->player.x = x + 0.5;
				(*game)->player.y = y + 0.5;
				return (1);
			}
			x++;
		}
		y--;
	}
	print_error(RED"Error: Player not found on the map\n"RESET);
	return (0);
}

static int	**allocate_visited(int height, int width)
{
	int	y;
	int	**visited;

	visited = malloc(height * sizeof(int *));
	if (!visited)
		return (NULL);
	y = 0;
	while (y < height)
	{
		visited[y] = ft_calloc(width, sizeof(int));
		if (!visited[y])
		{
			free_visited(visited, y);
			return (NULL);
		}
		y++;
	}
	return (visited);
}

int	is_map_closed_and_accessible(t_game *game, char **map, \
								int height, int width)
{
	int	**visited;

	if (!game || !map)
	{
		print_error(RED"Error: Game or map is NULL\n"RESET);
		return (0);
	}
	if (!find_player(&game) || !validate_map_chars(game))
		return (0);
	visited = allocate_visited(height, width);
	if (!visited)
		return (0);
	flood_fill(game, visited);
	if (!check_accessibility(game, visited) || \
		!check_enclosure(game, map) || \
		!check_corners(game, map) || \
		!check_walls(game, map))
	{
		free_visited(visited, height);
		return (0);
	}
	free_visited(visited, height);
	return (1);
}
