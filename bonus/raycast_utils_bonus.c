/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:55:21 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/30 17:59:58 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_vars2(t_info *info)
{
	if (info->rays.raydirx < 0)
	{
		info->rays.stepx = -1;
		info->rays.sidedistx = (info->posx - info->rays.mapx)
			* info->rays.deltadistx;
	}
	else
	{
		info->rays.stepx = 1;
		info->rays.sidedistx = (info->rays.mapx + 1.0 - info->posx)
			* info->rays.deltadistx;
	}
	if (info->rays.raydiry < 0)
	{
		info->rays.stepy = -1;
		info->rays.sidedisty = (info->posy - info->rays.mapy)
			* info->rays.deltadisty;
	}
	else
	{
		info->rays.stepy = 1;
		info->rays.sidedisty = (info->rays.mapy + 1.0 - info->posy)
			* info->rays.deltadisty;
	}
}

void	init_vars(t_info *info, int x)
{
	info->rays.camerax = 2 * x / (double)WINWIDTH - 1;
	info->rays.raydirx = info->dirx + info->planex * info->rays.camerax;
	info->rays.raydiry = info->diry + info->planey * info->rays.camerax;
	info->rays.mapx = (int)info->posx;
	info->rays.mapy = (int)info->posy;
	info->rays.deltadistx = fabs(1 / info->rays.raydirx);
	info->rays.deltadisty = fabs(1 / info->rays.raydiry);
	info->rays.hit = 0;
	init_vars2(info);
}

void	choose_direction(t_info *info)
{
	while (info->rays.hit == 0)
	{
		if (info->rays.sidedistx < info->rays.sidedisty)
		{
			info->rays.sidedistx += info->rays.deltadistx;
			info->rays.mapx += info->rays.stepx;
			info->rays.side = 0;
		}
		else
		{
			info->rays.sidedisty += info->rays.deltadisty;
			info->rays.mapy += info->rays.stepy;
			info->rays.side = 1;
		}
		if (info->map[info->rays.mapx][info->rays.mapy] == '1')
			info->rays.hit = 1;
		else if (info->map[info->rays.mapx][info->rays.mapy] == '2')
			info->rays.hit = 2;
	}
	if (info->rays.side == 0)
		info->rays.perpwalldist = (info->rays.mapx
				- info->posx + (1 - info->rays.stepx) / 2) / info->rays.raydirx;
	else
		info->rays.perpwalldist = (info->rays.mapy
				- info->posy + (1 - info->rays.stepy) / 2) / info->rays.raydiry;
}

void	draw_walls2(t_info *info)
{
	info->rays.texx = (int)(info->rays.wallx * (double)TEXWIDTH);
	if (info->rays.side == 0 && info->rays.raydirx > 0)
		info->rays.texx = TEXWIDTH - info->rays.texx - 1;
	if (info->rays.side == 1 && info->rays.raydiry < 0)
		info->rays.texx = TEXWIDTH - info->rays.texx - 1;
	info->rays.step = 1.0 * TEXHEIGHT / info->rays.lineheight;
	info->rays.texpos = (info->rays.drawstart
			- WINHEIGHT / 2 + info->rays.lineheight / 2) * info->rays.step;
}

void	draw_walls(t_info *info)
{
	info->rays.lineheight = (int)(WINHEIGHT / info->rays.perpwalldist);
	info->rays.drawstart = -info->rays.lineheight / 2 + WINHEIGHT / 2;
	if (info->rays.drawstart < 0)
		info->rays.drawstart = 0;
	info->rays.drawend = info->rays.lineheight / 2 + WINHEIGHT / 2;
	if (info->rays.drawend >= WINHEIGHT)
		info->rays.drawend = WINHEIGHT - 1;
	if (info->rays.side == 0 && info->rays.mapx > info->posx)
		info->rays.texnum = NO;
	if (info->rays.side == 0 && info->rays.mapx < info->posx)
		info->rays.texnum = SO;
	if (info->rays.side == 1 && info->rays.mapy > info->posy)
		info->rays.texnum = WE;
	if (info->rays.side == 1 && info->rays.mapy < info->posy)
		info->rays.texnum = EA;
	if (info->rays.side == 0)
		info->rays.wallx = info->posy
			+ info->rays.perpwalldist * info->rays.raydiry;
	else
		info->rays.wallx = info->posx
			+ info->rays.perpwalldist * info->rays.raydirx;
	info->rays.wallx -= floor(info->rays.wallx);
	draw_walls2(info);
}
