/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:17:36 by lauriago          #+#    #+#             */
/*   Updated: 2024/03/04 17:22:19 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
#include <signal.h>
#include <unistd.h>

void	handle_signal(int signum)
{
	static unsigned char	byte;
	static int	bit_count;

	byte = 0;
	bit_count = 0;
	if (signum == SIGUSR1)
		byte = (byte << 1) | 1;
	else if (signum == SIGUSR2)
		byte = byte << 1;
	bit_count++;
	if (bit_count == 8)
	{
		ft_printf("%c", byte);
		byte = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
