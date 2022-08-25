/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:46:34 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/25 19:01:07 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_end(char *line, int i)
{
	while (line[i] && line[i] != ' ')
		i++;
	return (i);
}

void	get_texture(t_info *info, int side, char *line)
{
	int	i;
	int	end;

	i = 0;
	end = 0;
	i = skip_spaces(line, i);
	i += 2;
	i = skip_spaces(line, i);
	end = get_end(line, i);
	if (side == NO)
		info->no_path = ft_substr(line, i, end - i - 1);
	else if (side == SO)
		info->so_path = ft_substr(line, i, end - i - 1);
	else if (side == WE)
		info->we_path = ft_substr(line, i, end - i - 1);
	else if (side == EA)
		info->ea_path = ft_substr(line, i, end - i - 1);
}

void	init_table(int *nb, int *i)
{
	nb[0] = 0;
	nb[1] = 0;
	nb[2] = 0;
	*i = 0;
}

void	check_errors(int sep, int *nb)
{
	if (sep > 3)
		exit_error_msg("invalid rgb format\n");
	else if (!nb[0] || !nb[1] || !nb[2])
		exit_error_msg("invalid rgb format\n");
	else if ((nb[0] > 3 || nb[0] < 0) || (nb[1] > 3 || nb[1] < 0)
		|| (nb[2] > 3 || nb[2] < 0))
		exit_error_msg("invalid rgb format\n");
}

void	valid_rgb_format(char *line)
{
	int	i;
	int	nb[3];
	int	sep;

	sep = 0;
	init_table(nb, &i);
	while (line[++i])
	{
		if (line[i] == '\n')
			break ;
		if ((line[i] == ',') || (line[i] >= '0' && line[i] <= '9'
				&& sep < 3) || line[i] == ' ')
		{
			if (line[i] == ',')
				sep++;
			else if (line[i] >= '0' && line[i] <= '9' && sep < 3)
				nb[sep]++;
		}
		else
			exit_error_msg("invalid rgb format\n");
	}
	check_errors(sep, nb);
}
