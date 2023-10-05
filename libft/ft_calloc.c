/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:30:22 by joerober          #+#    #+#             */
/*   Updated: 2022/10/24 09:55:47 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*string;

	i = 0;
	string = malloc(count * size);
	if (!string)
		return (0);
	while (i < count * size)
	{
		string[i] = 0;
		i++;
	}	
	return (string);
}
