/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 21:13:32 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/07 21:13:35 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultims.h"
#include <limits.h>

int	ft_puthexa(unsigned int n, char format)
{
	int		count;
	char	*s;

	s = "0123456789abcdef";
	count = 0;
	if (format == 'X')
		s = "0123456789ABCDEF";
	if (n < 16)
		count += ft_putchar(s[n]);
	else
	{
		count += ft_puthexa(n / 16, format);
		count += ft_putchar(s[n % 16]);
	}
	return (count);
}
