/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controller.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:08:26 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/08 13:14:52 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_pressed(int keycode, t_data *game)
{
	if (keycode == W_KEY)
		game->keys->move_forward = 1;
	if (keycode == S_KEY)
		game->keys->move_back = 1;
	if (keycode == A_KEY)
		game->keys->move_left = 1;
	if (keycode == D_KEY)
		game->keys->move_right = 1;
	if (keycode == LEFT_KEY)
		game->keys->rotate_left = 1;
	if (keycode == RIGHT_KEY)
		game->keys->rotate_right = 1;
	if (keycode == ESC_KEY)
		ft_exit_game(game);
	return (0);
}

int	key_released(int keycode, t_data *game)
{
	if (keycode == W_KEY)
		game->keys->move_forward = 0;
	if (keycode == S_KEY)
		game->keys->move_back = 0;
	if (keycode == A_KEY)
		game->keys->move_left = 0;
	if (keycode == D_KEY)
		game->keys->move_right = 0;
	if (keycode == LEFT_KEY)
		game->keys->rotate_left = 0;
	if (keycode == RIGHT_KEY)
		game->keys->rotate_right = 0;
	return (0);
}

int	ft_exit_game(t_data *game)
{
	ft_free_game(game);
	exit(0);
}
