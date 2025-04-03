/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_gun_ray_health_ammo_bar_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:57:01 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:57:02 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_ray_b(t_ray *ray)
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
	ray->door = 0;
	ray->final_door = 0;
}

void	init_mlx_ray_b(t_ray *ray, t_game *game, int x)
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
	calculate_step_b(ray, game);
}

void	init_gun_b(t_gun *gun, int dim, int index)
{
	gun[index].addr = NULL;
	gun[index].img = NULL;
	gun[index].path = NULL;
	gun[index].height = dim;
	gun[index].width = dim;
	gun[index].screen_x = (SCREEN_WIDTH / 2) - (gun[index].width / 2);
	gun[index].screen_y = SCREEN_HEIGHT - gun[index].height;
}

void	init_health_bar_b(t_health *health_bar, int width, int height)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		health_bar[i].addr = NULL;
		health_bar[i].img = NULL;
		health_bar[i].path = NULL;
		health_bar[i].height = height;
		health_bar[i].width = width;
		health_bar[i].screen_x = 20;
		health_bar[i].screen_y = SCREEN_HEIGHT - SCREEN_HEIGHT / 8;
		i++;
	}
}

void	init_ammo_b(t_ammo *ammo, int width, int height)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		ammo[i].addr = NULL;
		ammo[i].img = NULL;
		ammo[i].path = NULL;
		ammo[i].height = height;
		ammo[i].width = width;
		ammo[i].screen_x = 20;
		ammo[i].screen_y = SCREEN_HEIGHT - SCREEN_HEIGHT / 13;
		i++;
	}
}
