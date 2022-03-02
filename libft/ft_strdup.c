/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/19 07:10:55 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	i = ft_strlen(s1);
	dst = ft_calloc(i + 1, sizeof(char));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, i + 1);
	return (dst);
}
