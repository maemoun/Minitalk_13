/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:07:09 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/09 12:43:05 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	tot;
	long long	check;

	sign = 1;
	tot = 0;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		check = tot;
		tot = (tot * 10) + (*nptr - 48);
		if (tot / 10 != check && sign == 1)
			return (-1);
		else if (tot / 10 != check && sign == -1)
			return (0);
		nptr++;
	}
	return (tot * sign);
}

void	send_bit(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i--;
		usleep(300);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;
	char	*s;

	if (ac != 3)
	{
		write(1, "try next time : ", 16);
		write(1, " <pid> <message>\n", 17);
	}
	i = 0;
	pid = ft_atoi(av[1]);
	s = av[2];
	while (s[i])
	{
		send_bit(s[i], pid);
		i++;
	}
	return (EXIT_SUCCESS);
}
