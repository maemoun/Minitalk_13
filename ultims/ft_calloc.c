/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeskhai <maeskhai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:12:44 by maeskhai          #+#    #+#             */
/*   Updated: 2025/03/07 12:12:51 by maeskhai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ultims.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*s;
	void			*p;
	size_t			bytes;

	bytes = count * size;
	if (size && bytes / size != count)
		return (NULL);
	p = malloc(bytes);
	if (p == NULL)
		return (NULL);
	s = p;
	while (bytes--)
	{
		*(unsigned char *)s++ = 0;
	}
	return (p);
}