/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:39:39 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/26 14:56:09 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	exit_error_msg(char *err_msg)
{
	write(2, "error: ", 7);
	write(2, err_msg, ft_strlen(err_msg));
	exit(1);
}

int	check_map_file(int ac, char *line)
{
	size_t	i;

	i = 0;
	if (ac != 2)
		exit_error_msg("invalid number of arguments\n");
	while (line[i])
		i++;
	i--;
	while (i && line[i] != '.')
		i--;
	if (!i || ft_strncmp(&line[i], ".cub\0", 5))
		exit_error_msg("invalid map file extension\n");
	return (0);
}

void	check_map_content(char	**temp, char *charset)
{
	int		i;
	int		j;

	i = 0;
	if (ft_strspn(temp[i], "1 \n") != ft_strlen(temp[i]))
		exit_error_msg("map must be closed/surrounded by walls\n");
	while (temp[i + 1])
	{
		if (ft_strspn(temp[i], charset) != ft_strlen(temp[i]))
			exit_error_msg("map must be composed of only '01NSEW'\n");
		j = ft_strspn(temp[i], " ");
		if (temp[i][j] != '1')
			print_error_pos(i, j, temp[i][j]);
		j = 0;
		while (temp[i][j])
		{
			if (check_valid_path(temp, i, j) == -1)
				exit_error_msg("bad map\n");
			j++;
		}
		i++;
	}
	if (ft_strspn(temp[i], "1 \n") != ft_strlen(temp[i]))
		exit_error_msg("map must be closed/surrounded by walls\n");
}

int	check_for_error(char **map, int i, int j)
{
	if (map[i][j + 1] != '1' && map[i][j + 1] != '0'
			&& !ft_strchr("SEWN2", map[i][j + 1]))
		return (-1);
	if (!map[i][j + 1])
		return (-1);
	if (map[i][j - 1] != '1' && map[i][j - 1] != '0'
		&& !ft_strchr("SEWN2", map[i][j - 1]))
		return (-1);
	if (!map[i][j - 1])
		return (-1);
	if (map[i + 1][j] != '1' && map[i + 1][j] != '0'
		&& !ft_strchr("SEWN2", map[i + 1][j]))
		return (-1);
	if (!map[i + 1][j])
		return (-1);
	if (map[i - 1][j] != '1' && map[i - 1][j] != '0'
		&& !ft_strchr("SEWN2", map[i - 1][j]))
		return (-1);
	if (!map[i - 1][j])
		return (-1);
	return (0);
}

int	check_valid_path(char **map, int i, int j)
{
	if (i == 0)
		return (0);
	if (map[i][j] == '0')
		if (check_for_error(map, i, j) == -1)
			return (-1);
	if (map[i][j] == ' ')
	{
		if (j - 1 == -1)
			return (0);
		if (map[i][j + 1] != '1' && map[i][j + 1] != ' '
			&& !ft_strchr("SEWN", map[i][j + 1]))
			return (-1);
		if (map[i][j - 1] != '1' && map[i][j - 1] != ' '
			&& !ft_strchr("SEWN", map[i][j - 1]))
			return (-1);
	}
	if (ft_strchr("SEWN2", map[i][j]))
		if (check_for_error(map, i, j) == -1)
			return (-1);
	if (map[i][j] == '2')
		if (check_door(map, i, j) == -1)
			return (-1);
	return (0);
}
