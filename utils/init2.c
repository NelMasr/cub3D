/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:00:34 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 12:13:05 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rays_init(t_data *game)
{
	if (!(game->s.zbuffer = (double *)malloc(sizeof(double)
			* game->pars->resx)))
		ft_error("Error ! Could not initiate zbuffer.", game);
	game->rays.posx = (double)game->player_x + 0.5;
	game->rays.posy = (double)game->player_y + 0.5;
	game->rays.dirx = 0;
	game->rays.diry = 0;
	game->rays.planex = 0;
	game->rays.planey = 0;
	ft_init_dir(game);
}

void	rays_init2(t_data *game)
{
	game->rays.hit = 0;
	game->rays.perpwalldist = 0;
	game->rays.camerax = 2 * game->rays.x / (double)game->pars->resx - 1;
	game->rays.raydirx = game->rays.dirx + game->rays.planex *
														game->rays.camerax;
	game->rays.raydiry = game->rays.diry + game->rays.planey *
														game->rays.camerax;
	game->rays.mapx = (int)game->rays.posx;
	game->rays.mapy = (int)game->rays.posy;
	game->rays.movespeed = 0.075;
	game->rays.rotspeed = 0.1 * 1.8;
	ft_init_delta(game);
}

void	ft_init_dir(t_data *game)
{
	if (game->player_orientation == 'N')
	{
		game->rays.dirx = -1;
		game->rays.planey = 0.66;
	}
	if (game->player_orientation == 'S')
	{
		game->rays.dirx = 1;
		game->rays.planey = -0.66;
	}
	if (game->player_orientation == 'W')
	{
		game->rays.diry = -1;
		game->rays.planex = -0.66;
	}
	if (game->player_orientation == 'E')
	{
		game->rays.diry = 1;
		game->rays.planex = 0.66;
	}
}

void	ft_init_delta(t_data *game)
{
	if (game->rays.raydiry == 0)
		game->rays.deltadistx = 0;
	else if (game->rays.raydirx == 0)
		game->rays.deltadistx = 1;
	else
		game->rays.deltadistx = sqrt(1 + (game->rays.raydiry *
			game->rays.raydiry) / (game->rays.raydirx * game->rays.raydirx));
	if (game->rays.raydirx == 0)
		game->rays.deltadisty = 0;
	else if (game->rays.raydiry == 0)
		game->rays.deltadisty = 1;
	else
		game->rays.deltadisty = sqrt(1 + (game->rays.raydirx *
			game->rays.raydirx) / (game->rays.raydiry * game->rays.raydiry));
}

void	ft_init_texdata(t_data *game)
{
	if (game->rays.side == 0 && game->rays.raydirx < 0)
		game->t.texor = 0;
	if (game->rays.side == 0 && game->rays.raydirx >= 0)
		game->t.texor = 1;
	if (game->rays.side == 1 && game->rays.raydiry >= 0)
		game->t.texor = 2;
	if (game->rays.side == 1 && game->rays.raydiry < 0)
		game->t.texor = 3;
	if (game->rays.side == 0)
		game->t.wallx = game->rays.posy + game->rays.perpwalldist *
														game->rays.raydiry;
	else
		game->t.wallx = game->rays.posx + game->rays.perpwalldist *
														game->rays.raydirx;
	game->t.wallx -= floor((game->t.wallx));
}
