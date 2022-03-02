/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:17 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/02 17:41:47 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_print_space_s(t_stock *lst, size_t len)
{
	if ((long long)len < lst->width)
	{
		while (0 < lst->width - (long long)len)
			ft_write(lst, " ", 1);
	}
	else if (lst->precision != OFF && lst->precision < lst->width)
	{
		while (0 < lst->width - lst->precision)
			ft_write(lst, " ", 1);
	}
}

void	ft_print_str(t_stock *lst, char *str)
{
	size_t	len;

	if (!str)
	{
		len = 6;
		str = "(null)";
	}
	else
		len = ft_strlen(str);
	if (lst->left_align == OFF)
		ft_print_space_s(lst, len);
	if (lst->left_align == OFF && lst->precision < lst->width)
		ft_print_wid_pre(lst, len);
	if ((long long)len <= lst->precision || lst->precision == OFF)
		ft_write(lst, str, len);
	else if (lst->precision < (long long)len)
		ft_write(lst, str, lst->precision);
	ft_print_left_align_space(lst);
}
