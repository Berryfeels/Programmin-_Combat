/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_game_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:00:15 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:00:16 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_mlx_wall_texture_b(t_game *game, int index, char *path)
{
	if (!path)
	{
		print_error(RED"WALL Texture path is NULL\n"RESET);
		return ;
	}
	game->textures[index].img = mlx_xpm_file_to_image(\
		game->mlx, path, &(game->textures[index].width), \
		&(game->textures[index].height));
	if (!game->textures[index].img)
	{
		print_error(RED"Texture file could not be loaded: ");
		print_error("%s\n"RESET, path);
		close_window_b(game);
	}
	game->textures[index].addr = mlx_get_data_addr(\
		game->textures[index].img, &game->textures[index].bpp, \
		&game->textures[index].line_len, &game->textures[index].endian);
	if (!game->textures[index].addr)
	{
		print_error(RED"Error: Texture %d address is NULL!\n"RESET, index);
		close_window_b(game);
	}
}

void	init_mlx_health_bar_texture_b(t_game *game)
{
	int		index;
	char	*path;

	index = 0;
	while (index < 5)
	{
		path = game->health_bar[index].path;
		game->health_bar[index].img = mlx_xpm_file_to_image(game->mlx, path, \
		&(game->health_bar[index].width), &(game->health_bar[index].height));
		if (!game->health_bar[index].img)
		{
			print_error(RED"Error: Health bar Tex could not be loaded: ");
			print_error("%s\n"RESET, path);
			close_window_b(game);
		}
		game->health_bar[index].addr = mlx_get_data_addr(\
			game->health_bar[index].img, &game->health_bar[index].bpp, \
			&game->health_bar[index].line_len, &game->health_bar[index].endian);
		if (!game->health_bar[index].addr)
		{
			print_error(RED"Error: Health bar tex addr is NULL\n"RESET);
			close_window_b(game);
		}
		index++;
	}
}

void	init_mlx_ammo_bar_texture_b(t_game *game)
{
	int		index;
	char	*path;

	index = 0;
	while (index < 7)
	{
		path = game->ammo[index].path;
		game->ammo[index].img = mlx_xpm_file_to_image(game->mlx, path, \
			&(game->ammo[index].width), &(game->ammo[index].height));
		if (!game->ammo[index].img)
		{
			print_error(RED"Error: Ammo bar tex could not be loaded: ");
			print_error("%s\n"RESET, path);
			close_window_b(game);
		}
		game->ammo[index].addr = mlx_get_data_addr(\
			game->ammo[index].img, &game->ammo[index].bpp, \
			&game->ammo[index].line_len, &game->ammo[index].endian);
		if (!game->ammo[index].addr)
		{
			print_error(RED"Error: Ammo bar tex addr is NULL\n"RESET);
			close_window_b(game);
		}
		index++;
	}
}

void	init_mlx_heart_texture_b(t_game *game)
{
	int		index;
	char	*path;

	index = 0;
	while (index < 12)
	{
		path = game->heart_tex[index].path;
		game->heart_tex[index].img = mlx_xpm_file_to_image(game->mlx, path, \
			&(game->heart_tex[index].width), &(game->heart_tex[index].height));
		if (!game->heart_tex[index].img)
		{
			print_error(RED"Error: Heart tex could not be loaded: ");
			print_error("%s\n"RESET, path);
			close_window_b(game);
		}
		game->heart_tex[index].addr = mlx_get_data_addr(\
			game->heart_tex[index].img, &game->heart_tex[index].bpp, \
			&game->heart_tex[index].line_len, &game->heart_tex[index].endian);
		if (!game->ammo[index].addr)
		{
			print_error(RED"Error: Heart tex addr is NULL!\n"RESET);
			close_window_b(game);
		}
		index++;
	}
}

void	init_mlx_c_ammo_texture_b(t_game *game)
{
	int		index;
	char	*path;

	index = 0;
	while (index < 12)
	{
		path = game->c_ammo_tex[index].path;
		game->c_ammo_tex[index].img = mlx_xpm_file_to_image(game->mlx, path, \
		&(game->c_ammo_tex[index].width), &(game->c_ammo_tex[index].height));
		if (!game->c_ammo_tex[index].img)
		{
			print_error(RED"Error: c_ammo tex could not be loaded: ");
			print_error("%s\n"RESET, path);
			close_window_b(game);
		}
		game->c_ammo_tex[index].addr = mlx_get_data_addr(\
			game->c_ammo_tex[index].img, &game->c_ammo_tex[index].bpp, \
			&game->c_ammo_tex[index].line_len, &game->c_ammo_tex[index].endian);
		if (!game->ammo[index].addr)
		{
			print_error(RED"Error: c_ammo tex addr is NULL!\n"RESET);
			close_window_b(game);
		}
		index++;
	}
}
