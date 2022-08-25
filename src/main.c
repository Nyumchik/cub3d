/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 10:12:54 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/25 19:01:42 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_event(void)
{
	exit(0);
	return (0);
}

void	init_info2(t_info *info, int i, int j)
{
	while (++i < height)
	{
		j = -1;
		while (++j < width)
			info->buf[i][j] = 0;
	}
	info->texture = (int **)malloc(sizeof(int *) * 4);
	if (!info->texture)
		exit(-1);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		info->texture[i] = (int *)malloc(sizeof(int) * (texHeight * texWidth));
		if (!info->texture[i])
			exit(-1);
		while (++j < texHeight * texWidth)
			info->texture[i][j] = 0;
	}
}

void	init_info(t_info *info)
{
	info->mlx = mlx_init();
	info->dirX = -1.0;
	info->dirY = 0.0;
	info->planeX = 0.0;
	info->planeY = 0.66;
	info->key_a = 0;
	info->key_w = 0;
	info->key_s = 0;
	info->key_d = 0;
	info->key_arrow_l = 0;
	info->key_arrow_r = 0;
	info->key_esc = 0;
	info->moveSpeed = 0.03;
	info->rotSpeed = 0.03;
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	key_update(info);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;

	init_info(&info);
	check_map_file(ac, av[1]);
	init_info2(&info, -1, -1);
	parser(av[1], &info, 0);
	load_texture(&info);
	free(info.no_path);
	free(info.so_path);
	free(info.we_path);
	free(info.ea_path);
	info.win = mlx_new_window(info.mlx, width, height, "cub3D");
	info.img.img = mlx_new_image(info.mlx, width, height);
	info.img.data = (int *)mlx_get_data_addr(info.img.img,
			&info.img.bpp, &info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &info);
	mlx_hook(info.win, X_EVENT_KEY_RELEASE, 1L << 1, &key_release, &info);
	mlx_hook(info.win, X_EVENT_KEY_EXIT, 1L << 0, handle_event, NULL);
	mlx_loop(info.mlx);
	return (0);
}
