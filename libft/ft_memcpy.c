/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 11:35:23 by joerober          #+#    #+#             */
/*   Updated: 2022/10/25 09:56:07 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*conv1;
	const unsigned char	*conv2;

	i = 0;
	conv1 = (unsigned char *) dst;
	conv2 = (const unsigned char *) src;
	if (dst == NULL && src == NULL)
		return (0);
	while (i < n)
	{
		conv1[i] = conv2[i];
		i++;
	}
	return (conv1);
}
