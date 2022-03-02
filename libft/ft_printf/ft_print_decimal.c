/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/02 17:41:09 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_print_space_deci(t_stock *lst, size_t len, long long tmp)
{
	if ((long long)len < lst->width)
	{
		if (0 < lst->precision && 0 < lst->width - lst->precision
			&& lst->sign == MINUS)
			tmp += lst->width - lst->precision;
		else if (0 < lst->precision && (long long)len < lst->precision)
			tmp += lst ->precision;
		else
			tmp += len;
		while (0 < lst->width - tmp)
			ft_write(lst, " ", 1);
	}
	else if (0 < lst->precision && lst->precision < lst->width
		&& (long long)len < lst->width)
	{
		tmp += lst->precision;
		while (0 < lst->width - tmp)
			ft_write(lst, " ", 1);
	}
}

static void	ft_print_width_preci_space_deci(t_stock *lst, size_t len)
{
	long long	tmp;

	if (lst->zero_pad == ON && lst->width < lst->precision)
		return ;
	if (lst->zero_pad == ON && lst->precision < 0)
		return ;
	tmp = 0;
	ft_print_space_deci(lst, len, tmp);
}

static void	ft_print_flags_before_deci(t_stock *lst, size_t len)
{
	if (lst->sign != MINUS)
		ft_print_space(lst, len);
	if (lst->left_align == OFF && lst->precision < lst->width)
		ft_print_width_preci_space_deci(lst, len);
	ft_print_sign(lst);
	ft_print_zero_pad(lst, len);
}

void	ft_print_decimal(t_stock *lst, int decimal)
{
	size_t	len;
	char	*res;

	res = ft_itoa(decimal);
	if (!res)
	{
		lst->status = ERROR;
		return ;
	}
	len = ft_strlen(res);
	if (decimal < 0)
		lst->sign = MINUS;
	ft_print_flags_before_deci(lst, len);
	if (res[0] == '-')
		ft_write(lst, res + 1, len - 1);
	else if (lst->precision != 0 || decimal != 0)
		ft_write(lst, res, len);
	if (0 < lst->width && lst->precision == 0 && decimal == 0)
		ft_write(lst, " ", 1);
	ft_print_left_align_space(lst);
	free (res);
}
