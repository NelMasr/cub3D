/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:43:27 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 12:02:06 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_texture1(char *hit, t_data *game, int i)
{
	if (hit[i] == 'N' && hit[i + 1] == 'O')
	{
		if (game->textures[0].check == 1)
			game->textures[0].check = 2;
		if (game->textures[0].check == 0)
			game->textures[0].check = 1;
	}
	else if (hit[i] == 'S' && hit[i + 1] == 'O')
	{
		if (game->textures[1].check == 1)
			game->textures[1].check = 2;
		if (game->textures[1].check == 0)
			game->textures[1].check = 1;
	}
	else if (hit[i] == 'E' && hit[i + 1] == 'A')
	{
		if (game->textures[2].check == 1)
			game->textures[2].check = 2;
		if (game->textures[2].check == 0)
			game->textures[2].check = 1;
	}
	return (1);
}

int		ft_check_texture2(char *hit, t_data *game, int i)
{
	if (hit[i] == 'W' && hit[i + 1] == 'E')
	{
		if (game->textures[3].check == 1)
			game->textures[3].check = 2;
		if (game->textures[3].check == 0)
			game->textures[3].check = 1;
	}
	if (hit[i] == 'S' && hit[i + 1] != 'O'
			&& hit[i + 1] != '0'
			&& hit[i + 1] != '1'
			&& hit[i + 1] != '2')
	{
		if (game->textures[4].check == 1)
			game->textures[4].check = 2;
		if (game->textures[4].check == 0)
			game->textures[4].check = 1;
	}
	return (1);
}

char	*ft_get_texture(char *hit, t_data *game, int tex)
{
	char	*texture;
	char	**pathname;

	texture = NULL;
	if (game->textures[tex].path)
		return (game->textures[tex].path);
	if (ft_trandominhit(hit, 0, game))
	{
		pathname = ft_split(hit, ' ');
		if (pathname[1])
			texture = ft_strdup(pathname[1]);
		else
			game->error->invalidpath = 1;
		free_that_string(pathname);
	}
	return (texture);
}

int		ft_parse_textures(char *hit, t_data *game)
{
	int i;

	i = -1;
	while (hit[++i])
	{
		if (hit[i] == 'N' && hit[i + 1] == 'O'
				&& ft_check_texture1(hit, game, i))
			game->textures[0].path = ft_get_texture(hit, game, 0);
		else if (hit[i] == 'S' && hit[i + 1] == 'O'
				&& ft_check_texture1(hit, game, i))
			game->textures[1].path = ft_get_texture(hit, game, 1);
		else if (hit[i] == 'E' && hit[i + 1] == 'A'
				&& ft_check_texture1(hit, game, i))
			game->textures[2].path = ft_get_texture(hit, game, 2);
		else if (hit[i] == 'W' && hit[i + 1] == 'E'
				&& ft_check_texture2(hit, game, i))
			game->textures[3].path = ft_get_texture(hit, game, 3);
		else if (hit[i] == 'S' && hit[i + 1] != 'O'
			&& hit[i + 1] != '0'
			&& hit[i + 1] != '1'
			&& hit[i + 1] != '2' && ft_check_texture2(hit, game, i))
			game->textures[4].path = ft_get_texture(hit, game, 4);
	}
	game->pars->i = 0;
	return (0);
}
