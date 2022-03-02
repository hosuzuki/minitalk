/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:10:30 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/02 17:40:49 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_char(t_stock *lst, int c)
{
	char	chara;

	if (lst->left_align == OFF)
		ft_print_space(lst, 1);
	chara = (char)c;
	if (lst->left_align == OFF && lst->precision < lst->width)
		ft_print_wid_pre(lst, 1);
	ft_write(lst, &chara, 1);
	ft_print_left_align_space(lst);
}
