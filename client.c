#include "client.h"

static void ft_print_error_and_exit(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit (1);
}

static void ft_send_a_byte(pid_t s_pid, char c)
{
	int	shift;
	int send_sig;

	shift = 7;
	while (shift >= 0)
	{
		if ((c & (0b00000001 << shift)) == 0)
			send_sig = SIGUSR1;
		else
			send_sig = SIGUSR2;
		if (kill(s_pid, send_sig) == -1)
			ft_print_error_and_exit("kill Error\n");
		while (received_signal == 0)
			usleep(10);
		if (received_signal != send_sig)
			ft_print_error_and_exit("received signal Error\n");
		received_signal = 0;
		shift--;
	}
}

static void ft_send_str(pid_t s_pid, char *str)
{
	int	i;

	i = 0;
	while (1)
	{
		ft_send_a_byte(s_pid, str[i]);
		if (str[i++] == '\0')
			break;
	}
}

static void ft_handler_c(int signum)
{
	received_signal = signum;
}

int main(int argc, char **argv)
{
	struct sigaction sa;
	pid_t	server_pid;
	
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
	ft_send_str(server_pid, argv[2]);
	return (0);
}
