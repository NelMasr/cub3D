/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 13:06:27 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/05 15:27:16 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_refresh(t_data *game)
{
	void	*tmp;

	tmp = game->win->img;
	game->win->img = game->win->img2;
	game->win->img2 = tmp;
	tmp = game->win->addr;
	game->win->addr = game->win->addr2;
	game->win->addr2 = tmp;
}
