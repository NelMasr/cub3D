/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution_and_colors.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 19:06:18 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/09 18:58:52 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_atoi_res(char *nptr, t_data *game, int i)
{
	int	result;

	i = game->pars->i;
	i++;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t'
			|| nptr[i] == '\v' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		game->error->ressign = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	game->pars->i = i;
	if (result > 2147483647 || result <= 0)
		game->error->invalidres = 1;
	return (result);
}

int	ft_atoi_colors(char *nptr, t_data *game, int i)
{
	int	result;

	i = game->pars->i;
	i++;
	result = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t'
			|| nptr[i] == '\v' || nptr[i] == '\n'
			|| nptr[i] == '\r' || nptr[i] == '\f'
			|| nptr[i] == ',')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
		game->error->colorsign = 1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	game->pars->i = i;
	if (result > 255 || result < 0)
		game->error->colorrange = 1;
	return (result);
}

int	ft_color_check(char *hit, t_data *game, int i)
{
	if (hit[i] == 'F')
	{
		if (game->pars->fcheck == 1)
			game->pars->fcheck = 2;
		else if (game->pars->fcheck == 0)
			game->pars->fcheck = 1;
	}
	if (hit[i] == 'C')
	{
		if (game->pars->ccheck == 1)
			game->pars->ccheck = 2;
		else if (game->pars->ccheck == 0)
			game->pars->ccheck = 1;
	}
	return (0);
}

int	ft_parse_colors(char *hit, t_data *game)
{
	int i;

	i = 0;
	while (hit[i])
	{
		if (hit[i] == 'F' && ft_fcrandominhit(hit, i, game))
		{
			ft_color_check(hit, game, i);
			game->pars->floor_r = ft_atoi_colors(hit, game, i);
			game->pars->floor_g = ft_atoi_colors(hit, game, i);
			game->pars->floor_b = ft_atoi_colors(hit, game, i);
			check_commas(hit, game, i);
		}
		else if (hit[i] == 'C' && ft_fcrandominhit(hit, i, game))
		{
			ft_color_check(hit, game, i);
			game->pars->ceiling_r = ft_atoi_colors(hit, game, i);
			game->pars->ceiling_g = ft_atoi_colors(hit, game, i);
			game->pars->ceiling_b = ft_atoi_colors(hit, game, i);
			check_commas(hit, game, i);
		}
		i++;
	}
	game->pars->i = 0;
	return (0);
}

int	ft_parse_resolution(char *hit, t_data *game)
{
	int i;

	i = 0;
	while (hit[i])
	{
		if (hit[i] == 'R')
		{
			if (game->pars->resx != 0 && game->pars->resy != 0)
				game->error->resrep = 1;
			if (ft_rrandominhit(hit, i, game) == 1)
			{
				game->pars->resx = ft_atoi_res(hit, game, i);
				if (game->pars->resx < 640)
					game->pars->resx = 640;
				game->pars->resy = ft_atoi_res(hit, game, i);
				if (game->pars->resy < 480)
					game->pars->resy = 480;
			}
		}
		i++;
	}
	game->pars->i = 0;
	return (0);
}
