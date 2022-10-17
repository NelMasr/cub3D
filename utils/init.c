/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:19:35 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 12:14:03 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_keys		*keys_init(void)
{
	t_keys	*keys;

	if (!(keys = (t_keys *)malloc(sizeof(t_keys))))
		return (NULL);
	keys->move_forward = 0;
	keys->move_back = 0;
	keys->move_left = 0;
	keys->move_right = 0;
	keys->rotate_left = 0;
	keys->rotate_right = 0;
	return (keys);
}

t_pars		*pars_init(void)
{
	t_pars	*pars;

	if (!(pars = (t_pars *)malloc(sizeof(t_pars))))
		return (NULL);
	pars->resx = 0;
	pars->resy = 0;
	pars->floor_r = -1;
	pars->floor_g = -1;
	pars->floor_b = -1;
	pars->ceiling_r = -1;
	pars->ceiling_g = -1;
	pars->ceiling_b = -1;
	pars->fcheck = 0;
	pars->ccheck = 0;
	pars->i = 0;
	pars->linenb = 0;
	pars->linesize = 0;
	pars->map = NULL;
	pars->weareinmap = 0;
	pars->firstexit = 0;
	return (pars);
}

t_textures	tex_init(void)
{
	t_textures	tex;

	tex.img = NULL;
	tex.addr = NULL;
	tex.bpp = 0;
	tex.line_length = 0;
	tex.endian = 0;
	tex.width = 0;
	tex.height = 0;
	tex.path = NULL;
	tex.check = 0;
	return (tex);
}

t_mlx		*window_init(void)
{
	t_mlx	*window;

	if (!(window = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	window->mlx_ptr = NULL;
	window->mlx_win = NULL;
	window->img = NULL;
	window->addr = NULL;
	window->img2 = NULL;
	window->addr2 = NULL;
	window->bpp = 0;
	window->line_length = 0;
	window->endian = 0;
	return (window);
}

t_data		*game_init(void)
{
	t_data *game;

	if (!(game = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	game->player_x = 0;
	game->player_y = 0;
	game->player_orientation = 0;
	game->save = 0;
	game->textures[0] = tex_init();
	game->textures[1] = tex_init();
	game->textures[2] = tex_init();
	game->textures[3] = tex_init();
	game->textures[4] = tex_init();
	game->keys = keys_init();
	game->pars = pars_init();
	game->win = window_init();
	game->error = error_init();
	game->s.order = NULL;
	game->s.distance = NULL;
	game->s.zbuffer = NULL;
	game->spos = NULL;
	return (game);
}
