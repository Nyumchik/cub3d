/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:10:36 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/31 15:01:29 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t	ft_strspn(const char *str, const char *charset)
{
	int	i;

	i = 0;
	if (str == NULL || charset == NULL)
		return (i);
	while (str[i] && ft_strchr(charset, str[i]))
		i++;
	return (i);
}

void	print_error_pos(int row, int column, char c)
{
	write(2, "map error: ", 11);
	write(2, "row : [", 7);
	ft_putnbr_fd(row, 2);
	write(2, "] column : [", 12);
	ft_putnbr_fd(column, 2);
	write(2, "] char : [", 10);
	ft_putchar_fd(c, 2);
	write(2, "]\n", 2);
	exit(1);
}

int	check_player_existence(t_info *info, char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (ft_strchr("SEWN", str[i][j]))
			{
				get_player_info(info, str, i, j);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	check_duplicate_player(t_info *info, char **temp)
{
	char	*pos;
	int		i;
	int		j;

	i = 0;
	pos = NULL;
	if (!check_player_existence(info, temp))
		exit_error_msg("missing player in map\n");
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (pos && (temp[i][j] == 'N' || temp[i][j] == 'S'
				|| temp[i][j] == 'E' || temp[i][j] == 'W'))
				exit_error_msg("duplicate player in map\n");
			if (ft_strchr("NSEW", temp[i][j]))
				pos = ft_strchr(temp[i], temp[i][j]);
			j++;
		}
		i++;
	}
}

void	ft_read_map(const int fd, t_info *info, char *line)
{
	char	*map;

	map = ft_strdup(line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[0] && line[0] == '\n')
		{
			free(line);
			exit_error_msg("bad map\n");
		}
		map = ft_strjoin_gnl(map, line);
		free(line);
	}
	close(fd);
	info->map = ft_split(map, '\n');
	free(map);
	check_duplicate_player(info, info->map);
	check_map_content(info->map, "01SEWN \n");
}
