/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceiling_and_floor_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:00:32 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 18:00:33 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_cf_texture_pixel_b(t_color *color, int x, int y, int tex_id)
{
	char	*dst;
	int		cf_color;

	if (!color || tex_id < 0 || tex_id >= 3)
	{
		print_error(RED"Error: Invalid color ID %d\n"RESET, tex_id);
		return (-1);
	}
	if (!color[tex_id].addr)
	{
		print_error(RED"Error: color[%d].addr is NULL\n"RESET, tex_id);
		return (-1);
	}
	if (x < 0 || x >= color[tex_id].width || y < 0 || y >= color[tex_id].height)
	{
		print_error(RED"Error: Invalid coordinates for color \n"RESET);
		return (-1);
	}
	dst = color[tex_id].addr + (y * color[tex_id].line_len + \
			x * (color[tex_id].bpp / 8));
	cf_color = 0;
	ft_memcpy(&cf_color, dst, sizeof(int));
	return (cf_color);
}

void	draw_floor_and_ceiling_b(t_game *game, int index)
{
	if (game->color[index].mode == 1)
	{
		if (index == CEILING)
			draw_ceiling_pixel_b(game);
		else if (index == FLOOR)
			draw_floor_pixel_b(game);
	}
	else
	{
		if (index == CEILING)
			draw_ceiling_texture_b(game);
		else if (index == FLOOR)
			draw_floor_texture_b(game);
		else if (index == SKY)
			draw_sky_texture_b(game);
	}
}
