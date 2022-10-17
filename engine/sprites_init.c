/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:16:39 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 11:54:28 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_set_textures_addr(t_data *game)
{
	game->textures[0].addr = (int *)mlx_get_data_addr(game->textures[0].img,
		&(game->textures[0].bpp), &(game->textures[0].line_length),
		&(game->textures[0].endian));
	game->textures[1].addr = (int *)mlx_get_data_addr(game->textures[1].img,
		&(game->textures[1].bpp), &(game->textures[1].line_length),
		&(game->textures[1].endian));
	game->textures[3].addr = (int *)mlx_get_data_addr(game->textures[3].img,
		&(game->textures[3].bpp), &(game->textures[3].line_length),
		&(game->textures[3].endian));
	game->textures[2].addr = (int *)mlx_get_data_addr(game->textures[2].img,
		&(game->textures[2].bpp), &(game->textures[2].line_length),
		&(game->textures[2].endian));
	game->textures[4].addr = (int *)mlx_get_data_addr(game->textures[4].img,
		&(game->textures[4].bpp), &(game->textures[4].line_length),
		&(game->textures[4].endian));
	return (0);
}

int		ft_set_textures(t_data *game)
{
	if (!(game->textures[0].img = mlx_xpm_file_to_image(game->win->mlx_ptr,
			game->textures[0].path, &(game->textures[0].width),
			&(game->textures[0].height))))
		ft_error("Error ! NO texture could not be initiated.", game);
	if (!(game->textures[1].img = mlx_xpm_file_to_image(game->win->mlx_ptr,
			game->textures[1].path, &(game->textures[1].width),
			&(game->textures[1].height))))
		ft_error("Error ! SO texture could not be initiated.", game);
	if (!(game->textures[3].img = mlx_xpm_file_to_image(game->win->mlx_ptr,
			game->textures[3].path, &(game->textures[3].width),
			&(game->textures[3].height))))
		ft_error("Error ! WE texture could not be initiated.", game);
	if (!(game->textures[2].img = mlx_xpm_file_to_image(game->win->mlx_ptr,
			game->textures[2].path, &(game->textures[2].width),
			&(game->textures[2].height))))
		ft_error("Error ! EA texture could not be initiated.", game);
	if (!(game->textures[4].img = mlx_xpm_file_to_image(game->win->mlx_ptr,
			game->textures[4].path, &(game->textures[4].width),
			&(game->textures[4].height))))
		ft_error("Error ! SP texture could not be initiated.", game);
	ft_set_textures_addr(game);
	return (0);
}

void	sprite_init(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	game->s.nbsp = 0;
	while (i < game->pars->linenb)
	{
		j = 0;
		while (j < game->pars->linesize)
		{
			if (game->pars->map[i][j] == '2')
				game->s.nbsp++;
			j++;
		}
		i++;
	}
	if (!(game->spos = (t_spos *)malloc(sizeof(t_spos) * game->s.nbsp)))
		ft_error("Error ! Could not initiate sprite positions.", game);
	if (!(game->s.order = (int *)malloc(sizeof(int) * game->s.nbsp)))
		ft_error("Error ! Could not initiate sprite order.", game);
	if (!(game->s.distance = (double *)malloc(sizeof(double) * game->s.nbsp)))
		ft_error("Error ! Could not initiate sprite distance.", game);
	sprite_init2(game, 0);
}

void	sprite_init2(t_data *game, int k)
{
	int i;
	int j;

	i = 0;
	while (i < game->pars->linenb)
	{
		j = 0;
		while (j < game->pars->linesize)
		{
			if (game->pars->map[i][j] == '2')
			{
				game->spos[k].x = (double)i + 0.5;
				game->spos[k].y = (double)j + 0.5;
				k++;
			}
			j++;
		}
		i++;
	}
}
