/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:42:06 by ujicama           #+#    #+#             */
/*   Updated: 2022/08/30 18:20:45 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_update(t_info *info)
{
	movements(info);
	rotation(info);
	if (info->key_esc)
		exit(0);
	return (0);
}

void	draw(t_info *info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < WINHEIGHT)
	{
		x = -1;
		while (++x < WINWIDTH)
			info->img.data[y * WINWIDTH + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	rays(t_info *info)
{
	int		x;
	int		y;

	x = -1;
	floor_and_ceiling(info);
	while (++x < WINWIDTH)
	{
		init_vars(info, x);
		choose_direction(info);
		draw_walls(info);
		y = info->rays.drawstart;
		while (y < info->rays.drawend)
		{
			info->rays.texy = (int)info->rays.texpos & (TEXHEIGHT - 1);
			info->rays.texpos += info->rays.step;
			info->rays.color = info->texture[info->rays.texnum][TEXHEIGHT
				* info->rays.texy + info->rays.texx];
			if (info->rays.hit == 2)
				info->rays.color = info->door.data[TEXHEIGHT
					* info->rays.texy + info->rays.texx];
			info->buf[y][x] = info->rays.color;
			y++;
		}
	}
}
