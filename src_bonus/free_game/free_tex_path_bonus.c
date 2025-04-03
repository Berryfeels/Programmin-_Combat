/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tex_path_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:56:29 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:56:30 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_tex4(t_game *game)
{
	if (game->textures[DOOR_1].path)
		free(game->textures[DOOR_1].path);
	if (game->textures[DOOR_2].path)
		free(game->textures[DOOR_2].path);
	if (game->textures[DOOR_3].path)
		free(game->textures[DOOR_3].path);
	if (game->textures[DOOR_4].path)
		free(game->textures[DOOR_4].path);
	if (game->textures[DOOR_5].path)
		free(game->textures[DOOR_5].path);
	if (game->textures[DOOR_6].path)
		free(game->textures[DOOR_6].path);
	if (game->textures[FINAL_DOOR].path)
		free(game->textures[FINAL_DOOR].path);
}

static void	free_tex3(t_game *game)
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
	if (game->color[SKY].col_tex_str)
		free(game->color[SKY].col_tex_str);
	if (game->textures[ZOMBIE_0].path)
		free(game->textures[ZOMBIE_0].path);
	if (game->textures[ZOMBIE_1].path)
		free(game->textures[ZOMBIE_1].path);
	if (game->textures[ZOMBIE_2].path)
		free(game->textures[ZOMBIE_2].path);
	if (game->gun[GUN].path)
		free(game->gun[GUN].path);
	if (game->gun[GUN_SHUT].path)
		free(game->gun[GUN_SHUT].path);
}

static void	free_tex2(t_game *game)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		if (game->c_ammo_tex[i].path)
			free(game->c_ammo_tex[i].path);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		if (game->key_tex[i].path)
			free(game->key_tex[i].path);
		i++;
	}
}

static void	free_tex1(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->health_bar[i].path)
			free(game->health_bar[i].path);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		if (game->heart_tex[i].path)
			free(game->heart_tex[i].path);
		i++;
	}
	i = 0;
	while (i < 7)
	{
		if (game->ammo[i].path)
			free(game->ammo[i].path);
		i++;
	}
}

void	free_textures_path_b(t_game *game)
{
	free_tex1(game);
	free_tex2(game);
	free_tex3(game);
	free_tex4(game);
}
