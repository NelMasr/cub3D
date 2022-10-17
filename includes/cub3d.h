/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-masr <nel-masr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:07:21 by nel-masr          #+#    #+#             */
/*   Updated: 2021/02/15 12:25:56 by nel-masr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define BUFFER_SIZE 1024
# define INT_MAX 2147483648

typedef	struct	s_minimap
{
	double	tile_y;
	double	tile_x;
	double	x_max;
	double	y_max;
	double	line;
	double	y;
	double	x;
}				t_minimap;

typedef	struct	s_keys
{
	int		move_forward;
	int		move_back;
	int		move_left;
	int		move_right;
	int		rotate_right;
	int		rotate_left;
	int		key_close;
}				t_keys;

typedef	struct	s_error
{
	int		badcharhit;
	int		resrep;
	int		ressign;
	int		invalidres;
	int		invalidcharres;
	int		invalidcharcolor;
	int		colorsign;
	int		invalidcolor;
	int		colorrange;
	int		fourthf;
	int		fourthc;
	int		invalidchartex;
	int		invalidpath;
	int		emptyline;
	int		invalidcharmap;
	int		multiplayer;
	int		allgood;
	int		map;
}				t_error;

typedef	struct	s_pars
{
	int		resx;
	int		resy;
	int		floor_r;
	int		floor_g;
	int		floor_b;
	int		f;
	int		ceiling_r;
	int		ceiling_g;
	int		ceiling_b;
	int		c;
	int		fcheck;
	int		ccheck;
	int		i;
	int		linesize;
	int		linenb;
	char	**map;
	int		weareinmap;
	int		firstexit;
}				t_pars;

typedef	struct	s_textures
{
	void	*img;
	int		*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	char	*path;
	int		check;
}				t_textures;

typedef	struct	s_texdata
{
	int		texor;
	double	wallx;
	double	texpos;
	int		texx;
	int		texy;
	double	step;
}				t_texdata;

typedef	struct	s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	int			*addr;
	void		*img2;
	int			*addr2;
	int			bpp;
	int			line_length;
	int			endian;
}				t_mlx;

typedef	struct	s_rays
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			x;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
}				t_rays;

typedef	struct	s_spos
{
	double		x;
	double		y;
}				t_spos;

typedef	struct	s_spd
{
	double		*zbuffer;
	int			nbsp;
	int			*order;
	double		*distance;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			drawstartx;
	int			drawendx;
	int			spritewidth;
}				t_spd;

typedef	struct	s_data
{
	int			player_x;
	int			player_y;
	char		player_orientation;
	int			screenx;
	int			screeny;
	int			save;
	double		wall_hit_x;
	double		wall_hit_y;
	t_keys		*keys;
	t_pars		*pars;
	t_textures	textures[5];
	t_texdata	t;
	t_mlx		*win;
	t_rays		rays;
	t_spd		s;
	t_spos		*spos;
	t_error		*error;
}				t_data;

int				main(int argc, char **argv);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_parsing(char *file, t_data *game);
int				ft_parse_map(char *file, t_data *game);
int				ft_mlx(t_data *game);

int				ft_parse_resolution(char *hit, t_data *game);
int				ft_parse_colors(char *hit, t_data *game);
int				ft_atoi_res(char *nptr, t_data *game, int i);
int				ft_atoi_colors(char *nptr, t_data *game, int i);
int				ft_color_check(char *hit, t_data *game, int i);

int				ft_parse_textures(char *hit, t_data *game);
char			*ft_get_texture(char *hit, t_data *game, int tex);
int				ft_check_texture1(char *hit, t_data *game, int i);
int				ft_check_texture2(char *hit, t_data *game, int i);

int				ft_get_map_data(char *hit, t_data *game);
int				ft_ismap(char *hit, t_data *game, int i);
int				ft_copy_map(char *hit, t_data *game);
int				ft_get_player_position(char *hit, int i, int j, t_data *game);
int				ft_fill_walls(int j, int i, t_data *game);

int				ft_check_walls(t_data *game);
int				ft_create_trgb(int t, int r, int g, int b);
void			ft_check_map(t_data *game);

int				ft_set_textures(t_data *game);
int				ft_set_textures_addr(t_data *game);
void			sprite_init(t_data *game);
void			sprite_init2(t_data *game, int k);

int				key_pressed(int keycode, t_data *game);
int				key_released(int keycode, t_data *game);
int				ft_exit_game(t_data *game);

void			ft_render(t_data *game);
void			ft_move_forback(t_data *game);
void			ft_move_leftright(t_data *game);
void			ft_rotate_right(t_data *game);
void			ft_rotate_left(t_data *game);

void			ft_draw_textures(t_data *game, int x, int y);

void			ft_sprites(t_data *game);
void			ft_draw_sprites(t_data *game, int y, int texx, int stripe);
void			ft_get_sprite_data(t_data *game, int i);
void			ft_sort_sprites(t_data *game);
void			ft_init_orddist(t_data *game);

void			ft_get_sidedist(t_data *game);
void			ft_dda(t_data *game);
void			ft_drawdata(t_data *game);

void			ft_refresh(t_data *game);

int				ft_free_game(t_data *game);
int				ft_free_window(t_mlx *window, int save, t_error *error);
int				ft_free_tex_image(t_mlx *window, t_textures tex);
int				ft_free_sprites(t_spd s, t_spos *spos);
int				ft_free_map (t_pars *pars);

int				ft_rrandominhit(char *str, int pos, t_data *game);
int				ft_fcrandominhit(char *str, int pos, t_data *game);
int				ft_trandominhit(char *str, int pos, t_data *game);
int				check_commas(char *str, t_data *game, int i);
int				ft_check_player(t_data *game);

char			**ft_split(char const *s, char c);
void			split_that_string(char const *s, char c, char **tab, int count);
int				count_size(char const *s, char c, int pos);
int				count_words(char const *s, char c);
char			**free_that_string(char **tab);

char			*ft_strdup(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

t_data			*game_init(void);
t_pars			*pars_init(void);
t_keys			*keys_init(void);
t_textures		tex_init(void);
t_mlx			*window_init(void);

int				get_next_line(int fd, char **line);
size_t			ft_strlen(char const *str);
int				eotl(char *read_line);
char			*tw_strjoin(char *s1, char *s2);

void			rays_init(t_data *game);
void			rays_init2(t_data *game);
void			ft_init_dir(t_data *game);
void			ft_init_delta(t_data *game);
void			ft_init_texdata(t_data *game);

void			ft_error(char *error_message, t_data *game);
t_error			*error_init(void);
void			ft_check_parsing(t_data *game);
void			ft_check_parsing2(t_data *game);
void			ft_check_multiplayer(t_data *game);

void			ft_save(t_data *game);
void			ft_create_bmp(t_data *game, int fd);

void			ft_init_buffer(t_data *game);
void			ft_continue_parsing(char *file, t_data *game);
int				ft_check_fd(char *file, t_data *game);
int				ft_check_hit(char *hit, t_data *game);

#endif
