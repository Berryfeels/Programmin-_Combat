/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:39:15 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:39:16 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_wall_texture_pixel(t_texture *texture, int x, int y, int tex_id)
{
	char	*dst;
	int		color;

	if (!texture || tex_id < 0 || tex_id >= 5)
	{
		print_error(RED"Error: Invalid texture ID %d\n"RESET, tex_id);
		return (-1);
	}
	if (!texture[tex_id].addr)
	{
		print_error(RED"Error: texture[%d].addr is NULL\n"RESET, tex_id);
		return (-1);
	}
	if (x < 0 || x >= texture[tex_id].width || y < 0 || \
				y >= texture[tex_id].height)
	{
		print_error(RED"Error: Invalid coordinates for texture[%d]\n"RESET, \
					tex_id);
		return (-1);
	}
	dst = texture[tex_id].addr + (y * texture[tex_id].line_len + \
				x * (texture[tex_id].bpp / 8));
	color = 0;
	memcpy(&color, dst, sizeof(int));
	return (color);
}

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
	{
		print_error(RED"Error: Pixel (%d, %d) out of bounds!\n"RESET, x, y);
		return ;
	}
	if (!game->img || !game->addr)
	{
		print_error(RED"Error: Image buffer is not initialized!\n"RESET);
		return ;
	}
	dst = game->addr + (y * game->line_len + x * (game->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	calculate_texture_params(t_game *game, t_ray *ray, int tex_id, \
									t_texture_params *params)
{
	double	wall_x;

	if (ray->side == 0)
		wall_x = game->player.y + ray->walldist * ray->diry;
	else
		wall_x = game->player.x + ray->walldist * ray->dirx;
	wall_x -= floor(wall_x);
	params->tex_x = (int)(wall_x * game->textures[tex_id].width);
	if (params->tex_x < 0)
		params->tex_x = 0;
	if (params->tex_x >= game->textures[tex_id].width)
		params->tex_x = game->textures[tex_id].width - 1;
	params->step = (double)game->textures[tex_id].height / ray->lineheight;
	params->tex_pos = (ray->drawstart - SCREEN_HEIGHT / 2 + \
						ray->lineheight / 2) * params->step;
}

static void	render_wall_slice(t_game *game, t_ray *ray, int x, int tex_id)
{
	t_texture_params	params;
	int					tex_y;
	int					color;
	int					y;

	y = ray->drawstart;
	calculate_texture_params(game, ray, tex_id, &params);
	while (y < ray->drawend)
	{
		if (y < 0 || y >= SCREEN_HEIGHT)
			continue ;
		tex_y = (int)fmod(params.tex_pos, game->textures[tex_id].height);
		params.tex_pos += params.step;
		color = get_wall_texture_pixel(game->textures, params.tex_x, \
										tex_y, tex_id);
		if ((color & 0xFF000000) == 0x00000000)
			my_mlx_pixel_put(game, x, y, color);
		y++;
	}
}

/**
 * cast_rays - Main raycasting function to render the scene
 * @game: Pointer to the game structure
 *
 * This function loops through all screen columns, casting a ray per column,
 * computing intersections with walls, and rendering the correct wall slices.
 *
 * Loop Through Each Vertical Screen Column → Each column represents a ray.
	Initialize Ray (t_ray) → Calculate its direction based
	on the player’s position.
	Use DDA Algorithm to Find Wall Hits → Step through the grid
	to detect where the ray collides with a wall.
	Compute Distance to Wall → Needed for scaling wall height.
	Draw the Wall Strip → Convert the 3D projection into
	vertical lines on the screen.
 */
void	cast_rays(t_game *game)
{
	t_ray	ray;
	int		x;
	int		tex_id;

	x = 0;
	init_ray(&ray);
	while (x < SCREEN_WIDTH)
	{
		init_mlx_ray(&ray, game, x);
		calculate_step(&ray, game);
		perform_dda(&ray, game);
		calculate_wall_height(&ray);
		tex_id = select_texture(&ray);
		render_wall_slice(game, &ray, x, tex_id);
		x++;
	}
}
