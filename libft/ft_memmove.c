/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:32:48 by joerober          #+#    #+#             */
/*   Updated: 2022/10/24 09:49:45 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*conv1;
	const unsigned char	*conv2;

	i = 0;
	conv1 = (unsigned char *) dst;
	conv2 = (const unsigned char *) src;
	if ((!dst && !src))
		return (NULL);
	if (conv2 < conv1)
	{
		while (len-- > 0)
			conv1[len] = conv2[len];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			conv1[i] = conv2[i];
			i++;
		}
	}
	return (conv1);
}
