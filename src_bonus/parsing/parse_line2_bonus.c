/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:59:15 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 16:06:06 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
			game->textures[i].path = ft_strdup2(str_start_b(line + 2));
			return (1);
		}
		i++;
	}
	return (0);
}

int	assign_health_texture(char *line, t_game *game)
{
	char	prefix[4];
	int		i;

	if (!line)
		return (0);
	i = 1;
	while (i <= 5)
	{
		snprintf(prefix, sizeof(prefix), "H%d ", i);
		if (ft_strncmp(line, prefix, strlen(prefix)) == 0)
		{
			if (game->health_bar[i - 1].path)
			{
				free(game->health_bar[i - 1].path);
				game->duplicate = 1;
			}
			game->health_bar[i - 1].path = \
				ft_strdup2(str_start_b(line + strlen(prefix)));
			return (1);
		}
		i++;
	}
	return (0);
}

int	assign_ammo_texture(char *line, t_game *game)
{
	char	prefix[4];
	int		i;

	if (!line)
		return (0);
	i = 0;
	while (i <= 6)
	{
		snprintf(prefix, sizeof(prefix), "A%d ", i);
		if (ft_strncmp(line, prefix, strlen(prefix)) == 0)
		{
			if (game->ammo[i].path)
			{
				free(game->ammo[i].path);
				game->duplicate = 1;
			}
			game->ammo[i].path = ft_strdup2(str_start_b(line + strlen(prefix)));
			return (1);
		}
		i++;
	}
	return (0);
}

int	assign_heart_texture(char *line, t_game *game)
{
	char	prefix[6];
	int		i;

	if (!line)
		return (0);
	i = 1;
	while (i <= 12)
	{
		snprintf(prefix, sizeof(prefix), "R%d ", i);
		if (ft_strncmp(line, prefix, strlen(prefix)) == 0)
		{
			if (game->heart_tex[i - 1].path)
			{
				free(game->heart_tex[i - 1].path);
				game->duplicate = 1;
			}
			game->heart_tex[i - 1].path = \
				ft_strdup2(str_start_b(line + strlen(prefix)));
			return (1);
		}
		i++;
	}
	return (0);
}

int	assign_c_ammo_texture(char *line, t_game *game)
{
	char	prefix[6];
	int		i;

	if (!line)
		return (0);
	i = 1;
	while (i <= 12)
	{
		snprintf(prefix, sizeof(prefix), "CA%d ", i);
		if (ft_strncmp(line, prefix, strlen(prefix)) == 0)
		{
			if (game->c_ammo_tex[i - 1].path)
			{
				free(game->c_ammo_tex[i - 1].path);
				game->duplicate = 1;
			}
			game->c_ammo_tex[i - 1].path = \
				ft_strdup2(str_start_b(line + strlen(prefix)));
			return (1);
		}
		i++;
	}
	return (0);
}
