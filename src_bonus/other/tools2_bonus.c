/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheragh <mcheragh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:42:32 by mcheragh          #+#    #+#             */
/*   Updated: 2025/04/02 16:19:33 by mcheragh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r');
}

long	ft_atol(const char *str)
{
	long	num;
	int		i;
	int		digit;

	num = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		return (0);
	else if (str[i] == '-') 
		return (0);
	while (str[i] != '\0') 
	{
		if (!ft_isdigit(str[i])) 
			return (0);
		digit = str[i] - '0';
		if (num > (LONG_MAX - digit) / 10)
			return (0);
		num = num * 10 + digit;
		i++;
	}
	return (num);
}

char	*ft_strdup2(const char *s1)
{
	char	*dst;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	while (s1[start] && ft_isspace((unsigned char)s1[start]))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && ft_isspace((unsigned char)s1[end - 1]))
		end--;
	dst = malloc(sizeof(char) * (end - start + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (start < end)
		dst[i++] = s1[start++];
	dst[i] = '\0';
	return (dst);
}

int	is_all_space(const char *str)
{
	int	i;

	if (!str)
		return (1);
	i = 0;
	while (str[i])
	{
		if (!ft_isspace((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}
