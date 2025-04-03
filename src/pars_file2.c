/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_file2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:42:47 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 15:51:59 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	assign_texture(char *line, t_game *game)
{
	const char	*prefixes[4];
	int			i;

	prefixes[0] = "NO ";
	prefixes[1] = "SO ";
	prefixes[2] = "WE ";
	prefixes[3] = "EA ";
	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(line, prefixes[i], 3) == 0)
		{
			if (game->textures[i].path)
			{
				free(game->textures[i].path);
				game->duplicate = 1;
			}
			game->textures[i].path = ft_strdup2(str_start(line + 2));
			return (1);
		}
		i++;
	}
	return (0);
}

int	assign_color(char *line, t_game *game)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (game->color[FLOOR].col_tex_str)
		{
			free(game->color[FLOOR].col_tex_str);
			game->duplicate = 1;
		}
		game->color[FLOOR].col_tex_str = ft_strdup2(str_start(line + 1));
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (game->color[CEILING].col_tex_str)
		{
			free(game->color[CEILING].col_tex_str);
			game->duplicate = 1;
		}
		game->color[CEILING].col_tex_str = ft_strdup2(str_start(line + 1));
	}
	else
		return (0);
	return (1);
}
