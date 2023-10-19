/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:55:14 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/07 21:03:33 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include "../ft_printf/libft/includes/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct s_server_list
{
	int	client_pid;
	int	sig_received;
}	t_node;

static t_node	g_lst;

#endif
