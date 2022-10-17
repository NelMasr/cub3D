/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 11:43:43 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 11:53:31 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_orddist(t_data *game)
{
	int i;

	i = 0;
	while (i < game->s.nbsp)
	{
		game->s.order[i] = i;
		game->s.distance[i] = ((game->rays.posx - game->spos[i].x) *
								(game->rays.posx - game->spos[i].x) +
								(game->rays.posy - game->spos[i].y) *
								(game->rays.posy - game->spos[i].y));
		i++;
	}
}

void	ft_sort_sprites(t_data *game)
{
	int		i;
	int		j;
	double	tmp;

	i = -1;
	while (++i < game->s.nbsp)
	{
		j = -1;
		while (++j < game->s.nbsp - 1)
		{
			if (game->s.distance[j] < game->s.distance[j + 1])
			{
				tmp = game->s.distance[j];
				game->s.distance[j] = game->s.distance[j + 1];
				game->s.distance[j + 1] = tmp;
				tmp = game->s.order[j];
				game->s.order[j] = game->s.order[j + 1];
				game->s.order[j + 1] = (int)tmp;
			}
		}
	}
}

void	ft_get_sprite_data(t_data *game, int i)
{
	game->s.spritex = game->spos[game->s.order[i]].x - game->rays.posx;
	game->s.spritey = game->spos[game->s.order[i]].y - game->rays.posy;
	game->s.invdet = 1.0 / (game->rays.planex * game->rays.diry -
							game->rays.dirx * game->rays.planey);
	game->s.transformx = game->s.invdet * (game->rays.diry * game->s.spritex -
											game->rays.dirx * game->s.spritey);
	game->s.transformy = game->s.invdet * (-game->rays.planey * game->s.spritex
										+ game->rays.planex * game->s.spritey);
	game->s.spritescreenx = (int)((game->pars->resx / 2) *
							(1 + game->s.transformx / game->s.transformy));
	game->s.spriteheight = abs((int)(game->pars->resy / (game->s.transformy)));
	game->s.drawstarty = -game->s.spriteheight / 2 + game->pars->resy / 2;
	if (game->s.drawstarty < 0)
		game->s.drawstarty = 0;
	game->s.drawendy = game->s.spriteheight / 2 + game->pars->resy / 2;
	if (game->s.drawendy >= game->pars->resy)
		game->s.drawendy = game->pars->resy;
	game->s.spritewidth = abs((int)(game->pars->resy / (game->s.transformy)));
	game->s.drawstartx = -game->s.spritewidth / 2 + game->s.spritescreenx;
	if (game->s.drawstartx < 0)
		game->s.drawstartx = 0;
	game->s.drawendx = game->s.spritewidth / 2 + game->s.spritescreenx;
	if (game->s.drawendx >= game->pars->resx)
		game->s.drawendx = game->pars->resx;
}

void	ft_draw_sprites(t_data *game, int y, int texx, int stripe)
{
	int	d;
	int	texy;

	while (y < game->s.drawendy)
	{
		d = (y) * 256 - game->pars->resy * 128 + game->s.spriteheight * 128;
		texy = ((d * game->textures[4].height) / game->s.spriteheight) / 256;
		if ((unsigned int)game->textures[4].addr[texy *
				game->textures[4].line_length / 4 + texx] != 0xFF000000)
		{
			game->win->addr[y * game->win->line_length / 4 + stripe] =
			game->textures[4].addr[texy * game->textures[4].line_length / 4
																	+ texx];
		}
		y++;
	}
}

void	ft_sprites(t_data *game)
{
	int	i;
	int y;
	int	stripe;
	int	texx;

	ft_init_orddist(game);
	ft_sort_sprites(game);
	i = -1;
	while (++i < game->s.nbsp)
	{
		ft_get_sprite_data(game, i);
		stripe = game->s.drawstartx - 1;
		while (++stripe < game->s.drawendx)
		{
			texx = (int)(256 * (stripe - (-game->s.spritewidth / 2
					+ game->s.spritescreenx)) * game->textures[4].width /
					game->s.spritewidth) / 256;
			if (game->s.transformy > 0 && stripe >= 0 && stripe < game->
					pars->resx && game->s.transformy < game->s.zbuffer[stripe])
			{
				y = game->s.drawstarty;
				ft_draw_sprites(game, y, texx, stripe);
			}
		}
	}
}
