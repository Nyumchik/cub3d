/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:37:02 by ujicama           #+#    #+#             */
/*   Updated: 2022/08/30 14:42:47 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_cell(t_info *info, int x, int y)
{
	int	xx;

	xx = x;
	while (y < info->mm.ystop)
	{
		if (xx == 0)
			x = 0;
		else
			x = xx;
		while (x < info->mm.xstop)
		{
			mlx_pixel_put(info->mlx, info->win, x, y, info->mm.color);
			x++;
		}
		y++;
	}
}

int	pick_color(t_info *info, int x, int y)
{
	if (y < 0 || x < 0)
		return (BLACK);
	if (x > info->mapw)
		return (BLACK);
	if (y > info->maph)
		return (BLACK);
	if (!info->map[y])
		return (BLACK);
	if (info->map[y] && x > (int)ft_strlen(info->map[y]))
		return (BLACK);
	if (info->map[y][x] == '0')
		return (GRAY);
	if (info->map[y][x] == 'N' || info->map[y][x] == 'S'
		|| info->map[y][x] == 'E' || info->map[y][x] == 'W')
		return (GRAY);
	if (info->map[y][x] == '1')
		return (BLACK);
	return (BLACK);
}

int	get_p_dir_map(t_info *info)
{
	if (info->dirx <= -0.75
		&& (info->diry <= 0.75 && info->diry >= -0.75))
		return (NO);
	else if (info->dirx > 0.75
		&& (info->diry <= 0.75 && info->diry >= -0.75))
		return (SO);
	else if (info->diry <= -0.75
		&& (info->dirx <= 0.75 && info->dirx >= -0.75))
		return (WE);
	else if (info->diry > 0.75
		&& (info->dirx <= 0.75 && info->dirx >= -0.75))
		return (EA);
	return (info->mm.lastside);
}

void	draw_minimap(t_info *info, int my, int mx)
{
	int	imx;
	int	imy;

	imy = -2;
	while (imy < 3)
	{
		imx = -2;
		while (imx < 3)
		{
			info->mm.color = pick_color(info, my + imx, mx + imy);
			if (imy == 0 && imx == 0)
				draw_player_arrow(info, info->mm.x, info->mm.y);
			else
				draw_cell(info, info->mm.x, info->mm.y);
			info->mm.x += GRID;
			info->mm.xstop += GRID;
			imx++;
		}
		info->mm.y += GRID;
		info->mm.ystop += GRID;
		info->mm.xstop = GRID;
		info->mm.x = 0;
		imy++;
	}
}

void	minimap(t_info *info)
{
	int	mx;
	int	my;

	mx = info->posx;
	my = info->posy;
	info->mm.color = GRAY;
	info->mm.x = 0;
	info->mm.y = 0;
	info->mm.xstop = GRID;
	info->mm.ystop = GRID;
	info->mm.lastside = get_p_dir_map(info);
	draw_minimap(info, my, mx);
}
