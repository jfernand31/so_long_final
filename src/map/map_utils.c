/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:33:32 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/27 11:41:08 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

int	check_outer_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	check_borders(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (i == 0 && line[i] != '1')
			return (0);
		i++;
	}
	if (line[i - 1] != '1')
		return (0);
	return (1);
}

int	check_player(char *line, int y, t_game *game)
{
	int	i;
	int	player;

	i = 0;
	player = 0;
	while (line[i])
	{
		if (line[i] == 'P')
		{
			game->player_x = i;
			game->player_y = y;
			player++;
		}
		i++;
	}
	return (player);
}

int	check_exit(char *line)
{
	int	i;
	int	exits;

	i = 0;
	exits = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			exits++;
		i++;
	}
	return (exits);
}

int	check_valid_chars(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == 'P' || line[i] == 'E' || line[i] == '1'
				|| line[i] == '0' || line[i] == 'C'))
			return (0);
		i++;
	}
	return (1);
}
