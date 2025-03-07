/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:13:39 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/07 21:13:42 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultims.h"

int	ft_putnbr_u(unsigned int n)
{
	int	total;

	total = 0;
	if (n >= 10)
	{
		total += ft_putnbr(n / 10);
		total += ft_putchar((n % 10) + 48);
	}
	else
		total += ft_putchar(n + 48);
	return (total);
}
