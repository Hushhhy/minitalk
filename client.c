/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:00:52 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/22 14:13:33 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_response(int sig)
{
	if (sig == SIGUSR2)
	{
		ft_printf("🟢 The server received the message\n");
		exit(0);
	}
}

void	ft_bitsend(int pid, char i)
{
	int	byte;

	byte = 0;
	while (byte < 8)
	{
		if ((i & (0x01 << byte)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		byte++;
	}
}

void	ft_sigsend(int pid, char *msg)
{
	int	i;

	ft_bitsend(pid, 0x01);
	i = 0;
	while (msg[i] != '\0')
	{
		ft_bitsend(pid, msg[i]);
		i++;
	}
	ft_bitsend(pid, 0x04);
	i = 0;
	while (i < 3)
	{
		sleep(1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac != 3)
	{
		ft_printf("Wrong! Try : {PID} {MESSAGE}.\n");
		return (1);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID\n");
		return (1);
	}
	signal(SIGUSR2, ft_response);
	ft_sigsend(pid, av[2]);
	return (0);
}
