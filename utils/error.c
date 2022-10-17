/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:46:38 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/15 12:24:47 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(char *error_message, t_data *game)
{
	printf("%s\n", error_message);
	ft_free_game(game);
	exit(0);
}

t_error	*error_init(void)
{
	t_error	*error;

	if (!(error = (t_error *)malloc(sizeof(t_error))))
		return (NULL);
	error->badcharhit = 0;
	error->resrep = 0;
	error->ressign = 0;
	error->invalidres = 0;
	error->invalidcharres = 0;
	error->invalidcharcolor = 0;
	error->colorsign = 0;
	error->invalidcolor = 0;
	error->colorrange = 0;
	error->fourthf = 0;
	error->fourthc = 0;
	error->invalidchartex = 0;
	error->invalidpath = 0;
	error->emptyline = 0;
	error->invalidcharmap = 0;
	error->multiplayer = 0;
	error->allgood = 0;
	error->map = 0;
	return (error);
}

void	ft_check_parsing(t_data *game)
{
	if (game->error->badcharhit == 1)
		ft_error("Error ! Forbidden char in .cub file.", game);
	if (game->error->resrep == 1)
		ft_error("Error ! Resolution's been defined more than once.", game);
	if (game->error->invalidcharres == 1)
		ft_error("Error ! Invalid character in resolution.", game);
	if (game->error->ressign == 1)
		ft_error("Error ! Resolution values should not contain signs.", game);
	if (game->error->invalidres == 1)
		ft_error("Error ! Resolution is invalid.", game);
	if (game->error->invalidcharcolor == 1)
		ft_error("Error ! Invalid character in floor/ceiling.", game);
	if (game->pars->fcheck == 2)
		ft_error("Error ! Floor color is defined more than once.", game);
	if (game->pars->ccheck == 2)
		ft_error("Error ! Ceiling color is defined more than once.", game);
	if (game->error->colorsign == 1)
		ft_error("Error ! Color values should not contain signs.", game);
	if (game->error->colorrange == 1)
		ft_error("Error ! Color RGB range should be between 0 and 255.", game);
	if (game->error->fourthc == 1)
		ft_error("Error ! You tried to set a 4th color for the ceiling.", game);
	ft_check_parsing2(game);
}

void	ft_check_parsing2(t_data *game)
{
	if (game->error->fourthf == 1)
		ft_error("Error ! You tried to set a 4th color  for the floor.", game);
	if (game->textures[0].check == 2)
		ft_error("Error ! NO has been defined more than once.", game);
	if (game->textures[1].check == 2)
		ft_error("Error ! SO has been defined more than once.", game);
	if (game->textures[2].check == 2)
		ft_error("Error ! EA has been defined more than once.", game);
	if (game->textures[3].check == 2)
		ft_error("Error ! WE has been defined more than once.", game);
	if (game->textures[4].check == 2)
		ft_error("Error ! SP has been defined more than once.", game);
	if (game->error->invalidchartex == 1)
		ft_error("Error ! Forbidden character in texture pathname.", game);
	if (game->error->invalidpath == 1)
		ft_error("Error ! Please verify pathname.", game);
	if (game->error->emptyline == 1)
		ft_error("Error ! Empty line in map.", game);
	if (game->error->invalidcharmap == 1)
		ft_error("Error ! Forbidden characters in map.", game);
}

void	ft_check_multiplayer(t_data *game)
{
	if (game->error->multiplayer == 1)
		ft_error("Error ! More than one player is defined.", game);
}
