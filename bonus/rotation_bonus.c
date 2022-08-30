/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:25:28 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/30 17:35:05 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotation2(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	if (info->key_arrow_l)
	{
		old_dir_x = info->dirx;
		info->dirx = info->dirx * cos(info->rotspeed)
			- info->diry * sin(info->rotspeed);
		info->diry = old_dir_x * sin(info->rotspeed)
			+ info->diry * cos(info->rotspeed);
		old_plane_x = info->planex;
		info->planex = info->planex * cos(info->rotspeed)
			- info->planey * sin(info->rotspeed);
		info->planey = old_plane_x * sin(info->rotspeed)
			+ info->planey * cos(info->rotspeed);
	}
}

void	rotation(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	if (info->key_arrow_r)
	{
		old_dir_x = info->dirx;
		info->dirx = info->dirx * cos(-info->rotspeed)
			- info->diry * sin(-info->rotspeed);
		info->diry = old_dir_x * sin(-info->rotspeed)
			+ info->diry * cos(-info->rotspeed);
		old_plane_x = info->planex;
		info->planex = info->planex * cos(-info->rotspeed)
			- info->planey * sin(-info->rotspeed);
		info->planey = old_plane_x * sin(-info->rotspeed)
			+ info->planey * cos(-info->rotspeed);
	}
	rotation2(info);
}
