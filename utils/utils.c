/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 18:26:44 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/15 12:54:06 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_buffer(t_data *game)
{
	game->win->img2 = mlx_new_image(game->win->mlx_ptr, game->pars->resx,
										game->pars->resy);
	game->win->addr2 = (int *)mlx_get_data_addr(game->win->img2,
				&game->win->bpp, &game->win->line_length, &game->win->endian);
}

void	ft_continue_parsing(char *file, t_data *game)
{
	game->pars->weareinmap = 0;
	game->pars->firstexit = 1;
	game->pars->f = ft_create_trgb(255, game->pars->floor_r,
								game->pars->floor_g, game->pars->floor_b);
	game->pars->c = ft_create_trgb(255, game->pars->ceiling_r,
								game->pars->ceiling_g, game->pars->ceiling_b);
	ft_parse_map(file, game);
}

int		ft_check_fd(char *file, t_data *game)
{
	int fd;

	if ((fd = open(file, O_DIRECTORY)) != -1)
		ft_error("Error ! Map directs to a folder, should be a file.", game);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("Error ! Map file doesn't exist.", game);
	return (fd);
}

int		ft_check_hit(char *hit, t_data *game)
{
	int i;

	i = 0;
	if (hit[i] == ' ')
	{
		while (hit[i] == ' ')
			i++;
		if (!(hit[i] == '1' || hit[i] == '2' || hit[i] == '0'))
			game->error->badcharhit = 1;
		else
			game->error->map = 1;
		return (0);
	}
	i = 0;
	if (!(hit[i] == 'R' || hit[i] == 'F' || hit[i] == 'C' || hit[i] == '\0' ||
			hit[i] == 'S' || (hit[i] == 'W' && hit[i + 1] == 'E') ||
			(hit[i] == 'S' && hit[i + 1] == 'O') ||
			(hit[i] == 'E' && hit[i + 1] == 'A') ||
			(hit[i] == 'N' && hit[i + 1] == 'O') ||
			(hit[i] == '1') || hit[i] == '0' || hit[i] == '2'))
		game->error->badcharhit = 1;
	return (0);
}
