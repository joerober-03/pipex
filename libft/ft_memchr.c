/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 08:44:58 by joerober          #+#    #+#             */
/*   Updated: 2022/10/25 09:54:14 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*conv;
	unsigned char	c2;
	size_t			i;

	conv = (unsigned char *) str;
	c2 = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (conv[i] == c2)
			return (&conv[i]);
		i++;
	}
	return (0);
}
