/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:16 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/02 17:42:00 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_digit_len(size_t n)
{
	size_t	i;

	i = 1;
	while (9 < n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_dtoa_un(char *res, size_t nbr, size_t *i)
{
	if (9 < nbr)
	{
		ft_dtoa_un(res, nbr / 10, i);
		ft_dtoa_un(res, nbr % 10, i);
	}
	else
		res[(*i)++] = '0' + nbr;
}

static char	*ft_itoa_un(unsigned int nbr)
{
	size_t	len;
	char	*res;
	size_t	i;

	len = ft_digit_len(nbr);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	ft_dtoa_un(res, nbr, &i);
	res[i] = '\0';
	return (res);
}

void	ft_print_unsigned(t_stock *lst, unsigned int nbr)
{
	char	*res;
	size_t	len;

	res = ft_itoa_un(nbr);
	if (!res)
	{
		lst->status = ERROR;
		return ;
	}
	len = ft_strlen(res);
	if (lst->sign != MINUS)
		ft_print_space(lst, len);
	if (lst->space == OFF && lst->left_align == OFF)
		ft_print_wid_pre(lst, len);
	ft_print_sign(lst);
	ft_print_zero_pad(lst, len);
	ft_write(lst, res, len);
	ft_print_left_align_space(lst);
	free (res);
}
