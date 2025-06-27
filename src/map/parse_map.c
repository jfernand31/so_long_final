/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:12:16 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/27 11:12:45 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

int	get_height(int fd)
{
	int		height;
	char	*line;

	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	return (height);
}

void	remove_newline(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return ;
	while (str[len])
		len++;
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
}

void	parse_grid(int fd, t_game *game)
{
	char	*line;
	int		i;

	i = -1;
	game->grid = malloc(sizeof(char *) * (game->height + 1));
	if (!game->grid)
		return ;
	while (++i < game->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		remove_newline(line);
		game->grid[i] = ft_strdup(line);
		free(line);
	}
	game->grid[i] = NULL;
}
