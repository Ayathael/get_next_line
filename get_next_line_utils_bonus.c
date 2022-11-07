/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:48:16 by sroger            #+#    #+#             */
/*   Updated: 2022/11/07 13:23:09 by sroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

void	ft_bzero(void *ptr, size_t len)
{
	char	*str;

	str = ptr;
	while (len)
	{
		*str = '\0';
		str++;
		len--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(size * nmemb);
	if (!str)
	{
		return (NULL);
	}
	ft_bzero (str, (size * nmemb));
	return (str);
}

size_t	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		x;
	int		y;

	if (!s1 && !s2)
		return (NULL);
	x = 0;
	y = 0;
	str = malloc((ft_strlen((char *)s1)
				+ ft_strlen((char *)s2) + 1) * (sizeof(char)));
	if (str == NULL)
		return (0);
	while (s1[x] != '\0')
	{
		str[x + y] = s1[x];
		x++;
	}
	while (s2[y] != '\0')
	{
		str[x + y] = s2[y];
		y++;
	}
	str[x + y] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (char)c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return (str);
}
