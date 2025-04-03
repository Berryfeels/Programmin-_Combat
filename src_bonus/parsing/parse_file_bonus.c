/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:58:50 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 16:13:42 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	append_map_line_b(t_game *game, char *line)
{
	int		i;
	char	**new_map;

	i = 0;
	while (game->map && game->map[i])
		i++;
	new_map = malloc((i + 2) * sizeof(char *));
	if (!new_map)
		return ;
	i = 0;
	while (game->map && game->map[i])
	{
		new_map[i] = game->map[i];
		i++;
	}
	new_map[i] = ft_strdup(line);
	if (!new_map[i])
	{
		free(new_map);
		return ;
	}
	new_map[i + 1] = NULL;
	free(game->map);
	game->map = new_map;
}

char	*str_start_b(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

static void	check_texture_paths(t_game *game)
{
	if (!game->textures[NORTH].path || !game->textures[SOUTH].path || \
		!game->textures[WEST].path || !game->textures[EAST].path || \
		!game->color[FLOOR].col_tex_str || \
		(!game->color[CEILING].col_tex_str && !game->color[SKY].col_tex_str) || \
		!game->gun[GUN].path || !game->gun[GUN_SHUT].path || \
		!game->textures[DOOR_1].path || !game->textures[DOOR_2].path || \
		!game->textures[DOOR_3].path || !game->textures[DOOR_4].path || \
		!game->textures[FINAL_DOOR].path || !game->textures[ZOMBIE_0].path || \
		!game->textures[ZOMBIE_1].path || !game->textures[ZOMBIE_2].path || \
		!game->textures[DOOR_5].path || !game->textures[DOOR_6].path)
	{
		game->order = 1;
	}
}

void	file_data_order_b(t_game *game)
{
	check_texture_paths(game);
	check_ammo_paths(game, 0, 7);
	check_c_ammo_paths(game, 0, 12);
	check_heart_paths(game, 0, 12);
	check_health_paths(game, 0, 5);
	check_key_paths(game, 0, 7);
	if (game->order == 1)
	{
		print_error(RED"Error: cub file data is not in order or"RESET);
		print_error(RED" one/more texture is missing\n"RESET);
	}
}

int	pars_file_b(const char *filename, t_game *game)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (print_error(RED"Error: Could not open file %s\n"RESET, \
				filename), 0);
	if (!validate_file_b(filename))
	{
		close(fd);
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		check_line_b(line, game);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (game->duplicate == 1)
		print_error(RED"Error: Duplicate texture path\n"RESET);
	if (game->order || game->duplicate || !validate_cub_elements_b(game))
		return (0);
	return (1);
}
