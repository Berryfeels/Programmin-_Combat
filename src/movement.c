/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 17:41:07 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 13:44:30 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_player(t_game *game)
{
	if (game->keys[KEY_W])
		move_player(FORWARD, game);
	if (game->keys[KEY_S])
		move_player(BACKWARD, game);
	if (game->keys[KEY_A])
		move_player(LEFT, game);
	if (game->keys[KEY_D])
		move_player(RIGHT, game);
	if (game->keys[KEY_LEFT])
		rotate_player(LEFT_ROTATE, game);
	if (game->keys[KEY_RIGHT])
		rotate_player(RIGHT_ROTATE, game);
}

void	rotate_player(int direction, t_game *game)
{
	double	rotate_speed;
	double	old_dir_x;
	double	old_plane_x;
	double	angle;

	rotate_speed = 0.01;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	if (direction == LEFT_ROTATE)
		angle = -rotate_speed;
	else
		angle = rotate_speed;
	game->player.dir_x = game->player.dir_x * cos(angle) - \
							game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + \
							game->player.dir_y * cos(angle);
	game->player.plane_x = game->player.plane_x * cos(angle) - \
							game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle) + \
							game->player.plane_y * cos(angle);
}

static void	calculate_new_position(int direction, \
			t_game *game, double *new_x, double *new_y)
{
	if (direction == FORWARD)
	{
		*new_x += game->player.dir_x * MOVE_SPEED;
		*new_y += game->player.dir_y * MOVE_SPEED;
	}
	else if (direction == BACKWARD)
	{
		*new_x -= game->player.dir_x * MOVE_SPEED;
		*new_y -= game->player.dir_y * MOVE_SPEED;
	}
	else if (direction == LEFT)
	{
		*new_x -= game->player.plane_x * MOVE_SPEED;
		*new_y -= game->player.plane_y * MOVE_SPEED;
	}
	else if (direction == RIGHT)
	{
		*new_x += game->player.plane_x * MOVE_SPEED;
		*new_y += game->player.plane_y * MOVE_SPEED;
	}
}

void	move_player(int direction, t_game *game)
{
	double	new_x;
	double	new_y;

	new_x = game->player.x;
	new_y = game->player.y;
	calculate_new_position(direction, game, &new_x, &new_y);
	if (game->map[(int)new_y][(int)new_x] != '1')
	{
		game->player.x = new_x;
		game->player.y = new_y;
	}
}

int	mouse_rotate(int x, int y, t_game *game)
{
	static int	last_x;
	int			dx;
	double		rotation_speed;
	double		old_dir_x;
	double		old_plane_x;

	last_x = SCREEN_WIDTH / 2;
	dx = x - last_x;
	rotation_speed = ROTATE_SPEED * 0.5 * dx / 60.0;
	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(rotation_speed) - \
						game->player.dir_y * sin(rotation_speed);
	game->player.dir_y = old_dir_x * sin(rotation_speed) + game->player.dir_y * \
						cos(rotation_speed);
	game->player.plane_x = game->player.plane_x * cos(rotation_speed) - \
						game->player.plane_y * sin(rotation_speed);
	game->player.plane_y = old_plane_x * sin(rotation_speed) + \
			game->player.plane_y * cos(rotation_speed);
	last_x = SCREEN_WIDTH / 2;
	(void)y;
	return (0);
}
