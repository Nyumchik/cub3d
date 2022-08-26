/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:25:28 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/26 18:23:55 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	movements2(t_info *info)
{
	if (info->key_d)
	{
		if (info->map[(int)(info->posx)][(int)(info->posy
					- info->dirx * info->movespeed)] != '1')
			info->posy -= info->dirx * info->movespeed;
		if (info->map[(int)(info->posx + info->diry
				* info->movespeed)][(int)(info->posy)] != '1')
			info->posx += info->diry * info->movespeed;
	}
	if (info->key_a)
	{
		if (info->map[(int)(info->posx)][(int)(info->posy
					+ info->dirx * info->movespeed)] != '1')
			info->posy += info->dirx * info->movespeed;
		if (info->map[(int)(info->posx - info->diry
				* info->movespeed)][(int)(info->posy)] != '1')
			info->posx -= info->diry * info->movespeed;
	}
}

void	movements(t_info *info)
{
	if (info->key_w)
	{
		if (info->map[(int)(info->posx + info->dirx
				* info->movespeed)][(int)(info->posy)] != '1')
			info->posx += info->dirx * info->movespeed;
		if (info->map[(int)(info->posx)][(int)(info->posy
				+ info->diry * info->movespeed)] != '1')
			info->posy += info->diry * info->movespeed;
	}
	if (info->key_s)
	{
		if (info->map[(int)(info->posx - info->dirx
				* info->movespeed)][(int)(info->posy)] != '1')
			info->posx -= info->dirx * info->movespeed;
		if (info->map[(int)(info->posx)][(int)(info->posy
				- info->diry * info->movespeed)] != '1')
			info->posy -= info->diry * info->movespeed;
	}
	movements2(info);
}

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
