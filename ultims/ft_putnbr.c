/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:13:45 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/07 21:13:47 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultims.h"

int	ft_putnbr(int n)
{
	long	nb;
	int		total;

	total = 0;
	nb = n;
	if (nb < 0)
	{
		total += ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
	{
		total += ft_putnbr(nb / 10);
		total += ft_putchar((nb % 10) + 48); 
	}
	else
		total += ft_putchar(nb + 48);
	return (total);
}
