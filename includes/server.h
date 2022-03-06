#ifndef CLIENT_H
# define CLIENT_H

# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
#	include "../libft/includes/libft.h"
#	include "../libft/includes/ft_printf.h"

//static int client_pid = 0;
//static int received_sig = 0;

typedef struct
{
	int client_pid;
	int sig_to_receive;
} t_node;

static t_node g_lst;

#endif
