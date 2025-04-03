/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_order_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:00:04 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:00:05 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	compare_renderables(const void *a, const void *b)
{
	double	dist_a;
	double	dist_b;

	dist_a = ((t_renderable *)a)->distance;
	dist_b = ((t_renderable *)b)->distance;
	return (dist_b - dist_a);
}

static void	render_objects_in_order(t_game *game, \
		t_renderable *renderables, int num_renderables)
{
	int	i;

	i = 0;
	while (i < num_renderables)
	{
		if (renderables[i].type == 1)
			render_sprites(game, (t_sprite *)renderables[i].object);
		else if (renderables[i].type == 2)
			render_hearts(game, (t_heart *)renderables[i].object);
		else if (renderables[i].type == 3)
			render_c_ammo(game, (t_c_ammo *)renderables[i].object);
		else if (renderables[i].type == 4)
			render_key(game, (t_key *)renderables[i].object);
		i++;
	}
}

static void	render_background(t_game *game)
{
	if (game->color[CEILING].col_tex_str)
	{
		draw_floor_and_ceiling_b(game, CEILING);
	}
	else
	{
		draw_floor_and_ceiling_b(game, SKY);
	}
	draw_floor_and_ceiling_b(game, FLOOR);
}

static void	cast_rays_and_update_display(t_game *game)
{
	cast_rays_b(game);
	minimap_b(game);
	update_player_b(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

int	render_b(t_game *game)
{
	int				num_renderables;
	t_renderable	*renderables;

	mlx_clear_window(game->mlx, game->win);
	num_renderables = game->sprite_count + game->heart_count + \
					game->c_ammo_count + game->key_count;
	renderables = malloc(num_renderables * sizeof(t_renderable));
	if (!renderables)
		return (-1);
	store_objects_in_array(game, renderables);
	qsort(renderables, num_renderables, sizeof(t_renderable), \
										compare_renderables);
	render_background(game);
	cast_rays_and_update_display(game);
	render_objects_in_order(game, renderables, num_renderables);
	move_sprites(game);
	render_health_bar_b(game);
	render_ammo_bar_b(game);
	draw_gun_b(game);
	key_found(game);
	free(renderables);
	return (0);
}
