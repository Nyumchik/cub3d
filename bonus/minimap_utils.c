/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 14:42:48 by ujicama           #+#    #+#             */
/*   Updated: 2022/08/30 14:44:05 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_n_arrow(t_info *info)
{
	int	x;
	int	y;
	int	xstop;
	int	xx;

	x = 58;
	y = 56;
	xstop = 60;
	xx = x;
	while (y++ < 66)
	{
		x = xx--;
		while (x++ < xstop)
			mlx_pixel_put(info->mlx, info->win, x, y, RED);
		xstop++;
	}
}

void	draw_s_arrow(t_info *info)
{
	int	x;
	int	y;
	int	xstop;
	int	xx;

	x = 58;
	y = 63;
	xstop = 60;
	xx = x;
	while (y-- > 53)
	{
		x = xx--;
		while (x++ < xstop)
			mlx_pixel_put(info->mlx, info->win, x, y, RED);
		xstop++;
	}
}

void	draw_w_arrow(t_info *info)
{
	int	x;
	int	y;
	int	ystop;
	int	yy;

	x = 56;
	y = 58;
	ystop = 60;
	yy = y;
	while (x++ < 66)
	{
		y = yy--;
		while (y++ < ystop)
			mlx_pixel_put(info->mlx, info->win, x, y, RED);
		ystop++;
	}
}

void	draw_e_arrow(t_info *info)
{
	int	x;
	int	y;
	int	ystop;
	int	yy;

	x = 63;
	y = 58;
	ystop = 60;
	yy = y;
	while (x-- > 53)
	{
		y = yy--;
		while (y++ < ystop)
			mlx_pixel_put(info->mlx, info->win, x, y, RED);
		ystop++;
	}
}

void	draw_player_arrow(t_info *info, int x, int y)
{
	draw_cell(info, x, y);
	info->mm.lastside = get_p_dir_map(info);
	if (info->mm.lastside == NO)
		draw_n_arrow(info);
	else if (info->mm.lastside == SO)
		draw_s_arrow(info);
	else if (info->mm.lastside == WE)
		draw_w_arrow(info);
	else if (info->mm.lastside == EA)
		draw_e_arrow(info);
}
