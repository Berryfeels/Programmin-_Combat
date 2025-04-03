/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_empty_line_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:38:52 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:38:53 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_empty_line(const char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (true);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (false);
		i++;
	}
	return (true);
}

void	remove_trailing_empty_lines(char **map)
{
	int	last_non_empty;
	int	i;

	last_non_empty = -1;
	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		if (!is_empty_line(map[i]))
			last_non_empty = i;
		i++;
	}
	while (map[++last_non_empty])
	{
		free(map[last_non_empty]);
		map[last_non_empty] = NULL;
	}
}

int	check_empty_line(char **map)
{
	int	x;
	int	y;

	if (!map)
	{
		print_error(RED"Error: Map data missing.\n"RESET);
		return (0);
	}
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && (map[y][x] == ' ' || map[y][x] == '\t'))
			x++;
		if (map[y][x] == '\0')
			return (0);
		y++;
	}
	return (1);
}
