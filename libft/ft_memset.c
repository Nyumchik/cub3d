/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:28:02 by ujicama           #+#    #+#             */
/*   Updated: 2021/10/06 17:28:02 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s,	int c, size_t len)
{
	char	*ptr;

	ptr = (char *)s;
	while (len > 0)
	{
		ptr[len - 1] = c;
		len--;
	}
	return (s);
}
