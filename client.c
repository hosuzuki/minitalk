/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 17:54:55 by hokutosuz         #+#    #+#             */
/*   Updated: 2022/03/07 17:54:55 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	ft_print_error_and_exit(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit (1);
}

static void	ft_send_a_byte(pid_t server_pid, char c)
{
	int	shift;
	int	sig_to_send;

	shift = 0;
	while (shift <= 7)
	{
		if ((c & (0b10000000 >> shift)) == 0)
			sig_to_send = SIGUSR1;
		else
			sig_to_send = SIGUSR2;
		if (kill(server_pid, sig_to_send) != 0)
			ft_print_error_and_exit("kill Error\n");
		while (g_sig_received == 0)
			usleep(100);
		if (g_sig_received != sig_to_send)
			ft_print_error_and_exit("sig received or to send Error\n");
		g_sig_received = 0;
		shift++;
	}
}

static void	ft_send_char(pid_t server_pid, char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		ft_send_a_byte(server_pid, str[i]);
		if (str[i++] == '\0')
			break ;
	}
}

static void	ft_handler_c(int signum)
{
	g_sig_received = signum;
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;

	if (argc != 3)
		ft_print_error_and_exit("Command Error\n");
	server_pid = ft_atoi(argv[1]);
	if (server_pid <= 0)
		ft_print_error_and_exit("Invalid Server PID\n");
	sa.sa_handler = ft_handler_c;
	sa.sa_flags = 0;
	if (sigemptyset(&sa.sa_mask) != 0)
		ft_print_error_and_exit("sigemptyset Error\n");
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		ft_print_error_and_exit("sigaction-SIGUSR1 Error\n");
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		ft_print_error_and_exit("sigaction-SIGUSR2 Error\n");
	ft_send_char(server_pid, argv[2]);
	return (0);
}
