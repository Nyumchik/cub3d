/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:55:21 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/25 19:00:53 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_vars2(t_info *info)
{
	if (info->calc.rayDirX < 0)
	{
		info->calc.stepX = -1;
		info->calc.sideDistX = (info->posX - info->calc.mapX)
			* info->calc.deltaDistX;
	}
	else
	{
		info->calc.stepX = 1;
		info->calc.sideDistX = (info->calc.mapX + 1.0 - info->posX)
			* info->calc.deltaDistX;
	}
	if (info->calc.rayDirY < 0)
	{
		info->calc.stepY = -1;
		info->calc.sideDistY = (info->posY - info->calc.mapY)
			* info->calc.deltaDistY;
	}
	else
	{
		info->calc.stepY = 1;
		info->calc.sideDistY = (info->calc.mapY + 1.0 - info->posY)
			* info->calc.deltaDistY;
	}
}

void	init_vars(t_info *info, int x)
{
	info->calc.cameraX = 2 * x / (double)width - 1;
	info->calc.rayDirX = info->dirX + info->planeX * info->calc.cameraX;
	info->calc.rayDirY = info->dirY + info->planeY * info->calc.cameraX;
	info->calc.mapX = (int)info->posX;
	info->calc.mapY = (int)info->posY;
	info->calc.deltaDistX = fabs(1 / info->calc.rayDirX);
	info->calc.deltaDistY = fabs(1 / info->calc.rayDirY);
	info->calc.hit = 0;
	init_vars2(info);
}

void	choose_direction(t_info *info)
{
	while (info->calc.hit == 0)
	{
		if (info->calc.sideDistX < info->calc.sideDistY)
		{
			info->calc.sideDistX += info->calc.deltaDistX;
			info->calc.mapX += info->calc.stepX;
			info->calc.side = 0;
		}
		else
		{
			info->calc.sideDistY += info->calc.deltaDistY;
			info->calc.mapY += info->calc.stepY;
			info->calc.side = 1;
		}
		if (info->map[info->calc.mapX][info->calc.mapY] == '1')
			info->calc.hit = 1;
	}
	if (info->calc.side == 0)
		info->calc.perpWallDist = (info->calc.mapX
				- info->posX + (1 - info->calc.stepX) / 2) / info->calc.rayDirX;
	else
		info->calc.perpWallDist = (info->calc.mapY
				- info->posY + (1 - info->calc.stepY) / 2) / info->calc.rayDirY;
}

void	draw_walls2(t_info *info)
{
	info->calc.texX = (int)(info->calc.wallX * (double)texWidth);
	if (info->calc.side == 0 && info->calc.rayDirX > 0)
		info->calc.texX = texWidth - info->calc.texX - 1;
	if (info->calc.side == 1 && info->calc.rayDirY < 0)
		info->calc.texX = texWidth - info->calc.texX - 1;
	info->calc.step = 1.0 * texHeight / info->calc.lineHeight;
	info->calc.texPos = (info->calc.drawStart
			- height / 2 + info->calc.lineHeight / 2) * info->calc.step;
}

void	draw_walls(t_info *info)
{
	info->calc.lineHeight = (int)(height / info->calc.perpWallDist);
	info->calc.drawStart = -info->calc.lineHeight / 2 + height / 2;
	if (info->calc.drawStart < 0)
		info->calc.drawStart = 0;
	info->calc.drawEnd = info->calc.lineHeight / 2 + height / 2;
	if (info->calc.drawEnd >= height)
		info->calc.drawEnd = height - 1;
	if (info->calc.side == 0 && info->calc.mapX > info->posX)
		info->calc.texNum = NO;
	if (info->calc.side == 0 && info->calc.mapX < info->posX)
		info->calc.texNum = SO;
	if (info->calc.side == 1 && info->calc.mapY > info->posY)
		info->calc.texNum = WE;
	if (info->calc.side == 1 && info->calc.mapY < info->posY)
		info->calc.texNum = EA;
	if (info->calc.side == 0)
		info->calc.wallX = info->posY
			+ info->calc.perpWallDist * info->calc.rayDirY;
	else
		info->calc.wallX = info->posX
			+ info->calc.perpWallDist * info->calc.rayDirX;
	info->calc.wallX -= floor(info->calc.wallX);
	draw_walls2(info);
}
