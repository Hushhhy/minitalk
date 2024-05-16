/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 11:01:11 by acarpent          #+#    #+#             */
/*   Updated: 2024/05/16 13:00:40 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "libft.h"

char	*to_string(char *s1, char byte);
void	ft_sigsend(int pid, char *msg);
char	*to_string(char *s1, char byte);
void	signal_handle(int signum);
void	ft_signal(int signum, int result, char *final, int counter);

#endif