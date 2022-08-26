/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:16:48 by ujicama           #+#    #+#             */
/*   Updated: 2022/08/26 20:24:27 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_dir_east(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dirx;
	info->dirx = info->dirx * cos(-M_PI / 2) - info->diry * sin(-M_PI / 2);
	info->diry = old_dir_x * sin(-M_PI / 2) + info->diry * cos(-M_PI / 2);
	old_plane_x = info->planex;
	info->planex = info->planex * cos(-M_PI / 2)
		- info->planey * sin(-M_PI / 2);
	info->planey = old_plane_x * sin(-M_PI / 2) + info->planey * cos(-M_PI / 2);
}

void	set_player_dir(t_info *info, int dir)
{
	if (dir == NO)
		return ;
	else if (dir == SO)
		set_player_dir_south(info);
	else if (dir == WE)
		set_player_dir_west(info);
	else if (dir == EA)
		set_player_dir_east(info);
}

void	set_player_pos(t_info *info, int y, int x)
{
	info->posx = y + 0.5;
	info->posy = x + 0.5;
}

void	set_player_dir_pos(t_info *info, int dir, int y, int x)
{
	set_player_dir(info, dir);
	set_player_pos(info, y, x);
}

void	get_player_info(t_info *info, char **line, int y, int x)
{	
	if (line[y][x] == 'N')
		set_player_dir_pos(info, NO, y, x);
	else if (line[y][x] == 'S')
		set_player_dir_pos(info, SO, y, x);
	else if (line[y][x] == 'E')
		set_player_dir_pos(info, EA, y, x);
	else if (line[y][x] == 'W')
		set_player_dir_pos(info, WE, y, x);
}
