/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_corner_cases_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:57:33 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:57:34 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	case_one_b(char **map, int y, int height)
{
	int	first_y;
	int	first_y_next;

	first_y = first_pos_row_b(map[y]);
	first_y_next = first_pos_row_b(map[y + 1]);
	if (first_y > first_y_next)
	{
		if ((map[y][first_y]) != '1' || (map[y + 1][first_y]) != '1')
		{
			print_error(RED"Error: Map not enclosed at (%d, %d)\n"RESET, \
				first_y, height - y - 1);
			return (0);
		}
	}
	else if (first_y < first_y_next)
	{
		if ((map[y][first_y_next]) != '1' || (map[y + 1][first_y_next]) != '1')
		{
			print_error(RED"Error: Map not enclosed at (%d, %d)\n"RESET, \
				first_y, height - y - 1);
			return (0);
		}
	}
	return (1);
}

int	case_two_b(char **map, int y, int height)
{
	int	last_y;
	int	last_y_next;

	last_y = last_pos_row_b(map[y]);
	last_y_next = last_pos_row_b(map[y + 1]);
	if ((last_y > last_y_next))
	{
		if ((map[y][last_y_next]) != '1' || (map[y + 1][last_y_next]) != '1')
		{
			print_error(RED"Error: Map not enclosed at (%d, %d)\n"RESET, \
				last_y_next, height - y - 1);
			return (0);
		}
	}
	else if (last_y < last_y_next)
	{
		if ((map[y][last_y]) != '1' || (map[y + 1][last_y]) != '1')
		{
			print_error(RED"Error: Map not enclosed at (%d, %d)\n"RESET, \
				last_y, height - y - 1);
			return (0);
		}
	}
	return (1);
}

int	case_three_b(char **map, int x, int height)
{
	int	first_x;
	int	first_x_next;

	first_x = first_pos_col_b(map, x);
	first_x_next = first_pos_col_b(map, x + 1);
	if (first_x < first_x_next)
	{
		if (map[first_x_next] && (map[first_x_next][x] != '1' || \
			map[first_x_next][x + 1] != '1'))
		{
			print_error(RED"Error: Map not enclosed at (%d, %d)\n"RESET, x + 1, \
				height - first_x_next);
			return (0);
		}
	}
	else if (first_x > first_x_next && map[first_x])
	{
		if ((map[first_x][x] != '1' || map[first_x][x + 1] != '1'))
		{
			print_error(RED"Error: Map not enclosed at (%d, %d)\n"RESET, x, \
				height - first_x);
			return (0);
		}
	}
	return (1);
}

int	case_four_b(char **map, int x, int height)
{
	int	last_x;
	int	last_x_next;

	last_x = last_pos_col_b(map, x, height);
	last_x_next = last_pos_col_b(map, x + 1, height);
	if (last_x > last_x_next)
	{
		if (last_x_next >= 0 && last_x_next < height && map[last_x_next])
		{
			if (x >= 0 && x < (int)ft_strlen(map[last_x_next]) - 1)
			{
				if (map[last_x_next][x] != '1' || \
					map[last_x_next][x + 1] != '1')
				{
					print_error(RED"Error: Map not enclosed.\n"RESET);
					return (0);
				}
			}
			else
				return (1);
		}
		else
			return (1);
	}
	return (1);
}

int	case_five_b(char **map, int x, int height)
{
	int	last_x;
	int	last_x_next;

	last_x = last_pos_col_b(map, x, height);
	last_x_next = last_pos_col_b(map, x + 1, height);
	if (last_x < last_x_next)
	{
		if (last_x >= 0 && last_x < height && map[last_x])
		{
			if (x >= 0 && x < (int)strlen(map[last_x]) - 1)
			{
				if (map[last_x][x] != '1' || map[last_x][x + 1] != '1')
				{
					print_error(RED"Error: Map not enclosed\n"RESET);
					return (0);
				}
			}
			else
				return (1);
		}
		else
			return (1);
	}
	return (1);
}
