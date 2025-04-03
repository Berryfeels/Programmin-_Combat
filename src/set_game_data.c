/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:39:19 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:39:20 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Initializes an MLX texture from a given file path.
 * This function loads the texture into an MLX image and retrieves
 * its memory address for pixel manipulation.
 *
 * Parameters:
 * - game: Pointer to the main game structure.
 * - index: Index of the texture in the texture array.
 * - path: Path to the texture file.
 */
void	init_mlx_wall_texture(t_game *game, int index, char *path)
{
	if (!path)
	{
		print_error(RED"Texture path is NULL\n"RESET);
		return ;
	}
	game->textures[index].img = mlx_xpm_file_to_image(\
		game->mlx, path, &(game->textures[index].width), \
		&(game->textures[index].height));
	if (!game->textures[index].img)
	{
		print_error(RED"Texture file could not be loaded: \n");
		print_error("%s\n"RESET, path);
		close_window(game);
	}
	game->textures[index].addr = mlx_get_data_addr(\
		game->textures[index].img, &game->textures[index].bpp, \
		&game->textures[index].line_len, \
		&game->textures[index].endian);
	if (!game->textures[index].addr)
	{
		print_error(RED"Error: Texture %d address is NULL!\n"RESET, index);
		close_window(game);
	}
}

/*
 * Loads the player's direction based on an initial direction string.
 * This function assigns the correct direction vector and camera plane.
 *
 * Parameters:
 * - game: Pointer to the main game structure.
 */
void	load_player(t_game *game)
{
	if (!game->player.ini_dir)
	{
		print_error(RED"Player direction not set!\n"RESET);
		close_window(game);
	}
	if (ft_strncmp(game->player.ini_dir, "N", 1) == 0)
	{
		game->player.dir_y = -1;
		game->player.plane_x = 0.66;
	}
	else if (ft_strncmp(game->player.ini_dir, "S", 1) == 0)
	{
		game->player.dir_y = 1;
		game->player.plane_x = -0.66;
	}
	else if (ft_strncmp(game->player.ini_dir, "E", 1) == 0)
	{
		game->player.dir_x = 1;
		game->player.plane_y = 0.66;
	}
	else if (ft_strncmp(game->player.ini_dir, "W", 1) == 0)
	{
		game->player.dir_x = -1;
		game->player.plane_y = -0.66;
	}
}

static void	set_colors(t_color *color, int index)
{
	color[index].hex_color = rgb_to_hex(color[index].r, \
					color[index].g, color[index].b);
}

void	init_all_mlx_textures(t_game *game)
{
	init_mlx_wall_texture(game, NORTH, game->textures[NORTH].path);
	init_mlx_wall_texture(game, SOUTH, game->textures[SOUTH].path);
	init_mlx_wall_texture(game, WEST, game->textures[WEST].path);
	init_mlx_wall_texture(game, EAST, game->textures[EAST].path);
	set_colors(game->color, CEILING);
	set_colors(game->color, FLOOR);
}
