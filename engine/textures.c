/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 13:17:59 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 11:56:03 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_draw_textures(t_data *game, int x, int y)
{
	ft_init_texdata(game);
	game->t.texx = (int)(game->t.wallx * (double)game->textures
														[game->t.texor].width);
	if (game->rays.side == 0 && game->rays.raydirx > 0)
		game->t.texx = game->textures[game->t.texor].width - game->t.texx - 1;
	if (game->rays.side == 1 && game->rays.raydiry < 0)
		game->t.texx = game->textures[game->t.texor].width - game->t.texx - 1;
	game->t.step = 1.0 * game->textures[game->t.texor].height
													/ game->rays.lineheight;
	game->t.texpos = (game->rays.drawstart - game->pars->resy / 2
								+ game->rays.lineheight / 2) * game->t.step;
	while (y <= game->rays.drawend)
	{
		game->t.texy = (int)game->t.texpos & (game->textures
												[game->t.texor].height - 1);
		game->t.texpos += game->t.step;
		if (y < game->pars->resy && x < game->pars->resx)
			game->win->addr[y * game->win->line_length / 4 + x] =
			game->textures[game->t.texor].addr[game->t.texy *
			game->textures[game->t.texor].line_length / 4 + game->t.texx];
		y++;
	}
}
