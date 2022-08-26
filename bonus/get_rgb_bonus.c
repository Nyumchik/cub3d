/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:42:52 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/25 19:12:26 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	skip_number_atoi(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '0' && str[i] <= '9') || str[i] == ' ')
		i++;
	return (i);
}

int	convert_rgb(int r, int g, int b)
{
	return ((r << 16) + (g << 8) + b);
}

int	check_num_rgb(int num)
{
	if (num > 255 || num < 0)
		return (1);
	return (0);
}

int	get_rgb(char *line)
{
	int		i;
	int		red;
	int		green;
	int		blue;

	valid_rgb_format(line);
	i = 2;
	red = ft_atoi(line + i);
	i += skip_number_atoi(line + i) + 1;
	green = ft_atoi(line + i);
	i += skip_number_atoi(line + i) + 1;
	blue = ft_atoi(line + i);
	if (check_num_rgb(red) || check_num_rgb(green) || check_num_rgb(blue))
		exit_error_msg("invalid rgb format\n");
	return (convert_rgb(red, green, blue));
}
