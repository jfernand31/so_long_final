/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:12:16 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:56:47 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

int	has_ber_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

static void	remove_newline(char *str)
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
		game->grid[i] = NULL;
	i = -1;
	while (++i < game->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		remove_newline(line);
		game->grid[i] = ft_strdup(line);
		if (!game->grid[i])
			break;
		free(line);
	}
	game->grid[i] = NULL;
	game->height = i;
}
