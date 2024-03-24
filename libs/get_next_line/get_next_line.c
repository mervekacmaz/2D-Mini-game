/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:21:48 by mkacmaz           #+#    #+#             */
/*   Updated: 2022/06/30 17:21:52 by mkacmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_line(char *s)
{
	char	*dest;

	dest = ft_strchr(s, '\n');
	if (!dest)
	{
		free(s);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup(dest + 1);
	else
		dest = NULL;
	free(s);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*dest;
	char		*buffer;
	int			size;

	buffer = malloc(BUFFER_SIZE + 1);
	size = read(fd, buffer, BUFFER_SIZE);
	buffer[size] = 0;
	while (size > 0)
	{
		if (!s)
			s = ft_strdup(buffer);
		else
			s = ft_strjoin(s, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		size = read (fd, buffer, BUFFER_SIZE);
		buffer [size] = 0;
	}
	dest = ft_substr(s, 0, ft_strchr(s, '\n') - s + 1);
	s = move_line(s);
	free(buffer);
	return (dest);
}
