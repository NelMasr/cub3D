/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 10:21:39 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/15 12:22:04 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_fill_walls(int j, int i, t_data *game)
{
	while (j < game->pars->linesize)
	{
		game->pars->map[i][j] = '1';
		j++;
	}
	game->pars->map[i][j] = '\0';
	return (0);
}

int		ft_get_player_position(char *hit, int i, int j, t_data *game)
{
	if (game->player_x != 0 || game->player_y != 0
			|| game->player_orientation != 0)
	{
		game->error->multiplayer = 1;
		return (0);
	}
	game->player_x = i;
	game->player_y = j;
	game->pars->map[i][j] = '0';
	game->player_orientation = hit[j];
	return (0);
}

int		ft_copy_map(char *hit, t_data *game)
{
	static	int i = 0;
	int			j;

	j = 0;
	if (!(game->pars->map[i] = malloc(sizeof(char) *
			(game->pars->linesize + 1))))
		return (0);
	while (hit[j])
	{
		if (hit[j] == ' ')
			game->pars->map[i][j] = '1';
		else if (hit[j] == 'N' || hit[j] == 'W' || hit[j] == 'S'
				|| hit[j] == 'E')
			ft_get_player_position(hit, i, j, game);
		else
			game->pars->map[i][j] = hit[j];
		j++;
	}
	if (j <= game->pars->linesize)
		ft_fill_walls(j, i, game);
	i++;
	return (0);
}

int		ft_ismap(char *hit, t_data *game, int i)
{
	if (hit[i] == '\0' && game->pars->linenb > 0
			&& game->pars->firstexit != 1)
		game->error->emptyline = 1;
	else if (hit[i] == '\0')
		return (0);
	while (hit[i])
	{
		if (hit[i] != '1' && hit[i] != '2' && hit[i] != '0' && hit[i] != ' '
			&& hit[i] != 'N' && hit[i] != 'S' && hit[i] != 'W'
			&& hit[i] != 'E')
		{
			if (game->pars->resx != 0 && game->pars->resy != 0
				&& game->pars->fcheck == 1 && game->pars->ccheck == 1
				&& game->textures[0].check == 1 && game->textures[1].check == 1
				&& game->textures[2].check == 1 && game->textures[3].check == 1
				&& game->textures[4].check == 1 && game->pars->weareinmap == 1)
				game->error->invalidcharmap = 1;
			else
				return (0);
		}
		i++;
	}
	game->pars->weareinmap = 1;
	return (1);
}

int		ft_get_map_data(char *hit, t_data *game)
{
	static	int	linesize = 0;
	int			len;

	len = ft_strlen(hit);
	if (ft_ismap(hit, game, 0) == 1)
	{
		game->pars->weareinmap = 1;
		if (len > linesize)
			linesize = len;
		game->pars->linenb++;
		game->pars->linesize = linesize;
	}
	return (0);
}
