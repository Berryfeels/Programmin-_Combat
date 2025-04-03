/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tex_path_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:59:03 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 12:21:18 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	check_ammo_paths(t_game *game, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if (!game->ammo[i].path)
		{
			game->order = 1;
		}
		i++;
	}
}

void	check_c_ammo_paths(t_game *game, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if (!game->c_ammo_tex[i].path)
		{
			game->order = 1;
		}
		i++;
	}
}

void	check_heart_paths(t_game *game, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if (!game->heart_tex[i].path)
		{
			game->order = 1;
		}
		i++;
	}
}

void	check_health_paths(t_game *game, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if (!game->health_bar[i].path)
		{
			game->order = 1;
		}
		i++;
	}
}

void	check_key_paths(t_game *game, int start, int end)
{
	int	i;

	i = start;
	while (i < end)
	{
		if (!game->key_tex[i].path)
		{
			game->order = 1;
		}
		i++;
	}
}
