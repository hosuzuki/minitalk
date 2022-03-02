/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/02 17:42:11 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	t_stock	*lst;
	int		total_length;

	if (!fmt)
		return (0);
	lst = (t_stock *)malloc(sizeof(t_stock));
	if (!lst)
		return (-1);
	lst->total_len = 0;
	va_start(lst->args, fmt);
	total_length = ft_analyze_fmt(fmt, lst);
	va_end(lst->args);
	free (lst);
	return (total_length);
}
