/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:31:23 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/11 11:31:47 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_validate_base(char *str)
{
	while (*str)
	{
		if (!(32 <= *str && *str <= 126))
			return (0);
		if (*str == '+' || *str == '-')
			return (0);
		if (ft_strchr(str + 1, *str) != NULL)
			return (0);
		str++;
	}
	return (1);
}

static void	ft_print_body(long l_nbr, char *base, int len)
{
	if (l_nbr < 0)
	{
		write(1, "-", 1);
		ft_print_body(-l_nbr, base, len);
	}
	else
	{
		if (l_nbr >= len)
		{
			ft_print_body(l_nbr / len, base, len);
		}
		write(1, &base[l_nbr % len], 1);
		return ;
	}
}

void	ft_putnbr_base(size_t nbr, char *base)
{
	int	len;

	if (!ft_validate_base(base))
		return ;
	len = ft_strlen(base);
	if (len <= 1)
		return ;
	ft_print_body((long)nbr, base, len);
}
