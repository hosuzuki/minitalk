#include "server.h"

static void ft_print_error_and_exit(char *msg)
{
	ft_printf("%s\n", msg);
	exit (1);
}

//static void ft_recieve_str()
//{


static void ft_handler(int signum, siginfo_t *info, void *context)
//void handler(int signum)
{
	char	c;
	int		bits;

	(void)context;
	client_pid = info->si_pid;
//	received_sig = signum;
	c = 0;
	c |= (signum == SIGUSR2);
	bits = 0;
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
	else
		c <<= 1;
	kill(client_pid, SIGUSR2);
}

int main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_handler;
	sa.sa_flags = 0;
	if (sigemptyset(&sa.sa_mask) != 0)
		ft_print_error_and_exit("sigemptyset error\n");
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		ft_print_error_and_exit("SIGUSR1 error\n");
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		ft_print_error_and_exit("SIGUSR2 error\n");
	ft_printf("The server PID: %d\n", getpid());
	while(1)
		pause();
//		ft_recieve_str();
	return (0);
}
