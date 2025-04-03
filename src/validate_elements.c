/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:19:59 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:33:06 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_texture_path(char *path)
{
	int	len;

	len = ft_strlen(path);
	if (!path || len == 0)
	{
		print_error(RED"Error: Empty texture path\n"RESET);
		return (0);
	}
	if (len < 5 || ft_strncmp(path + len - 4, ".xpm", 4) != 0)
	{
		print_error(RED"Error: Texture file must be a .xpm file\n"RESET);
		print_error(RED"%s\n"RESET, path);
		return (0);
	}
	return (1);
}

int	validate_file(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len > 4)
	{
		if (ft_strncmp(filename + len - 4, ".cub", 4) == 0)
			return (1);
	}
	print_error(RED"Error: File must have a .cub extension\n"RESET);
	return (0);
}

//calls function to validate each texture
static int	validate_textures(t_texture *textures)
{
	if (!is_valid_texture_path(textures[NORTH].path) || \
		!is_valid_texture_path(textures[SOUTH].path) \
		|| !is_valid_texture_path(textures[WEST].path) \
		|| !is_valid_texture_path(textures[EAST].path))
		return (0);
	return (1);
}

int	validate_map(t_game *game)
{
	remove_trailing_empty_lines(game->map);
	if (!check_empty_line(game->map))
	{
		print_error(RED"Error: Empty line in map\n"RESET);
		return (0);
	}
	cal_map_dim(&game);
	if (!game->map || \
	!is_map_closed_and_accessible(game, game->map, game->height, game->width))
		return (0);
	return (1);
}

//calls function to validate the data saved in the structs
int	validate_cub_elements(t_game *game)
{
	if (!game->map)
	{
		print_error(RED"Error: map data is missing.\n"RESET);
		return (0);
	}
	if (validate_textures(game->textures) && \
		validate_colors(game->color) && validate_map(game))
		return (1);
	else
		return (0);
}
