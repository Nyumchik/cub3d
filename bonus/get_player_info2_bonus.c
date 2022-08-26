/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:10:16 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/26 17:02:37 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_dir_south(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dirx;
	info->dirx = info->dirx * cos(M_PI) - info->diry * sin(M_PI);
	info->diry = old_dir_x * sin(M_PI) + info->diry * cos(M_PI);
	old_plane_x = info->planex;
	info->planex = info->planex * cos(M_PI) - info->planey * sin(M_PI);
	info->planey = old_plane_x * sin(M_PI) + info->planey * cos(M_PI);
}

void	set_player_dir_west(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dirx;
	info->dirx = info->dirx * cos(M_PI / 2) - info->diry * sin(M_PI / 2);
	info->diry = old_dir_x * sin(M_PI / 2) + info->diry * cos(M_PI / 2);
	old_plane_x = info->planex;
	info->planex = info->planex * cos(M_PI / 2) - info->planey * sin(M_PI / 2);
	info->planey = old_plane_x * sin(M_PI / 2) + info->planey * cos(M_PI / 2);
}
