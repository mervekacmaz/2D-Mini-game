/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkacmaz <42istanbul.com.tr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:22:01 by mkacmaz           #+#    #+#             */
/*   Updated: 2022/06/30 17:22:03 by mkacmaz          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 999
# endif

char    *ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);

#endif
