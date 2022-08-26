/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:42:06 by ujicama           #+#    #+#             */
/*   Updated: 2022/08/26 13:54:52 by ujicama          ###   ########.fr       */
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

void	calc(t_info *info)
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
		y = info->calc.drawstart;
		while (y < info->calc.drawend)
		{
			info->calc.texy = (int)info->calc.texpos & (TEXHEIGHT - 1);
			info->calc.texpos += info->calc.step;
			info->calc.color = info->texture[info->calc.texnum][TEXHEIGHT
				* info->calc.texy + info->calc.texx];
			info->buf[y][x] = info->calc.color;
			y++;
		}
	}
}
