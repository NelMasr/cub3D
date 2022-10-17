/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:24:54 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/15 12:35:46 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/cub3d.h"

int		ft_raycasting(t_data *game)
{
	game->rays.x = 0;
	while (game->rays.x < game->pars->resx)
	{
		rays_init2(game);
		ft_get_sidedist(game);
		ft_render(game);
		game->s.zbuffer[game->rays.x] = game->rays.perpwalldist;
		game->rays.x++;
	}
	ft_sprites(game);
	if (game->save == 1)
		ft_save(game);
	mlx_put_image_to_window(game->win->mlx_ptr, game->win->mlx_win,
													game->win->img, 0, 0);
	ft_move_forback(game);
	ft_move_leftright(game);
	ft_rotate_right(game);
	ft_rotate_left(game);
	ft_refresh(game);
	return (0);
}

int		ft_mlx(t_data *game)
{
	if (!(game->win->mlx_ptr = mlx_init()))
		ft_error("Error ! Mlx couldn't be initiated.", game);
	mlx_get_screen_size(game->win->mlx_ptr, &game->screenx, &game->screeny);
	if (game->screenx < game->pars->resx)
		game->pars->resx = game->screenx;
	if (game->screeny < game->pars->resy)
		game->pars->resy = game->screeny;
	rays_init(game);
	ft_set_textures(game);
	game->win->img = mlx_new_image(game->win->mlx_ptr, game->pars->resx,
							game->pars->resy);
	game->win->addr = (int *)mlx_get_data_addr(game->win->img, &game->win->bpp,
							&game->win->line_length, &game->win->endian);
	if (game->save == 1)
		ft_raycasting(game);
	game->win->mlx_win = mlx_new_window(game->win->mlx_ptr, game->pars->resx,
							game->pars->resy, "cub3D");
	ft_init_buffer(game);
	mlx_hook(game->win->mlx_win, 33, 1L << 17, ft_exit_game, game);
	mlx_hook(game->win->mlx_win, 2, 1L << 0, key_pressed, game);
	mlx_hook(game->win->mlx_win, 3, 1L << 1, key_released, game);
	mlx_loop_hook(game->win->mlx_ptr, ft_raycasting, game);
	mlx_loop(game->win->mlx_ptr);
	return (0);
}

int		ft_parse_map(char *file, t_data *game)
{
	int		fd;
	int		ret;
	char	*hit;

	ret = 1;
	if (!(game->pars->map = malloc(sizeof(char *) * (game->pars->linenb))))
		return (0);
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_error("Error ! Map file doesn't exist.", game);
	while (ret != 0)
	{
		ret = get_next_line(fd, &hit);
		if (ft_ismap(hit, game, 0) == 1 && game->pars->weareinmap == 1)
			ft_copy_map(hit, game);
		free(hit);
	}
	close(fd);
	ft_check_multiplayer(game);
	ft_check_walls(game);
	sprite_init(game);
	ft_mlx(game);
	return (0);
}

int		ft_parsing(char *file, t_data *game)
{
	int		fd;
	int		ret;
	char	*hit;

	hit = NULL;
	ret = 1;
	fd = ft_check_fd(file, game);
	while ((ret = get_next_line(fd, &hit)) != 0)
	{
		ft_check_hit(hit, game);
		ft_parse_resolution(hit, game);
		ft_parse_colors(hit, game);
		ft_parse_textures(hit, game);
		ft_get_map_data(hit, game);
		free(hit);
	}
	free(hit);
	close(fd);
	ft_check_parsing(game);
	ft_check_map(game);
	ft_continue_parsing(file, game);
	return (0);
}

int		main(int argc, char **argv)
{
	t_data	*game;
	int		i;

	i = 0;
	if (argc == 2 || (argc == 3 && !ft_strncmp(argv[2], "--save", 6)))
	{
		while (argv[1][i] != '.')
			i++;
		if (argv[1][i + 1] == 'c' && argv[1][i + 2] == 'u'
				&& argv[1][i + 3] == 'b' && argv[1][i + 4] == '\0')
		{
			game = game_init();
			if (argc == 3)
				game->save = 1;
			ft_parsing(argv[1], game);
		}
		else
			printf("Error ! Map path invalid.\n");
	}
	else
		printf("Error ! Invalid arugments.\n");
	return (0);
}
