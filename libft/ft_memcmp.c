/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:05:47 by joerober          #+#    #+#             */
/*   Updated: 2022/10/25 09:54:45 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*conv1;
	unsigned char	*conv2;

	conv1 = (unsigned char *) s1;
	conv2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (conv1[i] == conv2[i] && (i < n - 1))
		i++;
	return (conv1[i] - conv2[i]);
}
