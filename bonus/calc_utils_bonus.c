/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:55:21 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/26 16:14:16 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_vars2(t_info *info)
{
	if (info->calc.raydirx < 0)
	{
		info->calc.stepx = -1;
		info->calc.sidedistx = (info->posx - info->calc.mapx)
			* info->calc.deltadistx;
	}
	else
	{
		info->calc.stepx = 1;
		info->calc.sidedistx = (info->calc.mapx + 1.0 - info->posx)
			* info->calc.deltadistx;
	}
	if (info->calc.raydiry < 0)
	{
		info->calc.stepy = -1;
		info->calc.sidedisty = (info->posy - info->calc.mapy)
			* info->calc.deltadisty;
	}
	else
	{
		info->calc.stepy = 1;
		info->calc.sidedisty = (info->calc.mapy + 1.0 - info->posy)
			* info->calc.deltadisty;
	}
}

void	init_vars(t_info *info, int x)
{
	info->calc.camerax = 2 * x / (double)WINWIDTH - 1;
	info->calc.raydirx = info->dirx + info->planex * info->calc.camerax;
	info->calc.raydiry = info->diry + info->planey * info->calc.camerax;
	info->calc.mapx = (int)info->posx;
	info->calc.mapy = (int)info->posy;
	info->calc.deltadistx = fabs(1 / info->calc.raydirx);
	info->calc.deltadisty = fabs(1 / info->calc.raydiry);
	info->calc.hit = 0;
	init_vars2(info);
}

void	choose_direction(t_info *info)
{
	while (info->calc.hit == 0)
	{
		if (info->calc.sidedistx < info->calc.sidedisty)
		{
			info->calc.sidedistx += info->calc.deltadistx;
			info->calc.mapx += info->calc.stepx;
			info->calc.side = 0;
		}
		else
		{
			info->calc.sidedisty += info->calc.deltadisty;
			info->calc.mapy += info->calc.stepy;
			info->calc.side = 1;
		}
		if (info->map[info->calc.mapx][info->calc.mapy] == '1')
			info->calc.hit = 1;
		else if (info->map[info->calc.mapx][info->calc.mapy] == '2')
			info->calc.hit = 2;
	}
	if (info->calc.side == 0)
		info->calc.perpwalldist = (info->calc.mapx
				- info->posx + (1 - info->calc.stepx) / 2) / info->calc.raydirx;
	else
		info->calc.perpwalldist = (info->calc.mapy
				- info->posy + (1 - info->calc.stepy) / 2) / info->calc.raydiry;
}

void	draw_walls2(t_info *info)
{
	info->calc.texx = (int)(info->calc.wallx * (double)TEXWIDTH);
	if (info->calc.side == 0 && info->calc.raydirx > 0)
		info->calc.texx = TEXWIDTH - info->calc.texx - 1;
	if (info->calc.side == 1 && info->calc.raydiry < 0)
		info->calc.texx = TEXWIDTH - info->calc.texx - 1;
	info->calc.step = 1.0 * TEXHEIGHT / info->calc.lineheight;
	info->calc.texpos = (info->calc.drawstart
			- WINHEIGHT / 2 + info->calc.lineheight / 2) * info->calc.step;
}

void	draw_walls(t_info *info)
{
	info->calc.lineheight = (int)(WINHEIGHT / info->calc.perpwalldist);
	info->calc.drawstart = -info->calc.lineheight / 2 + WINHEIGHT / 2;
	if (info->calc.drawstart < 0)
		info->calc.drawstart = 0;
	info->calc.drawend = info->calc.lineheight / 2 + WINHEIGHT / 2;
	if (info->calc.drawend >= WINHEIGHT)
		info->calc.drawend = WINHEIGHT - 1;
	if (info->calc.side == 0 && info->calc.mapx > info->posx)
		info->calc.texnum = NO;
	if (info->calc.side == 0 && info->calc.mapx < info->posx)
		info->calc.texnum = SO;
	if (info->calc.side == 1 && info->calc.mapy > info->posy)
		info->calc.texnum = WE;
	if (info->calc.side == 1 && info->calc.mapy < info->posy)
		info->calc.texnum = EA;
	if (info->calc.side == 0)
		info->calc.wallx = info->posy
			+ info->calc.perpwalldist * info->calc.raydiry;
	else
		info->calc.wallx = info->posx
			+ info->calc.perpwalldist * info->calc.raydirx;
	info->calc.wallx -= floor(info->calc.wallx);
	draw_walls2(info);
}
