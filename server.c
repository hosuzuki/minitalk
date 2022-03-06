#include "server.h"

static void ft_print_error_and_exit(char *error_msg)
{
	ft_printf("%s\n", error_msg);
	exit (1);
}

static char	ft_receive_a_byte(void)
{
	char	c;
	int		shift_count;
	int		sig;

	c = 0;
	shift_count = 0;
	while (shift_count < 8)
	{
		while (lst.sig_to_receive == 0)
			usleep(100);
		sig = lst.sig_to_receive;
		lst.sig_to_receive = 0;
		if (kill(lst.client_pid, sig) != 0)
			ft_print_error_and_exit("kill Error\n");
		c <<= 1;
		if (sig == SIGUSR2)
			c++;
		shift_count++;
	}
	return (c);
}

static void	ft_receive_char(void)
{
	char	c;

	while (1)
	{
		c = ft_receive_a_byte();
		if (c == '\0')
			break ;
		write(1, &c, 1);
	}
  write(1, "\n-----\n", 7);
}

static void	ft_handler_s(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)ucontext;
	lst.client_pid = siginfo->si_pid;
	lst.sig_to_receive = signum;
}

int main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		ft_print_error_and_exit("Command Error\nex: ./server");
	sa.sa_sigaction = ft_handler_s;
	sa.sa_flags = SA_SIGINFO;
	if (sigemptyset(&sa.sa_mask) != 0)
		ft_print_error_and_exit("sigemptyset Error\n");
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		ft_print_error_and_exit("sigaction-SIGUSR1 Error\n");
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		ft_print_error_and_exit("sigaction-SIGUSR2 Error\n");
	ft_printf("The Server PID: %d\n", getpid());
	while (1)
		ft_receive_char();
	return (0);
}
