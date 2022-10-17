/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:12:29 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 11:47:51 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_get_sidedist(t_data *game)
{
	if (game->rays.raydirx < 0)
	{
		game->rays.stepx = -1;
		game->rays.sidedistx = (game->rays.posx -
									game->rays.mapx) * game->rays.deltadistx;
	}
	else
	{
		game->rays.stepx = 1;
		game->rays.sidedistx = (game->rays.mapx + 1.0 -
									game->rays.posx) * game->rays.deltadistx;
	}
	if (game->rays.raydiry < 0)
	{
		game->rays.stepy = -1;
		game->rays.sidedisty = (game->rays.posy -
									game->rays.mapy) * game->rays.deltadisty;
	}
	else
	{
		game->rays.stepy = 1;
		game->rays.sidedisty = (game->rays.mapy + 1.0 -
									game->rays.posy) * game->rays.deltadisty;
	}
	ft_dda(game);
}

void	ft_dda(t_data *game)
{
	while (game->rays.hit == 0)
	{
		if (game->rays.sidedistx < game->rays.sidedisty)
		{
			game->rays.sidedistx += game->rays.deltadistx;
			game->rays.mapx += game->rays.stepx;
			game->rays.side = 0;
		}
		else
		{
			game->rays.sidedisty += game->rays.deltadisty;
			game->rays.mapy += game->rays.stepy;
			game->rays.side = 1;
		}
		if (game->pars->map[game->rays.mapx][game->rays.mapy] == '1')
			game->rays.hit = 1;
	}
	if (game->rays.side == 0)
		game->rays.perpwalldist = (game->rays.mapx - game->rays.posx +
						(1 - game->rays.stepx) / 2) / game->rays.raydirx;
	else
		game->rays.perpwalldist = (game->rays.mapy - game->rays.posy +
						(1 - game->rays.stepy) / 2) / game->rays.raydiry;
	ft_drawdata(game);
}

void	ft_drawdata(t_data *game)
{
	game->rays.lineheight = (int)(game->pars->resy / game->rays.perpwalldist);
	game->rays.drawstart = -(game->rays.lineheight) / 2 + game->pars->resy / 2;
	if (game->rays.drawstart < 0)
		game->rays.drawstart = 0;
	game->rays.drawend = game->rays.lineheight / 2 + game->pars->resy / 2;
	if (game->rays.drawend >= game->pars->resy)
		game->rays.drawend = game->pars->resy - 1;
}
