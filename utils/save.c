/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 18:28:17 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/11 12:30:30 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_create_bmp(t_data *game, int fd)
{
	int	tmp;

	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * game->pars->resx * game->pars->resy;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &game->pars->resx, 4);
	write(fd, &game->pars->resy, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &game->win->bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void	ft_save(t_data *game)
{
	int fd;
	int x;
	int y;

	if ((fd = open("./screen.bmp", O_CREAT | O_RDWR)) == -1)
		ft_error("Error ! Saved image could not be created.", game);
	ft_create_bmp(game, fd);
	y = game->pars->resy;
	while (y >= 0)
	{
		x = 0;
		while (x < game->pars->resx)
		{
			write(fd, &game->win->addr[y * game->win->line_length / 4 + x], 4);
			x++;
		}
		y--;
	}
	system("chmod 777 screen.bmp");
	ft_free_game(game);
	exit(0);
}
