/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:23:25 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/02 17:45:54 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define ERROR -1
# define GOOD 0
# define OFF -5
# define ON  1
# define PLUS 2
# define MINUS -2

typedef struct slist
{
	size_t		total_len;
	va_list		args;
	int			status;
	int			left_align;
	int			zero_pad;
	int			hash;
	int			sign;
	int			space;
	long long	width;
	long long	precision;
}	t_stock;

int		ft_printf(const char *fmt, ...);
int		ft_analyze_fmt(const char *fmt, t_stock *lst);

void	ft_print_str(t_stock *lst, char *str);
void	ft_print_char(t_stock *lst, int c);
void	ft_print_address(t_stock *lst, size_t address);
void	ft_print_unsigned(t_stock *lst, unsigned int decimal);
void	ft_print_decimal(t_stock *lst, int decimal);
void	ft_print_hex(t_stock *lst, unsigned int decimal);
void	ft_print_hex_cap(t_stock *lst, unsigned int decimal);
void	ft_turnon_left_align(t_stock *lst, size_t *i);
void	ft_turnon_zero_pad(t_stock *lst, size_t *i);
void	ft_turnon_sign(t_stock *lst, size_t *i);
void	ft_turnon_space(t_stock *lst, size_t *i);
void	ft_turnon_hash(t_stock *lst, size_t *i);

void	ft_save_precision(const char *fmt, t_stock *lst, size_t *i);
void	ft_save_width(const char *fmt, t_stock *lst, size_t *i);

void	ft_print_space(t_stock *lst, size_t len);
void	ft_print_wid_pre(t_stock *lst, size_t len);
void	ft_print_sign(t_stock *lst);
void	ft_print_left_align_space(t_stock *lst);
void	ft_print_zero_pad(t_stock *lst, size_t len);
int		ft_write(t_stock *lst, char	*content, size_t len);
int		ft_under_intmax(t_stock *lst, size_t total, size_t len);

#endif
