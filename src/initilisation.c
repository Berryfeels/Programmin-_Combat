/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initilisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:38:26 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 12:41:42 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_colors(t_color *color)
{
	color[FLOOR].col_tex_str = NULL;
	color[FLOOR].r = 0;
	color[FLOOR].g = 0;
	color[FLOOR].b = 0;
	color[FLOOR].hex_color = 0;
	color[FLOOR].height = 128;
	color[FLOOR].width = 128;
	color[CEILING].col_tex_str = NULL;
	color[CEILING].r = 0;
	color[CEILING].g = 0;
	color[CEILING].b = 0;
	color[CEILING].hex_color = 0;
	color[CEILING].height = 128;
	color[CEILING].width = 128;
}

static void	init_texture(t_texture *textures)
{
	textures[NORTH].addr = NULL;
	textures[SOUTH].addr = NULL;
	textures[WEST].addr = NULL;
	textures[EAST].addr = NULL;
	textures[NORTH].img = NULL;
	textures[SOUTH].img = NULL;
	textures[WEST].img = NULL;
	textures[EAST].img = NULL;
	textures[NORTH].path = NULL;
	textures[SOUTH].path = NULL;
	textures[WEST].path = NULL;
	textures[EAST].path = NULL;
	textures[NORTH].height = 64;
	textures[NORTH].width = 64;
	textures[SOUTH].height = 64;
	textures[SOUTH].width = 64;
	textures[WEST].height = 64;
	textures[WEST].width = 64;
	textures[EAST].height = 64;
	textures[EAST].width = 64;
}

void	init_ray(t_ray *ray)
{
	ray->dirx = 0;
	ray->diry = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	ray->side_distx = 0;
	ray->side_disty = 0;
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->walldist = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->side = 0;
	ray->lineheight = 0;
	ray->drawstart = 0;
	ray->drawend = 0;
	ray->camera_x = 0;
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->height = SCREEN_HEIGHT;
	game->width = SCREEN_WIDTH;
	game->map = NULL;
	game->map_started = 0;
	game->order = 0;
	game->duplicate = 0;
	init_texture(game->textures);
	init_colors(game->color);
	game->player.x = 0;
	game->player.y = 0;
	game->player.dir_x = 0;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0;
	game->player.ini_dir = NULL;
}

void	init_mlx_ray(t_ray *ray, t_game *game, int x)
{
	ray->camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->dirx = game->player.dir_x + game->player.plane_x * ray->camera_x;
	ray->diry = game->player.dir_y + game->player.plane_y * ray->camera_x;
	ray->mapx = (int)game->player.x;
	ray->mapy = (int)game->player.y;
	if (ray->dirx == 0)
		ray->deltadistx = 1e30;
	else
		ray->deltadistx = fabs(1 / ray->dirx);
	if (ray->diry == 0)
		ray->deltadisty = 1e30;
	else
		ray->deltadisty = fabs(1 / ray->diry);
	calculate_step(ray, game);
}
