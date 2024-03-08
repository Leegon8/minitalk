/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:17:36 by lauriago          #+#    #+#             */
/*   Updated: 2024/03/04 18:09:29 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <signal.h>
#include <unistd.h>

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	byte;
	static int		bit_count;

	(void) context;
	byte |= (signum == SIGUSR1);
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", byte);
		byte = 0;
		bit_count = 0;
	}
	else
		byte <<= 1;
/*	if (signum == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signum == SIGUSR2)
		kill(info->si_pid, SIGUSR2);*/
}

int	main(void)
{
	struct sigaction	act;

	act.sa_sigaction = &sig_handler;
	act.sa_flags = SA_RESTART;
	sigemptyset(&act.sa_mask);
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
