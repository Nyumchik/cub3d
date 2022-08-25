/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:16:48 by ujicama           #+#    #+#             */
/*   Updated: 2022/08/25 19:01:19 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_dir_east(t_info *info)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = info->dirX;
	info->dirX = info->dirX * cos(-M_PI / 2) - info->dirY * sin(-M_PI / 2);
	info->dirY = old_dir_x * sin(-M_PI / 2) + info->dirY * cos(-M_PI / 2);
	old_plane_x = info->planeX;
	info->planeX = info->planeX * cos(-M_PI / 2)
		- info->planeY * sin(-M_PI / 2);
	info->planeY = old_plane_x * sin(-M_PI / 2) + info->planeY * cos(-M_PI / 2);
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
	info->posX = y + 0.5;
	info->posY = x + 0.5;
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
