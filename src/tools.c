/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:42:32 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 16:02:39 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_two_dim(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	two_dim_len(char **arr)
{
	int	count;

	if (!arr)
		return (0);
	count = 0;
	while (arr[count])
		count++;
	return (count);
}

/**
 * select_texture - Determines which texture to use for a wall
 * @ray: Pointer to the ray structure
 *
 * This function selects the appropriate texture based on the direction
 * the ray was traveling when it hit a wall.
 * Returns: The texture index (NORTH, SOUTH, EAST, or WEST).
 */
int	select_texture(t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->dirx > 0)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (ray->diry > 0)
			return (SOUTH);
		else
			return (NORTH);
	}
	return (EAST);
}

int	rgb_to_hex(int r, int g, int b)
{
	if (r < 0)
		r = 0;
	if (r > 255)
		r = 255;
	if (g < 0)
		g = 0;
	if (g > 255)
		g = 255;
	if (b < 0)
		b = 0;
	if (b > 255)
		b = 255;
	return ((r << 16) | (g << 8) | b);
}
