/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:16 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/02 17:41:34 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_print_space_hex(t_stock *lst, size_t len)
{
	long long	tmp;

	if (lst->zero_pad == ON)
		return ;
	tmp = 0;
	if (lst->hash == ON)
		tmp += 2;
	if (0 < lst->precision)
	{
		tmp += lst->precision;
		while (0 < lst->width - tmp)
			ft_write(lst, " ", 1);
	}	
	else if (0 < lst->width)
	{
		while (0 < lst->width - tmp - (long long)len)
			ft_write(lst, " ", 1);
	}
}

static char	*ft_dtoh(unsigned int nbr, char *base, size_t len)
{
	static size_t	i;
	static char		res[10];

	i = 0;
	if (len <= nbr)
		ft_dtoh(nbr / len, base, len);
	res[i++] = base[nbr % len];
	res[i] = '\0';
	return (res);
}

static void	ft_print_zero_hex(t_stock *lst, size_t len)
{
	if (0 < lst->precision)
	{
		while (0 < lst->precision - (long long)len)
		{
			ft_write(lst, "0", 1);
			lst->precision--;
		}
	}
	else if (lst->zero_pad == ON)
	{
		while (0 < lst->width - (long long)len)
			ft_write(lst, "0", 1);
	}
}

void	ft_print_hex_cap(t_stock *lst, unsigned int decimal)
{
	size_t	len;
	char	*hex;

	hex = ft_dtoh(decimal, "0123456789ABCDEF", 16);
	len = ft_strlen(hex);
	if (lst->left_align == OFF)
		ft_print_space_hex(lst, len);
	if (lst->hash == ON && decimal != 0)
		ft_write(lst, "0X", 2);
	ft_print_zero_hex(lst, len);
	ft_write(lst, hex, len);
	ft_print_left_align_space(lst);
}

void	ft_print_hex(t_stock *lst, unsigned int decimal)
{
	size_t	len;
	char	*hex;

	hex = ft_dtoh(decimal, "0123456789abcdef", 16);
	len = ft_strlen(hex);
	if (lst->left_align == OFF)
		ft_print_space_hex(lst, len);
	if (lst->hash == ON && decimal != 0)
		ft_write(lst, "0x", 2);
	ft_print_zero_hex(lst, len);
	ft_write(lst, hex, len);
	ft_print_left_align_space(lst);
}
