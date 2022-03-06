#include "server.h"



#include <stdio.h>

void printb(unsigned int v) {
  unsigned int mask = (int)1 << (sizeof(v) * CHAR_BIT - 1);
  do putchar(mask & v ? '1' : '0');
  while (mask >>= 1);
}

void putb(unsigned int v) {
	putchar('0'), putchar('b'), printb(v), putchar('\n');
}



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
		while (received_sig == 0)
			usleep(100);
		sig = received_sig;
//		printf("sig: %d\n", sig);
		received_sig = 0;
//		printf("client_pid: %d | sig: %d\n", client_pid, sig);
		if (kill(client_pid, sig) != 0)
			ft_print_error_and_exit("kill Error\n");
		c <<= 1;
//		putb(c);
//		printf("\n");
//		printf("sig: %d | SIGUSR2: %d\n", sig, SIGUSR2);
		if (sig == SIGUSR2)
		{
//			putb(c);
//			printf("\n");
			c++;
//			putb(c);
//			printf("\n");
		}
//		printf("shift_count: %d\n", shift_count);
		shift_count++;
//		printf("shift_count: %d\n", shift_count);
	}
	return (c);
}

static void	ft_receive_str(void)
{
	char	c;

	while (1)
	{
		c = ft_receive_a_byte();
		if (c == '\0')
			break ;
		write(1, &c, 1);
	}
/*
  write(STDOUT_FILENO, "\n--- [", 6);
	ft_putnbr_fd(client_pid, 1);
	write(STDOUT_FILENO, "] Communication end ---\n\n", 25);
*/
}

/*
static void ft_handler_s(int signum, siginfo_t *info, void *context)
//void handler(int signum)
{
	static char	c;
	static int		bits;
//	static int client_pid;

	(void)context;
	client_pid = info->si_pid;
	received_sig = signum;
//	c = 0;
//	c |= (signum == SIGUSR2);
	c |= (signum == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		write(1, &c, 1);
		bits = 0;
		c = 0;
	}
	else
		c <<= 1;
//	kill(client_pid, SIGUSR2);
	kill(client_pid, SIGUSR1);
}
*/

static void	ft_handler_s(int signum, siginfo_t *siginfo, void *ucontext)
{
	(void)*ucontext;
	client_pid = siginfo->si_pid;
//	printf("client_pid: %d\n", client_pid);
	received_sig = signum;
//	printf("received_sig: %d\n", received_sig);
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
	while(1)
//	{
		//		pause();
		ft_receive_str();
//	}
	return (0);
}
