/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:31:43 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/30 17:43:17 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	movements4(t_info *info)
{
	if (info->key_a)
	{
		if (info->map[(int)(info->posx)][(int)(info->posy
					+ info->dirx * info->movespeed)] != '1'
				&& info->map[(int)(info->posx)][(int)(info->posy
					+ info->dirx * info->movespeed)] != '2')
			info->posy += info->dirx * info->movespeed;
		if (info->map[(int)(info->posx - info->diry
				* info->movespeed)][(int)(info->posy)] != '1'
				&& info->map[(int)(info->posx - info->diry
				* info->movespeed)][(int)(info->posy)] != '2')
			info->posx -= info->diry * info->movespeed;
	}
}

void	movements3(t_info *info)
{
	if (info->key_s)
	{
		if (info->map[(int)(info->posx - info->dirx
				* info->movespeed)][(int)(info->posy)] != '1'
				&& info->map[(int)(info->posx - info->dirx
				* info->movespeed)][(int)(info->posy)] != '2')
			info->posx -= info->dirx * info->movespeed;
		if (info->map[(int)(info->posx)][(int)(info->posy
				- info->diry * info->movespeed)] != '1'
				&& info->map[(int)(info->posx)][(int)(info->posy
				- info->diry * info->movespeed)] != '2')
			info->posy -= info->diry * info->movespeed;
	}
	movements4(info);
}

void	movements2(t_info *info)
{
	if (info->key_d)
	{
		if (info->map[(int)(info->posx)][(int)(info->posy
					- info->dirx * info->movespeed)] != '1'
				&& info->map[(int)(info->posx)][(int)(info->posy
					- info->dirx * info->movespeed)] != '2')
			info->posy -= info->dirx * info->movespeed;
		if (info->map[(int)(info->posx + info->diry
				* info->movespeed)][(int)(info->posy)] != '1'
				&& info->map[(int)(info->posx + info->diry
				* info->movespeed)][(int)(info->posy)] != '2')
			info->posx += info->diry * info->movespeed;
	}
	movements3(info);
}

void	movements(t_info *info)
{
	if (info->key_w)
	{
		if (info->map[(int)(info->posx + info->dirx
				* info->movespeed)][(int)(info->posy)] != '1'
				&& info->map[(int)(info->posx + info->dirx
				* info->movespeed)][(int)(info->posy)] != '2')
			info->posx += info->dirx * info->movespeed;
		if (info->map[(int)(info->posx)][(int)(info->posy
				+ info->diry * info->movespeed)] != '1'
				&& info->map[(int)(info->posx)][(int)(info->posy
				+ info->diry * info->movespeed)] != '2')
			info->posy += info->diry * info->movespeed;
	}
	movements2(info);
}
