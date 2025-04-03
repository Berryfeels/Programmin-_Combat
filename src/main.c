/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:38:34 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 12:33:33 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	render(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_floor_and_ceiling(game);
	cast_rays(game);
	update_player(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc < 2)
		return (print_error(RED"Error: Please provide a map file\n"RESET), 1);
	if (argc > 2)
		return (print_error(RED"Error: Multiple arguments\n"RESET), 1);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		print_error(RED"Error: Memory allocation failed\n"RESET);
		return (1);
	}
	init_game(game);
	if (!pars_file(argv[1], game, argv))
	{
		close_window(game);
		return (1);
	}
	create_window(game);
	close_window(game);
	return (0);
}
