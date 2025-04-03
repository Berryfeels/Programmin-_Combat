/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_c_ammo_heart_key_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:56:50 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:56:51 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_heart_tex_b(t_heart_tex *heart_tex, int dim)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		heart_tex[i].addr = NULL;
		heart_tex[i].img = NULL;
		heart_tex[i].path = NULL;
		heart_tex[i].height = dim;
		heart_tex[i].width = dim;
		i++;
	}
}

void	init_c_ammo_tex_b(t_c_ammo_tex *c_ammo_tex, int dim)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		c_ammo_tex[i].addr = NULL;
		c_ammo_tex[i].img = NULL;
		c_ammo_tex[i].path = NULL;
		c_ammo_tex[i].height = dim;
		c_ammo_tex[i].width = dim;
		i++;
	}
}

void	init_key_tex_b(t_key_tex *key_tex, int width, int height)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		key_tex[i].addr = NULL;
		key_tex[i].img = NULL;
		key_tex[i].path = NULL;
		key_tex[i].height = height;
		key_tex[i].width = width;
		i++;
	}
}
