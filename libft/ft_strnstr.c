/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:52 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/20 12:01:51 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	nlen;

	i = 0;
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return ((char *)haystack);
	else if (len == 0)
		return (NULL);
	while (haystack[i] != '\0' && i + nlen <= len)
	{
		if (ft_strncmp(&haystack[i], needle, nlen) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
