/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_destroy_game.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:38:22 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 15:20:57 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mlx(t_game *game)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (game->color[i].img)
			mlx_destroy_image(game->mlx, game->color[i].img);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx && game->img)
		mlx_destroy_image(game->mlx, game->img);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_tex_path(t_game *game)
{
	if (game->textures[NORTH].path)
		free(game->textures[NORTH].path);
	if (game->textures[SOUTH].path)
		free(game->textures[SOUTH].path);
	if (game->textures[WEST].path)
		free(game->textures[WEST].path);
	if (game->textures[EAST].path)
		free(game->textures[EAST].path);
	if (game->color[FLOOR].col_tex_str)
		free(game->color[FLOOR].col_tex_str);
	if (game->color[CEILING].col_tex_str)
		free(game->color[CEILING].col_tex_str);
}

int	close_window(t_game *game)
{
	if (game->map)
		free_two_dim(game->map);
	free_tex_path(game);
	free_mlx(game);
	if ((game->player.ini_dir))
		free(game->player.ini_dir);
	free(game);
	exit(0);
}
