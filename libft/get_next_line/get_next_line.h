/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 10:23:06 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/29 14:33:08 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
char	*ft_joinstr(char const *s1, char const *s2);
char	*ft_strduplicate(const char *s);
char	*ft_strchar(const char *s, int c);
size_t	ft_strlength(const char *str);
char	*ft_get_substr(char *s, unsigned int start, size_t len);

#endif