/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lauriago <lauriago@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:14:02 by lauriago          #+#    #+#             */
/*   Updated: 2024/03/04 17:10:33 by lauriago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	g_received;

// iterates the string from argv[1] and verify that the PID is correct
// if the string contains all number is correct.
// else, it means it's incorrect value.
int	check_pid(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

//converts the characters into 8 bits and send each bit as a signal to 
//the server. SIGUSR1 --> represents 1 & SIGUSR2 --> represents 0;
// 
// We use temp_char variable to save the char we want to send.
void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp_char;

	i = 8;
	temp_char = character;
	while (i-- > 0)
	{
		temp_char = character >> i;
		if (temp_char % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		g_received++;
	}
}

void	sig_confirm(int i)
{
	ft_printf("You're message have been successfully send\n");
	ft_printf("%d bites have been successfully recived\n", g_received);
}

int	main(int argc, char **argv)
{
	int		server_pid;
	const char	*message;
	int			i;
	

	i = 0;
	if (argc == 3)
	{
		if (check_pid(argv[1]) != 1)
			ft_printf("Error from PID\n");
		else if (check_pid(argv[1]) == 1)
		{
			server_pid = ft_atoi(argv[1]);
			message = argv[2];
			while (message[i])
				send_signal(server_pid, message[i++]);
			send_signal(server_pid, '\n');
		}
	sig_confirm(i);
	}
	else
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(1);
	}
	return (0);
}
