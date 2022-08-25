/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:10:16 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/25 19:01:24 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_dir_south(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dirX;
	info->dirX = info->dirX * cos(M_PI) - info->dirY * sin(M_PI);
	info->dirY = old_dir_x * sin(M_PI) + info->dirY * cos(M_PI);
	old_plane_x = info->planeX;
	info->planeX = info->planeX * cos(M_PI) - info->planeY * sin(M_PI);
	info->planeY = old_plane_x * sin(M_PI) + info->planeY * cos(M_PI);
}

void	set_player_dir_west(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dirX;
	info->dirX = info->dirX * cos(M_PI / 2) - info->dirY * sin(M_PI / 2);
	info->dirY = old_dir_x * sin(M_PI / 2) + info->dirY * cos(M_PI / 2);
	old_plane_x = info->planeX;
	info->planeX = info->planeX * cos(M_PI / 2) - info->planeY * sin(M_PI / 2);
	info->planeY = old_plane_x * sin(M_PI / 2) + info->planeY * cos(M_PI / 2);
}
