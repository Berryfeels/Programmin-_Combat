/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 13:19:59 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:23:06 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	validate_file_b(const char *filename)
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

int	validate_colors_b(t_color *color)
{
	if (!color[FLOOR].col_tex_str || (!color[CEILING].col_tex_str && \
	!color[SKY].col_tex_str))
	{
		print_error(RED"Error: Missing floor or ceiling color (F, C)\n"RESET);
		return (0);
	}
	if (!is_valid_color_texture_b(&color[FLOOR]))
		return (0);
	if (color[CEILING].col_tex_str)
	{
		if (!is_valid_color_texture_b(&color[CEILING]))
			return (0);
	}
	else
	{
		if (!is_valid_color_texture_b(&color[SKY]))
			return (0);
	}
	return (1);
}

static int	validate_textures_b(t_texture *textures)
{
	if (!is_valid_texture_path_b(textures[NORTH].path) \
		|| !is_valid_texture_path_b(textures[SOUTH].path) \
		|| !is_valid_texture_path_b(textures[WEST].path) \
		|| !is_valid_texture_path_b(textures[EAST].path) \
		|| !is_valid_texture_path_b(textures[ZOMBIE_0].path) \
		|| !is_valid_texture_path_b(textures[ZOMBIE_1].path) \
		|| !is_valid_texture_path_b(textures[ZOMBIE_2].path) \
		|| !is_valid_texture_path_b(textures[DOOR_1].path) \
		|| !is_valid_texture_path_b(textures[DOOR_2].path) \
		|| !is_valid_texture_path_b(textures[DOOR_3].path) \
		|| !is_valid_texture_path_b(textures[DOOR_4].path) \
		|| !is_valid_texture_path_b(textures[DOOR_5].path) \
		|| !is_valid_texture_path_b(textures[DOOR_6].path) \
		|| !is_valid_texture_path_b(textures[FINAL_DOOR].path))
		return (0);
	return (1);
}

int	validate_map_b(t_game *game)
{
	remove_trailing_empty_lines_b(game->map);
	if (!check_empty_line_b(game->map))
	{
		print_error(RED"Error: Empty line in map\n"RESET);
		return (0);
	}
	cal_map_dim_b(&game);
	if (!game->map || \
	!is_map_closed_and_accessible_b(game, game->map, game->height, game->width))
		return (0);
	return (1);
}

int	validate_cub_elements_b(t_game *game)
{
	if (!game->map)
	{
		print_error(RED"Error: map data is missing.\n"RESET);
		return (0);
	}
	if (validate_textures_b(game->textures) && validate_objects(game) && \
		validate_colors_b(game->color) && validate_map_b(game))
		return (1);
	else
		return (0);
}
