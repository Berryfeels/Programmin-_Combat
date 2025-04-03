/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:39:29 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:39:30 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	loop_hook(t_game *game)
{
	mlx_hook(game->win, KeyPress, KeyPressMask, press_key, game);
	mlx_hook(game->win, KeyRelease, KeyReleaseMask, release_key, game);
	mlx_hook(game->win, DestroyNotify, ButtonPressMask, &close_window, game);
	mlx_hook(game->win, 17, 0, &close_window, game);
	mlx_loop_hook(game->mlx, &render, game);
	mlx_loop(game->mlx);
}

/*
 * Creates and initializes the game window, textures, and rendering system.
 * Also sets up MLX hooks for user input and rendering.
 *
 * Parameters:
 * - game: Pointer to the main game structure.
 */
void	create_window(t_game *game)
{
	load_player(game);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		print_error(RED"Error! MLX initialization failed!"RESET);
		return ;
	}
	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	if (!game->win)
	{
		free(game->mlx);
		print_error(RED"Error! MLX window creation failed!"RESET);
		return ;
	}
	game->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!game->img)
	{
		print_error(RED"Error: mlx_new_image() failed!\n"RESET);
		return ;
	}
	game->addr = mlx_get_data_addr(game->img, &game->bpp, &game->line_len, \
									&game->endian);
	init_all_mlx_textures(game);
	loop_hook(game);
}
