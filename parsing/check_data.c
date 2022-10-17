/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 15:20:02 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 11:59:01 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_walls(t_data *game)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < game->pars->linenb)
	{
		if (game->pars->map[i][0] != '1')
			ft_error("Error ! Map is not closed on left wall.", game);
		if (game->pars->map[i][game->pars->linesize - 1] != '1')
			ft_error("Error ! Map is not closed on right wall.", game);
		i++;
	}
	while (j < game->pars->linesize)
	{
		if (game->pars->map[0][j] != '1')
			ft_error("Error ! Map is not closed on top wall.", game);
		if (game->pars->map[game->pars->linenb - 1][j] != '1')
			ft_error("Error ! Map is not closed on bottom wall.", game);
		j++;
	}
	ft_check_player(game);
	return (0);
}

void	ft_check_map(t_data *game)
{
	if (game->pars->resx == 0 || game->pars->resy == 0
				|| game->pars->floor_r == -1 || game->pars->floor_g == -1
				|| game->pars->floor_b == -1 || game->pars->ceiling_r == -1
				|| game->pars->ceiling_g == -1 || game->pars->ceiling_b == -1
				|| game->textures[0].path == NULL
				|| game->textures[1].path == NULL
				|| game->textures[2].path == NULL
				|| game->textures[3].path == NULL
				|| game->textures[3].path == NULL)
		ft_error("Error ! Missing data before retrieving map.", game);
}

int		ft_create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
