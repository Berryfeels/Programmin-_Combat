/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 18:14:05 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 15:50:39 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i])
		i++;
	dst = malloc(sizeof(char) * (i + 1));
	if (!dst)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		dst[j] = s1[j];
		j++;
	}
	return (dst);
}
