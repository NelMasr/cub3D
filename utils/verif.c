/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:57:54 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 12:15:46 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_rrandominhit(char *str, int pos, t_data *game)
{
	int i;

	i = pos + 1;
	while (str[i])
	{
		if (!(str[i] == ' ' || str[i] == '\t' || str[i] == '\v'
				|| str[i] == '\n' || str[i] == '\r'
				|| str[i] == '\f'))
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				game->error->invalidcharres = 1;
			i++;
		}
		else
			i++;
	}
	return (1);
}

int	ft_fcrandominhit(char *str, int pos, t_data *game)
{
	size_t i;

	i = pos + 1;
	while (i < ft_strlen(str))
	{
		if (!(str[i] == ' ' || str[i] == ',' || str[i] == '\t'
					|| str[i] == '\v' || str[i] == '\n'
					|| str[i] == '\n' || str[i] == '\r'
					|| str[i] == '\f'))
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				game->error->invalidcharcolor = 1;
			i++;
		}
		else
			i++;
	}
	return (1);
}

int	ft_trandominhit(char *str, int pos, t_data *game)
{
	int i;

	i = pos + 2;
	while (str[i] != '.' && str[i])
		i++;
	while (str[i])
	{
		if (str[i] == '*' || str[i] == '\\' || str[i] == '['
				|| str[i] == ']' || str[i] == '"'
				|| str[i] == ':' || str[i] == ';' || str[i] == '|'
				|| str[i] == ',' || str[i] == ' ' || str[i] == '\0')
			game->error->invalidchartex = 1;
		i++;
	}
	return (1);
}

int	check_commas(char *str, t_data *game, int i)
{
	i = game->pars->i;
	if (game->pars->floor_r != -1 && game->pars->floor_g != -1
			&& game->pars->floor_b != -1)
	{
		while (str[i])
		{
			if (str[i] == ',' || (str[i] >= '0' && str[i] <= '9'))
				game->error->fourthf = 1;
			i++;
		}
	}
	if (game->pars->ceiling_r != -1 && game->pars->ceiling_g != -1
			&& game->pars->ceiling_b != -1)
	{
		while (str[i])
		{
			if (str[i] == ',' || (str[i] >= '0' && str[i] <= '9'))
				game->error->fourthc = 1;
			i++;
		}
	}
	return (0);
}

int	ft_check_player(t_data *game)
{
	if (game->player_x == 0 || game->player_y == 0
			|| game->player_orientation == 0)
		ft_error("Error ! Missing player / map data.", game);
	game->error->allgood = 1;
	return (0);
}
