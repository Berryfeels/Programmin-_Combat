/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Key_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:57:09 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/01 17:57:10 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	press_key_b(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_window_b(game);
	else if (keycode == XK_w)
		game->keys[KEY_W] = 1;
	else if (keycode == XK_s)
		game->keys[KEY_S] = 1;
	else if (keycode == XK_a)
		game->keys[KEY_A] = 1;
	else if (keycode == XK_d)
		game->keys[KEY_D] = 1;
	else if (keycode == XK_Left)
		game->keys[KEY_LEFT] = 1;
	else if (keycode == XK_Right)
		game->keys[KEY_RIGHT] = 1;
	else if (keycode == XK_Control_L)
		shoot_gun(game);
	else if (keycode == XK_space)
		door_door(game);
	return (0);
}

int	release_key_b(int keycode, t_game *game)
{
	if (keycode == XK_w)
		game->keys[KEY_W] = 0;
	else if (keycode == XK_s)
		game->keys[KEY_S] = 0;
	else if (keycode == XK_a)
		game->keys[KEY_A] = 0;
	else if (keycode == XK_d)
		game->keys[KEY_D] = 0;
	else if (keycode == XK_Left)
		game->keys[KEY_LEFT] = 0;
	else if (keycode == XK_Right)
		game->keys[KEY_RIGHT] = 0;
	return (0);
}
