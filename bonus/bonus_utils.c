/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:56:32 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/30 18:00:15 by gjohana          ###   ########.fr       */
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

void	close_door(t_info *info)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = (int)(info->posy / 64);
	x = (int)(info->posx / 64);
	while (info->old_map[i])
	{
		j = 0;
		while (info->old_map[i][j])
		{
			if (info->old_map[i][j] == '2')
			{
				if (((j != x) && (j + 1 != x && j - 1 != x)))
					info->map[i][j] = info->old_map[i][j];
				if (((i != y) && (i + 1 != y && i - 1 != y)))
					info->map[i][j] = info->old_map[i][j];
				info->rays.hit = 2;
			}
			j++;
		}
		i++;
	}
}

void	open_door(t_info *info)
{
	if (info->map[(int)(info->posx + info->dirx
			* info->movespeed)][(int)(info->posy)] == '2')
		info->map[(int)(info->posx + info->dirx
				* info->movespeed)][(int)(info->posy)] = '0';
	if (info->map[(int)(info->posx)][(int)(info->posy
				+ info->diry * info->movespeed)] == '2')
		info->map[(int)(info->posx)][(int)(info->posy
				+ info->diry * info->movespeed)] = '0';
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
