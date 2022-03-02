/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:41:14 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/02 17:42:49 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_save_precision(const char *fmt, t_stock *lst, size_t *i)
{
	long long	len;

	if (fmt[*i] != '.')
		return ;
	(*i)++;
	if (fmt[*i] == '*')
	{
		lst->precision = va_arg(lst->args, int);
		(*i)++;
		return ;
	}
	len = 0;
	while (ft_isdigit(fmt[*i]))
	{
		len = len * 10;
		len = len + (fmt[*i] - '0');
		(*i)++;
	}
	lst->precision = len;
	if (ERROR == ft_under_intmax(lst, lst->total_len, lst->precision))
		lst->status = ERROR;
}

void	ft_save_width(const char *fmt, t_stock *lst, size_t *i)
{
	long long	len;

	if (fmt[*i] == '*')
	{
		lst->width = va_arg(lst->args, int);
		if (lst->width < 0)
		{
			lst->width = -(lst->width);
			lst->left_align = ON;
		}
		if (ERROR == ft_under_intmax(lst, lst->total_len, lst->width))
			lst->status = ERROR;
		(*i)++;
		return ;
	}
	len = 0;
	while (ft_isdigit(fmt[*i]))
	{
		len = len * 10;
		len = len + (fmt[*i] - '0');
		(*i)++;
	}
	lst->width = len;
	if (ERROR == ft_under_intmax(lst, lst->total_len, lst->width))
		lst->status = ERROR;
}
