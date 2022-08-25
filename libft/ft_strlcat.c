/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:15:54 by ujicama           #+#    #+#             */
/*   Updated: 2021/10/19 16:15:36 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srcsize;
	size_t	dstsize;

	srcsize = ft_strlen(src);
	dstsize = ft_strlen(dst);
	if (size < dstsize)
		return (srcsize + size);
	else
	{
		dst = dst + dstsize;
		ft_strlcpy(dst, src, size - dstsize);
		return (srcsize + dstsize);
	}
}
