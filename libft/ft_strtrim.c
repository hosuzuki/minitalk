/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:52 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/25 10:08:26 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	size_t	len;
	char	*dst;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front = 0;
	back = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[front]) && front < len)
		front++;
	while (ft_strchr(set, s1[len - 1 - back]) && back < len - front)
		back++;
	len = len - (front + back);
	dst = ft_substr(s1, front, len);
	return (dst);
}
