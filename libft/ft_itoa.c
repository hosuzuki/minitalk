/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 18:03:48 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/11/25 10:13:18 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	i;

	i = 1;
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	to_alpha(char *res, int n, int *i)
{
	if (n == INT_MIN)
	{
		to_alpha(res, n / 10, i);
		res[(*i)++] = '8';
	}
	else if (n < 0)
	{
		res[(*i)++] = '-';
		to_alpha(res, -n, i);
	}
	else if (n > 9)
	{
		to_alpha(res, n / 10, i);
		to_alpha(res, n % 10, i);
	}
	else
		res[(*i)++] = '0' + n;
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*res;
	int		i;

	digits = count_digits(n);
	res = ft_calloc(digits + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	to_alpha(res, n, &i);
	res[i] = '\0';
	return (res);
}
