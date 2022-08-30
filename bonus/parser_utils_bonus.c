/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjohana <gjohana@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:37:46 by gjohana           #+#    #+#             */
/*   Updated: 2022/08/30 18:06:59 by gjohana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	skip_spaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

void	get_map_w_h(t_info *info)
{
	int	i;
	int	len;

	i = 0;
	info->mapw = ft_strlen(info->map[0]);
	while (info->map[i])
		i++;
	info->maph = i;
	i = 0;
	while (info->map[i])
	{
		len = ft_strlen(info->map[i]);
		if (len > info->mapw)
			info->mapw = len;
		i++;
	}
}
