/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:48 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/02/18 08:27:40 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static bool	is_space(const char c)
{
	if (c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (true);
	return (false);
}

static int	check_max(long long res, char *str, size_t i, int sign)
{
	long long	tmp;

	tmp = (res * 10) + (str[i] - '0');
	if (tmp / 10 != res)
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (1);
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;
	size_t		i;
	int			max_index;

	res = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		max_index = check_max(res, (char *)str, i, sign);
		if (max_index != 1)
			return (max_index);
		res = (res * 10) + (str[i++] - '0');
	}
	return ((int)res * sign);
}
