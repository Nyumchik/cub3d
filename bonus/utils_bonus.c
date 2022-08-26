/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:23:18 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/26 13:58:55 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floor_and_ceiling(t_info *info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < WINHEIGHT)
	{
		x = -1;
		while (++x < WINWIDTH)
		{
			info->buf[y][x] = info->floorcolor;
			info->buf[WINHEIGHT - y - 1][x] = info->ceilingcolor;
		}
	}
}

int	key_press(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key_w = 1;
	else if (key == K_A)
		info->key_a = 1;
	else if (key == K_S)
		info->key_s = 1;
	else if (key == K_D)
		info->key_d = 1;
	else if (key == K_AR_L)
		info->key_arrow_l = 1;
	else if (key == K_AR_R)
		info->key_arrow_r = 1;
	return (0);
}

int	key_release(int key, t_info *info)
{
	if (key == K_ESC)
		exit(0);
	else if (key == K_W)
		info->key_w = 0;
	else if (key == K_A)
		info->key_a = 0;
	else if (key == K_S)
		info->key_s = 0;
	else if (key == K_D)
		info->key_d = 0;
	else if (key == K_AR_L)
		info->key_arrow_l = 0;
	else if (key == K_AR_R)
		info->key_arrow_r = 0;
	return (0);
}

int	load_image(t_info *info, int *texture, char *path, t_img *img)
{
	int	y;
	int	x;

	y = -1;
	img->img = mlx_xpm_file_to_image(info->mlx,
			path, &img->img_width, &img->img_height);
	if (!img->img)
		return (1);
	img->data = (int *)mlx_get_data_addr(img->img,
			&img->bpp, &img->size_l, &img->endian);
	if (!img->data)
		return (1);
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
	return (0);
}

void	load_texture(t_info *info)
{
	t_img	img;
	int		error;

	error = 0;
	error |= load_image(info, info->texture[0], info->no_path, &img);
	error |= load_image(info, info->texture[1], info->so_path, &img);
	error |= load_image(info, info->texture[2], info->we_path, &img);
	error |= load_image(info, info->texture[3], info->ea_path, &img);
	if (error)
		exit_error_msg("failed to load textures\n");
}
