/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_more_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:44:26 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:56:51 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"
#include <fcntl.h>

int	get_height(const char *path)
{
	int		height;
	char	*line;
	int		fd;

	height = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	ft_strlen_nobrk(const char *s)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

int	check_collectibles(char *line)
{
	int	i;
	int	items;

	i = 0;
	items = 0;
	while (line[i])
	{
		if (line[i] == 'C')
			items++;
		i++;
	}
	return (items);
}

int	check_shape(char **grid, t_game *game)
{
	int	len;
	int	curr_len;
	int	y;

	if (!grid || !grid[0])
		return (0);
	y = 1;
	len = ft_strlen_nobrk(grid[0]);
	while (grid[y])
	{
		curr_len = ft_strlen_nobrk(grid[y]);
		if (curr_len != len)
			return (0);
		y++;
	}
	game->width = len;
	return (1);
}

char	**copy_grid(char **grid, int height)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = -1;
	while (++i < height)
	{
		copy[i] = ft_strdup(grid[i]);
		if (!copy[i])
		{
			free_grid(copy, i);
			return (NULL);
		}
	}
	copy[height] = NULL;
	return (copy);
}
