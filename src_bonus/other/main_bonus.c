/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:58:19 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 12:38:54 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	open_game(char *selected_map, t_start_page *start_page)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
	{
		print_error(RED"Error: Memory allocation failed\n"RESET);
		return (1);
	}
	init_game_b(game);
	game->start_page = start_page;
	if (!pars_file_b(selected_map, game))
	{
		close_window_b(game);
		return (1);
	}
	create_window_b(game);
	close_window_b(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_start_page	*start_page;

	(void)(argv);
	if (argc > 1)
	{
		print_error(RED"Error: Bonus does not require any arguments\n"RESET);
		return (1);
	}
	start_page = ft_calloc(1, sizeof(t_start_page));
	if (!start_page)
	{
		print_error(RED"Error: Memory allocation failed\n"RESET);
		return (1);
	}
	start(start_page);
	open_game(start_page->selected_map, start_page);
	return (0);
}

void	game_over(void)
{
	printf("\033[1;31m");
	printf("   ██████  █████  ███	███ ███████     \n");
	printf("  ██      ██   ██ ████  ████ ██          \n");
	printf("  ██      ███████ ██ ████ ██ █████       \n");
	printf("  ██   ██ ██   ██ ██  ██  ██ ██          \n");
	printf("   ██████ ██   ██ ██      ██ ███████     \n");
	printf("                                         \n");
	printf("    ████   ██     ██ ███████ █████       \n");
	printf("  ██    ██ ██     ██ ██      ██  ██      \n");
	printf("  ██    ██ ██     ██ █████   ██████      \n");
	printf("  ██    ██  ██   ██  ██      ██  █       \n");
	printf("    ████     █████   ███████ ██   █      \n");
	printf("\033[0m\n");
}

void	victory(void)
{
	printf(GREEN"");
	printf("\\ \\    / /|_ _||  __||_____| / _ \\ |  _ \\\\  // \n");
	printf(" \\ \\  / /  | | | |     | |  | | | || |_) \\\\V/  \n");
	printf("  \\  V /   | | | |___  | |  | |_| ||  _ < ||   \n");
	printf("   \\__/   |___ \\____|  |_|   \\___/ |_| |_\\||   \n");
	printf(RESET"");
}
