/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:36:31 by joerober          #+#    #+#             */
/*   Updated: 2022/10/24 09:54:09 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*conv;
	char	c2;

	i = 0;
	conv = (char *) s;
	c2 = (char) c;
	while (conv[i] != '\0')
	{
		if (conv[i] == c2)
			return (&conv[i]);
		i++;
	}
	if (conv[i] == c)
	{
		return (&conv[i]);
		i++;
	}
	if (c2 == '\0')
		return (&conv[i]);
	return (0);
}
