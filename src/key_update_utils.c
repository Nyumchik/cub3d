/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:25:28 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/25 19:01:36 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	movements2(t_info *info)
{
	if (info->key_d)
	{
		if (info->map[(int)(info->posX)][(int)(info->posY
					- info->dirX * info->moveSpeed)] != '1')
			info->posY -= info->dirX * info->moveSpeed;
		if (info->map[(int)(info->posX + info->dirY
				* info->moveSpeed)][(int)(info->posY)] != '1')
			info->posX += info->dirY * info->moveSpeed;
	}
	if (info->key_a)
	{
		if (info->map[(int)(info->posX)][(int)(info->posY
					+ info->dirX * info->moveSpeed)] != '1')
			info->posY += info->dirX * info->moveSpeed;
		if (info->map[(int)(info->posX - info->dirY
				* info->moveSpeed)][(int)(info->posY)] != '1')
			info->posX -= info->dirY * info->moveSpeed;
	}
}

void	movements(t_info *info)
{
	if (info->key_w)
	{
		if (info->map[(int)(info->posX + info->dirX
				* info->moveSpeed)][(int)(info->posY)] != '1')
			info->posX += info->dirX * info->moveSpeed;
		if (info->map[(int)(info->posX)][(int)(info->posY
				+ info->dirY * info->moveSpeed)] != '1')
			info->posY += info->dirY * info->moveSpeed;
	}
	if (info->key_s)
	{
		if (info->map[(int)(info->posX - info->dirX
				* info->moveSpeed)][(int)(info->posY)] != '1')
			info->posX -= info->dirX * info->moveSpeed;
		if (info->map[(int)(info->posX)][(int)(info->posY
				- info->dirY * info->moveSpeed)] != '1')
			info->posY -= info->dirY * info->moveSpeed;
	}
	movements2(info);
}

void	rotation2(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	if (info->key_arrow_l)
	{
		old_dir_x = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed)
			- info->dirY * sin(info->rotSpeed);
		info->dirY = old_dir_x * sin(info->rotSpeed)
			+ info->dirY * cos(info->rotSpeed);
		old_plane_x = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed)
			- info->planeY * sin(info->rotSpeed);
		info->planeY = old_plane_x * sin(info->rotSpeed)
			+ info->planeY * cos(info->rotSpeed);
	}
}

void	rotation(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	if (info->key_arrow_r)
	{
		old_dir_x = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed)
			- info->dirY * sin(-info->rotSpeed);
		info->dirY = old_dir_x * sin(-info->rotSpeed)
			+ info->dirY * cos(-info->rotSpeed);
		old_plane_x = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed)
			- info->planeY * sin(-info->rotSpeed);
		info->planeY = old_plane_x * sin(-info->rotSpeed)
			+ info->planeY * cos(-info->rotSpeed);
	}
	rotation2(info);
}
