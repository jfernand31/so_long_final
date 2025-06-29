/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:59:43 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/29 14:33:08 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_store(int fd, char *leftover, char *buffer);
char	*update_leftover(char *line);
char	*extract_line(char *str);

char	*get_next_line(int fd)
{
	char			*buffer;
	static char		*leftover;
	char			*line;
	char			*temp;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(leftover);
		free(buffer);
		leftover = NULL;
		buffer = NULL;
		return (NULL);
	}
	leftover = read_and_store(fd, leftover, buffer);
	if (!leftover)
		return (free(buffer), NULL);
	free (buffer);
	line = extract_line(leftover);
	temp = leftover;
	leftover = update_leftover(temp);
	free (temp);
	return (line);
}

char	*read_and_store(int fd, char *leftover, char *buffer)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(leftover);
			return (NULL);
		}
		else if (bytes == 0)
			break ;
		buffer[bytes] = '\0';
		if (!leftover)
			leftover = ft_strduplicate("");
		tmp = leftover;
		leftover = ft_joinstr(tmp, buffer);
		free(tmp);
		if (ft_strchar(buffer, '\n'))
			break ;
	}
	return (leftover);
}

char	*update_leftover(char *line)
{
	size_t	i;
	char	*new_leftover;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	new_leftover = ft_get_substr(line, i + 1, ft_strlength(line) - (i + 1));
	if (!new_leftover || *new_leftover == '\0')
	{
		free(new_leftover);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (new_leftover);
}

char	*extract_line(char *str)
{
	size_t	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (ft_get_substr(str, 0, i));
}
