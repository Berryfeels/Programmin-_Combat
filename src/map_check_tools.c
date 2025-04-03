/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:38:45 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:38:46 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cal_map_dim(t_game **game)
{
	int	height;
	int	width;
	int	line_width;
	int	i;

	height = 0;
	width = 0;
	while ((*game)->map[height] != NULL)
	{
		line_width = 0;
		i = 0;
		while ((*game)->map[height][i] != '\0')
		{
			line_width++;
			i++;
		}
		if (line_width > width)
			width = line_width;
		height++;
	}
	(*game)->width = width;
	(*game)->height = height;
}

int	first_pos_row(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] == ' ')
	{
		i++;
	}
	return (i);
}

int	last_pos_row(char *line)
{
	int	len;

	len = ft_strlen(line);
	while (len > 0 && line[len - 1] == ' ')
	{
		len--;
	}
	return (len - 1);
}

int	first_pos_col(char **map, int col)
{
	int	y;

	y = 0;
	while (map[y])
	{
		if (map[y][col])
		{
			if (map[y][col] != ' ')
				return (y);
		}
		y++;
	}
	return (y);
}

int	last_pos_col(char **map, int col, int height)
{
	int	y;

	y = 0;
	while (y < height && map[y] && col < (int)ft_strlen(map[y]) \
			&& map[y][col] == ' ')
	{
		y++;
	}
	while (y < height && map[y] && col < (int)ft_strlen(map[y]) \
			&& map[y][col] &&
			(map[y][col] == '1' || map[y][col] == '0' ||
			map[y][col] == 'N' || map[y][col] == 'S' ||
			map[y][col] == 'W' || map[y][col] == 'E' ))
	{
		y++;
	}
	return (y - 1);
}
