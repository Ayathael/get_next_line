/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroger <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:06:01 by sroger            #+#    #+#             */
/*   Updated: 2022/11/07 13:16:50 by sroger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

char	*ft_free(char *chainebuffer, char *buff)
{
	char	*chainetemporaire;

	chainetemporaire = ft_strjoin(chainebuffer, buff);
	free (chainebuffer);
	return (chainetemporaire);
}

char	*ft_next(char *chainebuffer)
{
	int		x;
	int		y;
	char	*str;

	x = 0;
	while (chainebuffer[x] != '\0' && chainebuffer[x] != '\n')
		x++;
	if (!chainebuffer[x])
	{
		free(chainebuffer);
		return (NULL);
	}
	str = ft_calloc((ft_strlen(chainebuffer) - x +1), sizeof(char));
	if (!str)
		return (NULL);
	x++;
	y = 0;
	while (chainebuffer[x] != '\0')
	{
		str[y] = chainebuffer[x];
		x++;
		y++;
	}
	free(chainebuffer);
	return (str);
}

char	*ft_line(char *chainebuffer)
{
	int		x;
	char	*str;

	x = 0;
	if (!chainebuffer[x])
		return (NULL);
	while (chainebuffer[x] != '\0' && chainebuffer[x] != '\n')
	{
		x++;
	}
	str = ft_calloc(x +2, sizeof(char));
	if (!str)
		return (NULL);
	x = 0;
	while (chainebuffer[x] != '\0' && chainebuffer[x] != '\n')
	{
		str[x] = chainebuffer[x];
		x++;
	}
	if (chainebuffer[x] != '\0' && chainebuffer[x] == '\n')
	{
		str[x] = '\n';
		x++;
	}
	return (str);
}

char	*read_file(int fd, char *result)
{
	char	*chainebuffer;
	int		isfonctionreadok;

	if (!result)
		result = ft_calloc(1, 1);
	chainebuffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!chainebuffer)
		return (NULL);
	isfonctionreadok = 1;
	while (isfonctionreadok > 0)
	{
		isfonctionreadok = read(fd, chainebuffer, BUFFER_SIZE);
		if (isfonctionreadok == -1)
		{
			free(chainebuffer);
			return (NULL);
		}
		chainebuffer[isfonctionreadok] = 0;
		result = ft_free(result, chainebuffer);
		if (ft_strchr(chainebuffer, '\n'))
			break ;
	}
	free(chainebuffer);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*chainebuffer[OPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		return (NULL);
	}
	chainebuffer[fd] = read_file(fd, chainebuffer[fd]);
	if (!chainebuffer[fd])
		return (NULL);
	line = ft_line(chainebuffer[fd]);
	chainebuffer[fd] = ft_next(chainebuffer[fd]);
	return (line);
}
/*
int    main(void)
{
    int fd = open("message.txt", O_RDONLY);
    if (fd == -1)
    {
    printf("error with opening of file\n");
    }
    printf("%s",get_next_line(fd));
}
*/
