/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:32 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/26 20:24:45 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_door(char **map, int i, int j)
{
	if (map[i][j - 1] == '1' && map[i][j + 1] == '1')
		return (0);
	else if (map[i - 1][j] == '1' && map[i + 1][j] == '1')
		return (0);
	return (-1);
}

t_img	load_img(char *path, void *mlx)
{
	t_img	tmp;

	tmp.img_width = 64;
	tmp.img_height = 64;
	tmp.img = mlx_xpm_file_to_image(mlx, path, &tmp.img_width, &tmp.img_height);
	if (!tmp.img)
		exit(printf("mlx Error : mlx_xpm_file_to_image !\n"));
	tmp.data = (int *)mlx_get_data_addr(tmp.img,
			&tmp.bpp, &tmp.size_l, &tmp.endian);
	if (!tmp.data)
		exit(printf("mlx Error : mlx_get_data_addr!\n"));
	return (tmp);
}

int	mouse(int x, int y, t_info *info)
{

	(void)y;

	double	diff;
	double		ptr;

	(void)y;
	diff = x - (WINWIDTH / 2);
	ptr = mlx_mouse_get_pos(info->win, &x, &y);
	if (diff < 0)
	{
		info->key_arrow_l = 1;
		info->key_arrow_r = 0;
		if (ptr > mlx_mouse_get_pos(info->win, &x, &y) || diff == 0)
		{
			info->key_arrow_l = 0;
			info->key_arrow_r = 0;
		}
	}
	if (diff > 0)
	{
		info->key_arrow_l = 0;
		info->key_arrow_r = 1;
		if (ptr < mlx_mouse_get_pos(info->win, &x, &y) || diff == 0)
		{
			info->key_arrow_l = 0;
			info->key_arrow_r = 0;
		}
	}
	if (diff == 0)
	{
		info->key_arrow_l = 0;
		info->key_arrow_r = 0;
	}
	# if defined(__linux__)
		mlx_mouse_move(info->mlx, info->win, WINWIDTH / 2, WINHEIGHT / 2);
	# elif defined(__APPLE__) && defined(__MACH__)
		mlx_mouse_move(info->win, WINWIDTH / 2, WINHEIGHT / 2);
	# endif
	return (0);
	
}
