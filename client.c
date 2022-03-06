#include "client.h"



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


static void ft_send_a_byte(pid_t s_pid, char c)
{
	int	shift;
	int send_sig;

//	printf("s_pid: %d\n", s_pid);
	shift = 7;
	while (0 <= shift)
	{
//		ft_printf("c: %c\n", c);
//		ft_printf("c: %d\n", c);
//		putb(c);
//		ft_printf("shift: %d\n", shift);
		if ((c & (0b00000001 << shift)) == 0)
		{
			send_sig = SIGUSR1;
//			ft_printf("SIGUSR1: %d\n", SIGUSR1);
		}
		else
		{
			send_sig = SIGUSR2;
//			ft_printf("SIGUSR2: %d\n", SIGUSR2);
		}
		if (kill(s_pid, send_sig) != 0)
			ft_print_error_and_exit("kill Error\n");
//		ft_printf("s_pid: %d | send_sig: %d\n", s_pid, send_sig);
//		ft_printf("received_signal: %d\n", received_signal);
		while (received_signal == 0)
		{
			usleep(100);
			ft_printf("usleep\n");
		}
//		ft_printf("received_signal: %d | send_sig:%d\n", received_signal, send_sig);
		if (received_signal != send_sig)
			ft_print_error_and_exit("received or send signal Error\n");
		received_signal = 0;
//		ft_printf("shift: %d\n", shift);
		shift--;
//		ft_printf("shift: %d\n", shift);
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
//	printf("signum: %d\n", signum);
	received_signal = signum;
}

int main(int argc, char **argv)
{
	struct sigaction sa;
	pid_t	s_pid;
	
	if (argc != 3)
		ft_print_error_and_exit("Command Error\n");
	s_pid = ft_atoi(argv[1]);
	if (s_pid <= 0)
		ft_print_error_and_exit("Invalid Server PID\n");
	sa.sa_handler = ft_handler_c;
	sa.sa_flags = 0;
	if (sigemptyset(&sa.sa_mask) != 0)
		ft_print_error_and_exit("sigemptyset Error\n");
//	printf("siga~: %d\n", sigaction(SIGUSR1, &sa, NULL));
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		ft_print_error_and_exit("sigaction-SIGUSR1 Error\n");
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		ft_print_error_and_exit("sigaction-SIGUSR2 Error\n");
	ft_send_str(s_pid, argv[2]);
	return (0);
}
