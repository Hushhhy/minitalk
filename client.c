/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:00:52 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/16 12:37:53 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sigsend(int pid, char *msg)
{
	int	byte;
	int	i;

	byte = 0;
	while (msg[byte])
	{
		i = 8;
		while (--i >= 0)
		{
			if ((msg[byte] & 1 << i) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
		}
		byte++;
	}
	i = 0;
	while (i++ < 8)
	{
		kill(pid, SIGUSR1);
		usleep(50);
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*message;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (!pid)
		{
			ft_printf("Error\n");
			return (0);
		}
		message = av[2];
		if (message[0] == 0)
		{
			ft_printf("Error\n");
			return (0);
		}
		ft_sigsend(pid, message);
	}
	else
		ft_printf("Missing Arguments !\n");
	return (0);
}
