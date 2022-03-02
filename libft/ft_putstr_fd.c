/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:50 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/15 20:35:25 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *c, int fd)
{
	size_t	len;

	if (!c)
		return ;
	len = ft_strlen(c);
	while (len > INT_MAX)
	{
		write(fd, c, INT_MAX);
		c += INT_MAX;
		len -= INT_MAX;
	}
	write(fd, c, len);
}
