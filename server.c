/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:00:50 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/22 14:10:03 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_straddc(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
	{
		new = (char *)malloc(sizeof(char) * 2);
		if (!new)
			return (0);
		new[0] = c;
		new[1] = '\0';
		return (new);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!new)
		return (0);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = '\0';
	free(str);
	return (new);
}

void	ft_sighandle(int signum, siginfo_t *info, void *context)
{
	static char		*msg = 0;
	static int		byte;
	static int		i;

	(void)context;
	if (signum == SIGUSR1)
		i |= (0x01 << byte);
	byte++;
	if (byte == 8)
	{
		if (i == 4)
		{
			ft_printf("{%d} %s\n", info->si_pid, msg);
			free(msg);
			msg = 0;
			kill(info->si_pid, SIGUSR2);
		}
		else
			msg = ft_straddc(msg, i);
		byte = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_memset(&sa, 0, sizeof(sa));
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_sighandle;
	ft_printf("Server PID : %d\n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
