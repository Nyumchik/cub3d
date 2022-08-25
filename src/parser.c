/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 17:28:26 by ujicama           #+#    #+#             */
/*   Updated: 2022/08/25 19:15:13 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	take_element2(t_info *info, char *line, int **count)
{
	if (!ft_strncmp(line, "F", 1) && ++(**count))
	{
		info->floorColor = get_rgb(line);
		return (0);
	}
	else if (!ft_strncmp(line, "C", 1) && ++(**count))
	{
		info->ceilingColor = get_rgb(line);
		return (0);
	}
	return (1);
}

int	take_element(t_info *info, char *line, int *count)
{
	if (!ft_strncmp(line, "NO", 2) && ++(*count))
	{
		get_texture(info, NO, line);
		return (0);
	}	
	else if (!ft_strncmp(line, "SO", 2) && ++(*count))
	{
		get_texture(info, SO, line);
		return (0);
	}
	else if (!ft_strncmp(line, "WE", 2) && ++(*count))
	{
		get_texture(info, WE, line);
		return (0);
	}
	else if (!ft_strncmp(line, "EA", 2) && ++(*count))
	{
		get_texture(info, EA, line);
		return (0);
	}
	else if (!take_element2(info, line, &count))
		return (0);
	return (1);
}

int	try_read_map(t_info *info, int fd, char *line, int i)
{
	i = ft_strspn(line, " ");
	if (i == 0)
	{
		ft_read_map(fd, info, line);
		return (0);
	}
	else if (ft_strncmp(line, "1", ft_strspn(line, " ")))
	{
		ft_read_map(fd, info, line);
		return (0);
	}
	return (1);
}

void	parser(char *file, t_info *info, int count)
{
	const int	fd = open(file, O_RDONLY);
	char		*line;

	if (fd < 0)
		exit_error_msg("can't open map file\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (take_element(info, line, &count) && ft_strchr(line, '1'))
		{
			if (!try_read_map(info, fd, line, 0))
				break ;
		}
		if (line)
			free(line);
		if (count > 6)
			exit_error_msg("invalid map file\n");
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (count != 6)
		exit_error_msg("invalid map file\n");
	close(fd);
}
