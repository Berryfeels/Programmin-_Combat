/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:41:18 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 16:06:26 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	assign_sprite(char *line, t_game *game)
{
	const char	*prefixes[3];
	int			i;

	prefixes[0] = "Z0 ";
	prefixes[1] = "Z1 ";
	prefixes[2] = "Z2 ";
	i = 0;
	while (i < 3)
	{
		if (ft_strncmp(line, prefixes[i], 3) == 0)
		{
			if (game->textures[i + 4].path)
			{
				free(game->textures[i + 4].path);
				game->duplicate = 1;
			}
			game->textures[i + 4].path = ft_strdup2(str_start_b(line + 2));
			return (1);
		}
		i++;
	}
	return (0);
}

int	assign_sky_texture(char *line, t_game *game)
{
	if (ft_strncmp(line, "SK ", 3) == 0)
	{
		if (game->color[SKY].col_tex_str)
		{
			free(game->color[SKY].col_tex_str);
			game->duplicate = 1;
		}
		game->color[SKY].col_tex_str = ft_strdup2(str_start_b(line + 2));
	}
	else
		return (0);
	return (1);
}

int	assign_final_door_texture(char *line, t_game *game)
{
	if (ft_strncmp(line, "END ", 4) == 0)
	{
		if (game->textures[FINAL_DOOR].path)
		{
			free(game->textures[FINAL_DOOR].path);
			game->duplicate = 1;
		}
		game->textures[FINAL_DOOR].path = ft_strdup2(str_start_b(line + 4));
		return (1);
	}
	return (0);
}
