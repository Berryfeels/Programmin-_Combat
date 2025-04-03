/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:59:11 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 16:05:14 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	assign_key_texture(char *line, t_game *game)
{
	char	prefix[4];
	int		i;

	if (!line)
		return (0);
	i = 1;
	while (i <= 7)
	{
		snprintf(prefix, sizeof(prefix), "K%d ", i);
		if (ft_strncmp(line, prefix, strlen(prefix)) == 0)
		{
			if (game->key_tex[i - 1].path)
			{
				free(game->key_tex[i - 1].path);
				game->duplicate = 1;
			}
			game->key_tex[i - 1].path = \
				ft_strdup2(str_start_b(line + strlen(prefix)));
			return (1);
		}
		i++;
	}
	return (0);
}

int	assign_door_texture(char *line, t_game *game)
{
	char	prefix[4];
	int		i;

	i = 1;
	while (i <= 6)
	{
		snprintf(prefix, sizeof(prefix), "D%d ", i);
		if (ft_strncmp(line, prefix, strlen(prefix)) == 0)
		{
			if (game->textures[DOOR_1 + (i - 1)].path)
			{
				free(game->textures[DOOR_1 + (i - 1)].path);
				game->duplicate = 1;
			}
			game->textures[DOOR_1 + (i - 1)].path = \
				ft_strdup2(str_start_b(line + strlen(prefix)));
			return (1);
		}
		i++;
	}
	return (0);
}

static int	assign_gun_texture(char *line, t_game *game)
{
	if (ft_strncmp(line, "G ", 2) == 0)
	{
		if (game->gun[GUN].path)
		{
			free(game->gun[GUN].path);
			game->duplicate = 1;
		}
		game->gun[GUN].path = ft_strdup2(str_start_b(line + 1));
	}
	else if (ft_strncmp(line, "GS ", 3) == 0)
	{
		if (game->gun[GUN_SHUT].path)
		{
			free(game->gun[GUN_SHUT].path);
			game->duplicate = 1;
		}
		game->gun[GUN_SHUT].path = ft_strdup2(str_start_b(line + 2));
	}
	else
		return (0);
	return (1);
}

static int	assign_color_texture(char *line, t_game *game)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (game->color[FLOOR].col_tex_str)
		{
			free(game->color[FLOOR].col_tex_str);
			game->duplicate = 1;
		}
		game->color[FLOOR].col_tex_str = ft_strdup2(str_start_b(line + 1));
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (game->color[CEILING].col_tex_str)
		{
			free(game->color[CEILING].col_tex_str);
			game->duplicate = 1;
		}
		game->color[CEILING].col_tex_str = ft_strdup2(str_start_b(line + 1));
	}
	else
		return (0);
	return (1);
}

int	check_line_b(char *line, t_game *game)
{
	if (!line)
		return (1);
	if (assign_texture(line, game) || assign_health_texture(line, game) || \
		assign_ammo_texture(line, game) || assign_heart_texture(line, game) || \
		assign_c_ammo_texture(line, game) || assign_key_texture(line, game) || \
		assign_door_texture(line, game) || assign_gun_texture(line, game) || \
		assign_color_texture(line, game) || assign_sprite(line, game) || \
		assign_sky_texture(line, game) || assign_final_door_texture(line, game))
		return (1);
	else if (ft_strnstr(line, "111", ft_strlen(line)) && \
					game->map_started == 0)
	{
		file_data_order_b(game);
		game->map_started = 1;
		append_map_line_b(game, line);
	}
	else if (ft_strchr("10NSWEDZFHAK \t", line[0]) && game->map_started == 1)
		append_map_line_b(game, line);
	else if (!is_all_space(line))
	{
		game->order = 1;
		printf(RED"Error: Unknown key '%s'\n"RESET, line);
	}
	return (1);
}
