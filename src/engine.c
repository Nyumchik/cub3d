/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:42:06 by ujicama           #+#    #+#             */
/*   Updated: 2022/08/25 19:01:12 by gjohana          ###   ########.fr       */
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
	while (++y < height)
	{
		x = -1;
		while (++x < width)
			info->img.data[y * width + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	calc(t_info *info)
{
	int		x;
	int		y;

	x = -1;
	floor_and_ceiling(info);
	while (++x < width)
	{
		init_vars(info, x);
		choose_direction(info);
		draw_walls(info);
		y = info->calc.drawStart;
		while (y < info->calc.drawEnd)
		{
			info->calc.texY = (int)info->calc.texPos & (texHeight - 1);
			info->calc.texPos += info->calc.step;
			info->calc.color = info->texture[info->calc.texNum][texHeight
				* info->calc.texY + info->calc.texX];
			info->buf[y][x] = info->calc.color;
			y++;
		}
	}
}
