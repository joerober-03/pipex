/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joerober <joerober@student.42lausan>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 09:57:13 by joerober          #+#    #+#             */
/*   Updated: 2022/10/24 09:56:32 by joerober         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*mem;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	mem = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + (ft_strlen(s2)) + 1));
	if (!mem)
		return (0);
	while (s1[j])
	{
		mem[i++] = s1[j];
		j++;
	}
	j = 0;
	while (s2[j])
	{
		mem[i++] = s2[j];
		j++;
	}
	mem[i] = '\0';
	return (mem);
}
