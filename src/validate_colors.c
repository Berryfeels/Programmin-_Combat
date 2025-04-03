/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:54:21 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 16:30:09 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' && str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	check_rgb_str(char **rgb)
{
	if (!rgb || two_dim_len(rgb) != 3)
	{
		print_error(RED"Error: Invalid color format\n"RESET);
		free_two_dim(rgb);
		return (0);
	}
	if (!is_valid_number(rgb[0]) || !is_valid_number(rgb[1]) || \
		!is_valid_number(rgb[2]))
	{
		print_error(RED"Error: Color values must be numbers\n"RESET);
		free_two_dim(rgb);
		return (0);
	}
	return (1);
}

static int	check_rgb(t_color *color)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	color->mode = 1;
	rgb = ft_split(color->col_tex_str, ',');
	if (!check_rgb_str(rgb))
		return (0);
	r = ft_atol(rgb[0]);
	g = ft_atol(rgb[1]);
	b = ft_atol(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255 || \
		!ft_atol(rgb[0]) || !ft_atol(rgb[1]) || !ft_atol(rgb[2]))
	{
		free_two_dim(rgb);
		print_error(RED"Error: Color values must be between 0 and 255\n"RESET);
		return (0);
	}
	free_two_dim(rgb);
	color->r = r;
	color->g = g;
	color->b = b;
	return (1);
}

int	validate_colors(t_color *color)
{
	if (!color[FLOOR].col_tex_str || !color[CEILING].col_tex_str)
	{
		print_error(RED"Error: Missing floor or ceiling color (F, C)\n"RESET);
		return (0);
	}
	if (!check_rgb(&color[FLOOR]))
	{
		print_error(RED"Error: Invalid floor color\n"RESET);
		return (0);
	}
	if (!check_rgb(&color[CEILING]))
	{
		print_error(RED"Error: Invalid ceiling color\n"RESET);
		return (0);
	}
	return (1);
}
