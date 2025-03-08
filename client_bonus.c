/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:01:16 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/08 11:23:55 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

void	send_len(int n, int pid)
{
	int i;
	i = 31; 
	if(n < 0)
		exit(1);
	while(i >= 0)
	{
		if (n & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		i--;
	}
}

void	send_bit(char c, int pid)
{
	int i;
	i = 7;
	while(i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		i--;
	}
}


void	writing(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("message wsal\n");
}

int	main(int ac, char **av)
{
	int i;
	int pid;
	struct sigaction	action;

	sigemptyset(&action.sa_mask);
	action.sa_handler = writing;
	action.sa_flags = 0;
	sigaction(SIGUSR1, &action, NULL);
	

	if (ac != 3)
	{
		write(1, "try next time : ",16);
		write(1, " <pid> <message>\n", 17);
		return EXIT_FAILURE;
	}

	i = 0;
	pid = ft_atoi(av[1]);
	char	*s = av[2];
	static int n;
	n = ft_strlen(s);
	send_len(n, pid);
	while (s[i])
	{
		send_bit(s[i], pid);
		i++;
	}
	return EXIT_SUCCESS;
}