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

void	flood_fill(char **grid, int x, int y)
{
	if (grid[y][x] == '1' || grid[y][x] == 'V')
		return ;
	grid[y][x] = 'V';
	flood_fill(grid, x + 1, y);
	flood_fill(grid, x - 1, y);
	flood_fill(grid, x, y + 1);
	flood_fill(grid, x, y - 1);
}

int	check_path(char **grid, t_game *game)
{
	char	**temp;
	int		i;
	int		j;

	temp = copy_grid(grid, game->height);
	if (!temp)
		return (0);
	flood_fill(temp, game->player_x, game->player_y);
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (temp[i][++j])
		{
			if (temp[i][j] != '1' && temp[i][j] != 'V' && temp[i][j] != '0')
			{
				free_grid(temp, game->height);
				return (0);
			}
		}
	}
	free_grid(temp, game->height);
	return (1);
}

static int	check_map_format(char **grid, t_game *game)
{
	int	y;
	int	exits;
	int	player;

	y = -1;
	exits = 0;
	player = 0;
	if (game->items > 0)
		game->items = 0;
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

int	is_map_valid(t_game *game, const char *path)
{
	int		fd;
	
	if (game->grid)
		free_grid(game->grid, game->height);
	game->grid  = NULL;
	game->height = get_height(path);
	fd = open(path, O_RDONLY);
	parse_grid(fd, game);
	close(fd);
	if (!game->grid)
		return (0);
	if (!check_map_format(game->grid, game))
		return (0);
	if (!check_path(game->grid, game))
		return (0);
	return (1);
}

int	validate_map(t_game *game, char **argv)
{
	int	i;

	if (!game)
		return (0);
	game->level_paths = ft_calloc(game->total_levels, sizeof *game->level_paths);
	if (!game->level_paths)
		return (0);
	i = -1;
	while (++i < game->total_levels)
	{
		if (!has_ber_extension(argv[i + 1]))
		{
			ft_printf("Error: map %s needs to have .ber extension\n", argv[i + 1]);
			free_game(game);
			return (0);
		}
		if (!is_map_valid(game, argv[i + 1]))
		{
			ft_printf("Error: invalid map %s\n", argv[i + 1]);
			free_game(game);
			return (0);
		}
		game->level_paths[i] = ft_strdup(argv[i + 1]);
	}
	return (1);
}
