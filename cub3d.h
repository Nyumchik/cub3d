/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:49:30 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/25 18:55:00 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// #include "key_linux.h" // linux
// #include "mlx_linux/mlx.h" // linux
#include "mlx/mlx.h" // mac
#include "key_macos.h" // mac

#include "libft/libft.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#define X_EVENT_KEY_PRESS	2
#define X_EVENT_KEY_RELEASE	3
#define X_EVENT_KEY_EXIT	17
#define texWidth 64
#define texHeight 64
#define mapWidth 24
#define mapHeight 24
#define width 640
#define height 480
#define WHITE 0xFFFFFF
#define GRAY 0x555555
#define BLUE 0x0000ff
#define NO 0
#define SO 1
#define WE 2
#define EA 3

typedef struct	s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_calc
{
	double	cameraX;
	double	rayDirX;
	double	rayDirY;
	int		mapX;
	int		mapY;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;
	double	perpWallDist;
	int		stepX;
	int		stepY;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
	int		texNum;
	double	wallX;
	int		texX;
	int		texY;
	double	step;
	double	texPos;
	int		color;
}				t_calc;

typedef struct	s_info
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	void	*mlx;
	void	*win;
	t_img	img;
	int		buf[height][width];
	int		**texture;
	double	moveSpeed;
	double	rotSpeed;
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_arrow_l;
	int		key_arrow_r;
	int		key_esc;
	int		floorColor;
	int		ceilingColor;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;

	char	**map;
	int		mapW;
	int		mapH;
	t_calc	calc;
}				t_info;

void	parser(char *file, t_info *info, int count);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		check_map_file(int ac, char *str);
int		skip_spaces(char *str, int i);
void	exit_error_msg(char *err_msg);
int		get_rgb(char *line);
void	valid_rgb_format(char *line);
void	get_texture(t_info *info, int side, char *line);
void	ft_read_map(const int fd, t_info *info, char *line);
void	check_map_content(char	**temp, char *charset);
int		check_valid_path(char **map, int i, int j);
void	print_error_pos(int row, int column, char c);
void	get_player_info(t_info *info, char **line, int y, int x);
size_t	ft_strspn(const char *str, const char *charset);
void	set_player_dir_west(t_info *info);
void	set_player_dir_south(t_info *info);
void	load_texture(t_info *info);

void	calc(t_info *info);
void	floor_and_ceiling(t_info *info);
void	init_vars(t_info *info, int x);
void	choose_direction(t_info *info);
void	draw_walls(t_info *info);
void	draw(t_info *info);
int		key_update(t_info *info);
void	movements(t_info *info);
void	rotation(t_info *info);
int		key_press(int key, t_info *info);
int		key_release(int key, t_info *info);
int		handle_event(void);


#endif