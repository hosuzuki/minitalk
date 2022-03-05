void ft_print_error_and_exit(char *msg);
{

}


void ft_recieve_str()
{
	
}

void handler(int signum, siginfo_t *info, void *context)
//void handler(int signum)
{
	(void)context;
	client_pid = info->si_pid;
	received_sig = signum;
}

int main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = 0;
	if (sigemptyset(&sa.sa_mask) != 0)
		ft_print_error_and_exit("sigemptyset error\n");
	if (sigaction(SIGUSR1, &sa, NULL) != 0)
		ft_print_error_and_exit("SIGUSR1 error\n");
	if (sigaction(SIGUSR2, &sa, NULL) != 0)
		ft_print_error_and_exit("SIGUSR2 error\n");
	ft_printf("The server PID: %d\n", getpid());
	while(1)
		ft_recieve_str();
	return (0);
}
