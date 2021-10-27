/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcrius <kcrius@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:07:08 by kcrius            #+#    #+#             */
/*   Updated: 2021/10/27 20:28:11 by kcrius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if ((char)c == s[i])
		return ((char *) s + i);
	else
		return (NULL);
}

void	ft_get_remain(char **remain, unsigned int i, char const *s)
{
	unsigned int	j;

	j = 0;
	remain = malloc(ft_strlen(&s[i]));
	while (s[i])
	{
		remain[j++] = s[i++];
	}
}

char	*ft_strjoin(char const *s1, char const *s2, char **remain)
{
	char			*conc;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = ft_strlen(s1) + ft_strlen(s2);
	conc = malloc(i);
	if (!(conc))
		return (NULL);
	i = 0;
	while (s1[i])
		conc[j++] = s1[i++];
	i = 0;
	while (s2[i] && s2[i] != '\n')
		conc[j++] = s2[i++];
	if (s2[i] == '\n')
	{
		conc[j++] = s2[i++];
		ft_get_remain(remain, i, s2);
	}
	conc[j] = '\0';
	return (conc);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		++i;
	return (i);
}

char	*get_next_line(int fd)
{
	int			readed;
	char		buffer[50 + 1];
	char		*line;
	static char	*remain;

	line = "";
	while (!ft_strchr(buffer, '\n'))
	{
		readed = read(fd, buffer, 10);
		if (readed == 0)
			return (NULL);
		buffer[readed] = '\0';
		line = ft_strjoin(line, buffer);
	}
	return (line);
}

int	main(void)
{
	int	fd;

	fd = open("text.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
