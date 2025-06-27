/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 09:38:10 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/27 12:16:10 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

static int	check_map_format(char **grid, t_game *game)
{
	int	y;
	int	exits;
	int	player;

	y = -1;
	exits = 0;
	player = 0;
	while (grid[++y])
	{
		if (y == 0 || grid[y + 1] == NULL)
			if (!check_outer_wall(grid[y]))
				return (0);
		exits += check_exit(grid[y]);
		player += check_player(grid[y], y, game);
		game->items += check_collectibles(grid[y]);
		if (!check_valid_chars(grid[y]) || !check_borders(grid[y]))
			return (0);
	}
	if (player != 1 || exits < 1 || game->items < 1 || !check_shape(grid, game))
		return (0);
	return (1);
}

static int	is_map_valid(t_game *game, const char *path)
{
	int		fd;
	int		valid;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	game->height = get_height(fd);
	close(fd);
	fd = open(path, O_RDONLY);
	parse_grid(fd, game);
	close(fd);
	if(!game->grid)
		return (0);
	valid = check_map_format(game->grid, game);
	return (valid);
}	

int	validate_map(t_game *game, char **argv)
{
	int	i;

	if (!game)
		return (0);
	game->level_paths = malloc(sizeof(char *) * game->total_levels);
	i = -1;
	while (++i < game->total_levels)
	{
		if (is_map_valid(game, argv[i + 1]))
			game->level_paths[i] = ft_strdup(argv[i + 1]);
		else
		{
			ft_printf("Error: invalid map %s\n", argv[i + 1]);
			return (0);
		}
	}
	return (1);
}

