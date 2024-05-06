/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:00:52 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/06 14:39:45 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long	i;
	long	min;
	long	result;

	i = 0;
	min = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			min *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result *= min);
}

// void	ft_encrypt(int pid, char *msg)
// {
	
// }

int	main(int ac, char **av)
{
	int		pid;
	char	*message;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (!pid || ft_check(pid) == 0)
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
		ft_encrypt(pid, message);
	}
	else
		ft_printf("Missing Arguments !\n");
	return (0);
}
