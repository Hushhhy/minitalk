/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:00:50 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/16 13:03:39 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	else
	{
		res = nb * ft_power(nb, power - 1);
		return (res);
	}
}

char	*to_string(char *s1, char byte)
{
	int		i;
	int		j;
	char	*tab;

	i = 0;
	j = 0;
	tab = malloc((ft_strlen(s1) + 2) * sizeof(char));
	if (!tab)
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	tab[j++] = byte;
	tab[j] = 0;
	free((void *)(s1));
	return (tab);
}

void	ft_signal(int signum, int result, char *final, int counter)
{
	if (!final)
		final = ft_strdup("");
	if (signum == SIGUSR1)
		result = result + 0;
	else if (signum == SIGUSR2)
		result = result + (1 * ft_power(2, 7 - counter));
}

void	signal_handle(int signum)
{
	int		counter;
	int		len;
	int		result;
	char	*final;

	counter = 0;
	result = 0;
	len = 0;
	final = NULL;
	ft_signal(signum, result, final, counter);
	counter++;
	if (counter == 8)
	{
		final = to_string(final, result);
		if (result == '\0')
		{
			ft_printf("%s\n", final);
			final = NULL;
		}
		counter = 0;
		result = 0;
		len++;
	}
}

int	main(void)
{
	struct sigaction	signal_received;

	ft_printf("Server PID : %d\n", getpid());
	signal_received.sa_handler = signal_handle;
	signal_received.sa_flags = 0;
	sigaction(SIGUSR1, &signal_received, NULL);
	sigaction(SIGUSR2, &signal_received, NULL);
	while (1)
		usleep(50);
}
