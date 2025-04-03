/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stdi-pum <stdi-pum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:57:04 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 15:30:40 by stdi-pum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	init_texture_b(t_texture *textures, int index, int dim)
{
	textures[index].addr = NULL;
	textures[index].img = NULL;
	textures[index].path = NULL;
	textures[index].height = dim;
	textures[index].width = dim;
}

void	init_wall_door_textures(t_game *game)
{
	init_texture_b(game->textures, NORTH, 64);
	init_texture_b(game->textures, SOUTH, 64);
	init_texture_b(game->textures, WEST, 64);
	init_texture_b(game->textures, EAST, 64);
	init_texture_b(game->textures, DOOR_1, 256);
	init_texture_b(game->textures, DOOR_2, 256);
	init_texture_b(game->textures, DOOR_3, 256);
	init_texture_b(game->textures, DOOR_4, 256);
	init_texture_b(game->textures, DOOR_5, 256);
	init_texture_b(game->textures, DOOR_6, 256);
	init_texture_b(game->textures, FINAL_DOOR, 256);
	init_texture_b(game->textures, ZOMBIE_0, 220);
	init_texture_b(game->textures, ZOMBIE_1, 220);
	init_texture_b(game->textures, ZOMBIE_2, 220);
}
