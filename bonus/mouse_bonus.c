/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:48:12 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/31 15:21:31 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_diff(t_info *info, double diff)
{
	if (diff == 0)
	{
		info->key_arrow_l = 0;
		info->key_arrow_r = 0;
	}
}

int	mouse(int x, int y, t_info *info)
{
	double	diff;
	double	ptr;

	(void)y;
	diff = x - (WINWIDTH / 2);
	ptr = mlx_mouse_get_pos(info->win, &x, &y);
	if (diff < 0)
	{
		info->key_arrow_l = 1;
		info->key_arrow_r = 0;
		if (ptr > mlx_mouse_get_pos(info->win, &x, &y) || diff == 0)
			info->key_arrow_l = 0;
	}
	if (diff > 0)
	{
		info->key_arrow_l = 0;
		info->key_arrow_r = 1;
		if (ptr < mlx_mouse_get_pos(info->win, &x, &y) || diff == 0)
			info->key_arrow_r = 0;
	}
	check_diff(info, diff);
	mlx_mouse_move(info->win, WINWIDTH / 2, WINHEIGHT / 2);
	return (0);
}
