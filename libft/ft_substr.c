/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 16:36:27 by ujicama           #+#    #+#             */
/*   Updated: 2021/10/19 16:13:43 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getlen(const char *s, unsigned int start, size_t len)
{
	size_t	slen;
	size_t	maxlen;

	slen = ft_strlen(s);
	if (start >= slen)
		return (0);
	else
	{
		maxlen = slen - start;
		if (len > maxlen)
			return (maxlen);
		return (len);
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	new;
	char	*substr;

	if (!s)
		return (NULL);
	new = ft_getlen(s, start, len);
	substr = malloc(new + 1);
	if (substr)
	{
		i = 0;
		while (i < new)
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
