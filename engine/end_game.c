/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 16:39:15 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 12:22:36 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_free_map(t_pars *pars)
{
	int i;

	i = 0;
	if (pars->map)
	{
		while (i < pars->linenb)
		{
			free(pars->map[i]);
			i++;
		}
		free(pars->map);
	}
	return (0);
}

int	ft_free_tex_image(t_mlx *window, t_textures tex)
{
	if (tex.path)
		free(tex.path);
	if (tex.img)
		mlx_destroy_image(window->mlx_ptr, tex.img);
	return (0);
}

int	ft_free_window(t_mlx *window, int save, t_error *error)
{
	if (window->img)
		mlx_destroy_image(window->mlx_ptr, window->img);
	if (window->img2)
		mlx_destroy_image(window->mlx_ptr, window->img2);
	if (window->mlx_win)
		mlx_destroy_window(window->mlx_ptr, window->mlx_win);
	if (window->mlx_ptr || (save == 1 && error->allgood == 1))
	{
		mlx_destroy_display(window->mlx_ptr);
		free(window->mlx_ptr);
	}
	free(window);
	return (0);
}

int	ft_free_sprites(t_spd s, t_spos *spos)
{
	if (s.zbuffer)
		free(s.zbuffer);
	if (s.order)
		free(s.order);
	if (s.distance)
		free(s.distance);
	free(spos);
	return (0);
}

int	ft_free_game(t_data *game)
{
	free(game->keys);
	ft_free_map(game->pars);
	free(game->pars);
	ft_free_tex_image(game->win, game->textures[0]);
	ft_free_tex_image(game->win, game->textures[1]);
	ft_free_tex_image(game->win, game->textures[2]);
	ft_free_tex_image(game->win, game->textures[3]);
	ft_free_tex_image(game->win, game->textures[4]);
	ft_free_sprites(game->s, game->spos);
	ft_free_window(game->win, game->save, game->error);
	free(game->error);
	free(game);
	return (0);
}
