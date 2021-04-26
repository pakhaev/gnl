/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvoltigo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:08:55 by rvoltigo          #+#    #+#             */
/*   Updated: 2020/11/22 15:11:30 by rvoltigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)dest)[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}

char	*ft_processing(int fd, char *str, char *buf)
{
	int res;

	res = 1;
	while (res != 0 && !ft_returning(str))
	{
		if ((res = read(fd, buf, BUFFER_SIZE)) == -1)
		{
			free(buf);
			return ((char*)-1);
		}
		buf[res] = '\0';
		str = ft_strjoin(str, buf);
	}
	free(buf);
	if (!str)
		return (NULL);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			res;
	char		*buf;
	static char	*str[1024];

	res = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ft_memset(buf, '\0', BUFFER_SIZE + 1);
	str[fd] = ft_processing(fd, str[fd], buf);
	if (str[fd] == (char*)-1)
		return (-1);
	*line = ft_gnldup(str[fd]);
	str[fd] = ft_strdup(str[fd]);
	if (!str[fd])
	{
		free(str[fd]);
		return (0);
	}
	return (1);
}
