/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:48 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/25 10:00:17 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	check_bytes(size_t *sum, size_t *count, size_t *size)
{
	if (*count == 0 || *size == 0)
	{
		*count = 1;
		*size = 1;
	}
	*sum = *count * *size;
	if (*sum / *count != *size)
		return (false);
	return (true);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	sum;

	errno = 0;
	if (!check_bytes(&sum, &count, &size))
	{
		errno = ENOMEM;
		return (NULL);
	}
	res = malloc(sum);
	if (!res)
		return (NULL);
	ft_bzero(res, sum);
	return (res);
}
