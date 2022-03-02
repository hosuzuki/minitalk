/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/23 12:32:07 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	dst_length(char *dst, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (i < dstsize)
	{
		if (!dst[i])
			break ;
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len1;
	size_t	len2;

	len1 = dst_length(dst, dstsize);
	len2 = ft_strlen(src);
	if (dstsize == 0)
		return (len2);
	if (dstsize <= len1)
		return (len2 + dstsize);
	if (dstsize > len1 + len2)
		ft_strlcpy(dst + len1, src, len2 + 1);
	else
		ft_strlcpy(dst + len1, src, dstsize - len1);
	return (len1 + len2);
}
