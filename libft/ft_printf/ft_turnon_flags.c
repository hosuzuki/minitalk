/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turnon_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:15 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/02 17:42:39 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_turnon_hash(t_stock *lst, size_t *i)
{
	(*i)++;
	lst->hash = ON;
}

void	ft_turnon_space(t_stock *lst, size_t *i)
{
	(*i)++;
	lst->space = ON;
}

void	ft_turnon_sign(t_stock *lst, size_t *i)
{
	(*i)++;
	lst->sign = PLUS;
}

void	ft_turnon_zero_pad(t_stock *lst, size_t *i)
{
	(*i)++;
	lst->zero_pad = ON;
}

void	ft_turnon_left_align(t_stock *lst, size_t *i)
{
	(*i)++;
	lst->left_align = ON;
}
