/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 17:01:22 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/07 12:14:54 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define	MINITALK_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
#include "./ultims/ultims.h"

typedef	struct init
{
	int i;
	int j;
	char c;
	char *str;
	int len;
    int index;
    int last_pid;
}	t_list;


#endif