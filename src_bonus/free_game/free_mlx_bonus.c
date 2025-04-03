/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:56:25 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:56:26 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_mlx_gun_sprite_b(t_game *game)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (game->gun[i].img)
			mlx_destroy_image(game->mlx, game->gun[i].img);
		i++;
	}
	free(game->z_buffer);
}

static void	free_mlx_wall_tex_color_b(t_game *game)
{
	int	i;

	i = 0;
	while (i < 14)
	{
		if (game->textures[i].img)
			mlx_destroy_image(game->mlx, game->textures[i].img);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (game->color[i].img)
			mlx_destroy_image(game->mlx, game->color[i].img);
		i++;
	}
}

static void	free_mlx_heart_health_b(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->health_bar[i].img)
			mlx_destroy_image(game->mlx, game->health_bar[i].img);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		if (game->heart_tex[i].img)
			mlx_destroy_image(game->mlx, game->heart_tex[i].img);
		i++;
	}
}

static void	free_mlx_ammo_key_b(t_game *game)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		if (game->ammo[i].img)
			mlx_destroy_image(game->mlx, game->ammo[i].img);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		if (game->c_ammo_tex[i].img)
			mlx_destroy_image(game->mlx, game->c_ammo_tex[i].img);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		if (game->key_tex[i].img)
			mlx_destroy_image(game->mlx, game->key_tex[i].img);
		i++;
	}
}

void	free_mlx_b(t_game *game)
{
	free_mlx_wall_tex_color_b(game);
	free_mlx_heart_health_b(game);
	free_mlx_ammo_key_b(game);
	free_mlx_gun_sprite_b(game);
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
