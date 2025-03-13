/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:01:08 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/09 12:42:38 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_list s = { 0, 31, 0, NULL, 0, 0, 0};
void	ft_variables(void)
{
	s.c = 0;
	s.j = 31;
	s.i = 0;
	s.len = 0;
	s.index = 0;
	s.c = 0;
	ft_free(s.str);
	s.str = NULL;
}
void	handler(int signum, siginfo_t *info, void *context)
{
	(void)context;
	if (info->si_pid != s.last_pid)
	{
		ft_variables();
		s.last_pid = info->si_pid;
	}
	if(s.j >= 0)
	{
		s.len = s.len << 1;
		if (signum == SIGUSR1)
			s.len = s.len | 1;
		s.j--;
		if (s.j == -1 && s.len > 0)
		{
			s.str = ft_calloc(s.len + 1, 1);
			if (!s.str)
				exit(1);
		}
	}
	else
	{
		s.c = s.c << 1;
        if (signum == SIGUSR1)
            s.c = s.c | 1;
        s.i++;

        if (s.i == 8)
        {
            s.str[s.index++] = s.c;
            s.c = 0;
            s.i = 0;

            if (s.index == s.len)
            {
                ft_printf("%s\n", s.str);
                s.len = 0;
                s.j = 31;
                s.index = 0;
				kill(info->si_pid, SIGUSR1);
            }
        }
	}
}

int	main(void)
{
	struct	sigaction action;

	ft_printf("SERVER PID = %d\n", getpid());
	action.sa_sigaction = handler;
	action.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);

	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}
