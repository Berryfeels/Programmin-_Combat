/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_tex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:00:26 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:00:27 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_mlx_wall_door_tex(t_game *game)
{
	init_mlx_wall_texture_b(game, NORTH, game->textures[NORTH].path);
	init_mlx_wall_texture_b(game, SOUTH, game->textures[SOUTH].path);
	init_mlx_wall_texture_b(game, WEST, game->textures[WEST].path);
	init_mlx_wall_texture_b(game, EAST, game->textures[EAST].path);
	init_mlx_wall_texture_b(game, DOOR_1, game->textures[DOOR_1].path);
	init_mlx_wall_texture_b(game, DOOR_2, game->textures[DOOR_2].path);
	init_mlx_wall_texture_b(game, DOOR_3, game->textures[DOOR_3].path);
	init_mlx_wall_texture_b(game, DOOR_4, game->textures[DOOR_4].path);
	init_mlx_wall_texture_b(game, DOOR_5, game->textures[DOOR_5].path);
	init_mlx_wall_texture_b(game, DOOR_6, game->textures[DOOR_6].path);
	init_mlx_wall_texture_b(game, FINAL_DOOR, game->textures[FINAL_DOOR].path);
}

void	init_all_mlx_textures_b(t_game *game)
{
	set_mlx_wall_door_tex(game);
	init_mlx_wall_texture_b(game, ZOMBIE_0, game->textures[ZOMBIE_0].path);
	init_mlx_wall_texture_b(game, ZOMBIE_1, game->textures[ZOMBIE_1].path);
	init_mlx_wall_texture_b(game, ZOMBIE_2, game->textures[ZOMBIE_2].path);
	init_mlx_gun_texture_b(game, GUN, game->gun[GUN].path);
	init_mlx_gun_texture_b(game, GUN_SHUT, game->gun[GUN_SHUT].path);
	init_mlx_health_bar_texture_b(game);
	init_mlx_ammo_bar_texture_b(game);
	init_mlx_heart_texture_b(game);
	init_mlx_c_ammo_texture_b(game);
	init_mlx_key_texture_b(game);
	set_heart_cords(game);
	set_c_ammo_cords(game);
	set_sprites_cords(game);
	set_doors(game);
	set_key_cords(game);
	set_colors_b(game, game->color, FLOOR);
	if (game->color[CEILING].col_tex_str)
		set_colors_b(game, game->color, CEILING);
	else
		set_colors_b(game, game->color, SKY);
}
