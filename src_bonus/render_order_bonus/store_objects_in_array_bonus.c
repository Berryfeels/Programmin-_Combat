/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_objects_in_array_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:00:09 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:00:10 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	store_sprites_in_array(t_game *game, \
			t_renderable *renderables, int *index)
{
	int	i;

	i = 0;
	while (i < game->sprite_count)
	{
		renderables[*index].distance = game->sprites[i].distance;
		renderables[*index].type = 1;
		renderables[*index].object = &game->sprites[i];
		(*index)++;
		i++;
	}
}

static void	store_hearts_in_array(t_game *game, \
			t_renderable *renderables, int *index)
{
	int	i;

	i = 0;
	while (i < game->heart_count)
	{
		renderables[*index].distance = game->heart[i].distance;
		renderables[*index].type = 2;
		renderables[*index].object = &game->heart[i];
		(*index)++;
		i++;
	}
}

static void	store_c_ammo_in_array(t_game *game, \
			t_renderable *renderables, int *index)
{
	int	i;

	i = 0;
	while (i < game->c_ammo_count)
	{
		renderables[*index].distance = game->c_ammo[i].distance;
		renderables[*index].type = 3;
		renderables[*index].object = &game->c_ammo[i];
		(*index)++;
		i++;
	}
}

static void	store_keys_in_array(t_game *game, \
			t_renderable *renderables, int *index)
{
	int	i;

	i = 0;
	while (i < game->key_count)
	{
		renderables[*index].distance = game->key[i].distance;
		renderables[*index].type = 4;
		renderables[*index].object = &game->key[i];
		(*index)++;
		i++;
	}
}

void	store_objects_in_array(t_game *game, t_renderable *renderables)
{
	int	index;

	index = 0;
	store_sprites_in_array(game, renderables, &index);
	store_hearts_in_array(game, renderables, &index);
	store_c_ammo_in_array(game, renderables, &index);
	store_keys_in_array(game, renderables, &index);
}
