/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_viewangel_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:58:01 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:58:02 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	update_line_vars(t_line *line)
{
	line->e2 = 2 * line->err;
	if (line->e2 > -line->dy)
	{
		line->err -= line->dy;
		if (line->x0 < line->x1)
			line->x0 += 1;
		else
			line->x0 -= 1;
	}
	if (line->e2 < line->dx)
	{
		line->err += line->dx;
		if (line->y0 < line->y1)
			line->y0 += 1;
		else
			line->y0 -= 1;
	}
}

void	draw_line_b(t_game *game, t_line *line, int color)
{
	line->dx = abs(line->x1 - line->x0);
	line->dy = abs(line->y1 - line->y0);
	line->err = line->dx - line->dy;
	while (1)
	{
		if (line->x0 >= 0 && line->y0 >= 0
			&& line->x0 < MAX_MINIMAP_WIDTH * game->minimap.tile_size
			&& line->y0 < MAX_MINIMAP_HEIGHT * game->minimap.tile_size)
		{
			draw_tile_b(game, line->x0, line->y0, color);
		}
		if (line->x0 == line->x1 && line->y0 == line->y1)
			break ;
		update_line_vars(line);
	}
}

static void	setup_ray(t_game *game, t_ray *ray, double angle)
{
	ray->mapx = (int)game->player.x;
	ray->mapy = (int)game->player.y;
	ray->dirx = cos(angle);
	ray->diry = sin(angle);
	ray->deltadistx = fabs(1 / ray->dirx);
	ray->deltadisty = fabs(1 / ray->diry);
	calculate_step_b(ray, game);
	perform_dda_b(ray, game);
	calculate_wall_height_b(ray, game, 0);
}

void	draw_view_angle_b(t_game *game, int px, int py)
{
	t_line	line;
	t_ray	ray;
	double	ray_angle;
	int		i;
	int		num_rays;

	num_rays = 20;
	i = -num_rays / 2;
	while (i <= num_rays / 2)
	{
		ray_angle = atan2(game->player.dir_y, game->player.dir_x) + \
							(i * (FOV_FACTOR / num_rays));
		setup_ray(game, &ray, ray_angle);
		line.x0 = px;
		line.y0 = py;
		line.x1 = px + (int)(ray.walldist * ray.dirx * game->minimap.tile_size);
		line.y1 = py + (int)(ray.walldist * ray.diry * game->minimap.tile_size);
		draw_line_b(game, &line, LIGHTBLUE);
		i++;
	}
}
