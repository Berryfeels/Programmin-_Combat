/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:58:14 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:58:15 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	print_textures(const t_texture textures[])
{
	printf("Textures:::\n---------------------------- \n");
	printf("NO %s\n", textures[NORTH].path);
	printf("SO %s\n", textures[SOUTH].path);
	printf("WE %s\n", textures[WEST].path);
	printf("EA %s\n", textures[EAST].path);
}

static void	print_color_info(const t_color *color, const char *type)
{
	if (color->mode == 1)
	{
		printf("%s color r: %d\n", type, color->r);
		printf("%s color g: %d\n", type, color->g);
		printf("%s color b: %d\n", type, color->b);
	}
	else if (color->mode == 2)
		printf("%s texture: %s\n", type, color->col_tex_str);
}

static void	print_map_coordinates(const t_game *game)
{
	int	i;
	int	j;

	printf(GREEN"^\n"RED" > 0  "RESET);
	i = 1;
	j = 0;
	while (j < game->width)
	{
		if (i > 9)
			i = 0;
		printf(RED"%d  "RESET, i);
		i++;
		j++;
	}
	printf("\n\n");
}

static void	print_map_grid(const t_game *game)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	while (game->map[i] && i < game->height)
	{
		printf(GREEN);
		width = 0;
		if (game->height - i - 1 <= 9)
			width = 2;
		printf("%*d ", width, game->height - i - 1);
		printf(RESET);
		j = 0;
		while (game->map[i][j])
			printf(" %c ", game->map[i][j++]);
		printf("\n");
		i++;
	}
}

void	print_struct_b(t_game *game)
{
	print_textures(game->textures);
	printf("\n\nFloor and Ceiling Color:::\n---------------------------- \n");
	print_color_info(&game->color[FLOOR], "floor");
	print_color_info(&game->color[CEILING], "ceiling");
	printf("\n\nPlayer Position:::\n---------------------------- \n");
	printf("player x: %f\n", game->player.x);
	printf("player y: %f\n", game->height - game->player.y - 1);
	printf("player direction: %s\n", game->player.ini_dir);
	printf("\n\nGame Dimensions:::\n---------------------------- \n");
	printf("Width: %d\nHeight: %d\n", game->width, game->height);
	printf("\n\nMAP:::\n---------------------------- \n");
	print_map_grid(game);
	print_map_coordinates(game);
}
