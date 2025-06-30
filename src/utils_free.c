/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:04:46 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:56:09 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/render.h"

void	free_textures(t_game *game)
{
	int	i;
	int	j;

	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 2)
		{
			if (game->textures.player[i][j])
				mlx_destroy_image(game->mlx, game->textures.player[i][j]);
		}
	}
	if (game->textures.items)
			mlx_destroy_image(game->mlx, game->textures.items);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
}

void	free_grid(char **grid, int height)
{
	int	i;

	if (!grid)
		return ;
	i = -1;
	while (++i < height)
	{
		if (grid[i])
		{
			free(grid[i]);
			grid[i] = NULL;
		}
	}
	free(grid);
	grid = NULL;
}

static void	free_str_array(char **arr, int count)
{
	int	i;

	if (!arr)
		return ;
	for (i = 0; i < count; i++)
	{
		if (arr[i])
			free(arr[i]);
	}
	free(arr);
}

void	free_game(t_game *game)
{
	if (!game)
		return ;
	free_grid(game->grid, game->height);
	free_str_array(game->level_paths, game->total_levels);
	game->level_paths = NULL;
	free(game);
}
