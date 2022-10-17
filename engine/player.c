/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 11:15:03 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 11:46:04 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_render(t_data *game)
{
	int		i;
	int		j;

	game->rays.drawend = game->pars->resy - game->rays.drawstart;
	j = -1;
	i = game->rays.drawend;
	while (++j < game->rays.drawstart)
		game->win->addr[j * game->win->line_length / 4
										+ game->rays.x] = game->pars->c;
	if (j <= game->rays.drawend)
		ft_draw_textures(game, game->rays.x, j);
	j = i;
	while (++j < game->pars->resy)
		game->win->addr[j * game->win->line_length / 4
										+ game->rays.x] = game->pars->f;
}

void	ft_move_forback(t_data *game)
{
	if (game->keys->move_forward == 1)
	{
		if (game->pars->map
				[(int)(game->rays.posx + game->rays.dirx *
				game->rays.movespeed * 4)][(int)(game->rays.posy)] == '0')
			game->rays.posx += game->rays.dirx * game->rays.movespeed;
		if (game->pars->map
				[(int)(game->rays.posx)][(int)(game->rays.posy +
				game->rays.diry * game->rays.movespeed * 4)] == '0')
			game->rays.posy += game->rays.diry * game->rays.movespeed;
	}
	if (game->keys->move_back == 1)
	{
		if (game->pars->map
				[(int)(game->rays.posx - game->rays.dirx *
				game->rays.movespeed * 4)][(int)(game->rays.posy)] == '0')
			game->rays.posx -= game->rays.dirx * game->rays.movespeed;
		if (game->pars->map
				[(int)(game->rays.posx)][(int)(game->rays.posy -
				game->rays.diry * game->rays.movespeed * 4)] == '0')
			game->rays.posy -= game->rays.diry * game->rays.movespeed;
	}
}

void	ft_move_leftright(t_data *game)
{
	if (game->keys->move_left == 1)
	{
		if (game->pars->map
				[(int)(game->rays.posx - game->rays.diry *
				game->rays.movespeed * 4)][(int)(game->rays.posy)] == '0')
			game->rays.posx -= game->rays.diry * game->rays.movespeed;
		if (game->pars->map
				[(int)(game->rays.posx)][(int)(game->rays.posy +
				game->rays.dirx * game->rays.movespeed * 4)] == '0')
			game->rays.posy += game->rays.dirx * game->rays.movespeed;
	}
	if (game->keys->move_right == 1)
	{
		if (game->pars->map
				[(int)(game->rays.posx + game->rays.diry *
				game->rays.movespeed * 4)][(int)(game->rays.posy)] == '0')
			game->rays.posx += game->rays.diry * game->rays.movespeed;
		if (game->pars->map
				[(int)(game->rays.posx)][(int)(game->rays.posy -
				game->rays.dirx * game->rays.movespeed * 4)] == '0')
			game->rays.posy -= game->rays.dirx * game->rays.movespeed;
	}
}

void	ft_rotate_right(t_data *game)
{
	double	olddirx;
	double	oldplanex;

	if (game->keys->rotate_right == 1)
	{
		olddirx = game->rays.dirx;
		oldplanex = game->rays.planex;
		game->rays.dirx = game->rays.dirx * cos(-game->rays.rotspeed / 4)
							- game->rays.diry * sin(-game->rays.rotspeed / 4);
		game->rays.diry = olddirx * sin(-game->rays.rotspeed / 4)
							+ game->rays.diry * cos(-game->rays.rotspeed / 4);
		game->rays.planex = game->rays.planex * cos(-game->rays.rotspeed / 4)
							- game->rays.planey * sin(-game->rays.rotspeed / 4);
		game->rays.planey = oldplanex * sin(-game->rays.rotspeed / 4)
							+ game->rays.planey * cos(-game->rays.rotspeed / 4);
	}
}

void	ft_rotate_left(t_data *game)
{
	double	olddirx;
	double	oldplanex;

	if (game->keys->rotate_left == 1)
	{
		olddirx = game->rays.dirx;
		oldplanex = game->rays.planex;
		game->rays.dirx = game->rays.dirx * cos(game->rays.rotspeed / 4)
							- game->rays.diry * sin(game->rays.rotspeed / 4);
		game->rays.diry = olddirx * sin(game->rays.rotspeed / 4)
							+ game->rays.diry * cos(game->rays.rotspeed / 4);
		game->rays.planex = game->rays.planex * cos(game->rays.rotspeed / 4)
							- game->rays.planey * sin(game->rays.rotspeed / 4);
		game->rays.planey = oldplanex * sin(game->rays.rotspeed / 4)
							+ game->rays.planey * cos(game->rays.rotspeed / 4);
	}
}
