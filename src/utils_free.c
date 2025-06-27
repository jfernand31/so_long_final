/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:04:46 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/27 10:20:16 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void free_grid(char **grid, int height)
{
    int i;

    if (!grid)
		return;
	i = -1;
    while (++i < height)
        free(grid[i]);
    free(grid);
}

void free_level_paths(char **paths, int total_levels)
{
    int i;

    if (!paths)
		return ;
	i = -1;
    while (++i < total_levels)
        free(paths[i]);
    free(paths);
}

void free_game(t_game *game)
{
    if (!game)
        return ;
    free_grid(game->grid, game->height);
    free_level_paths(game->level_paths, game->total_levels);
    // If you have other allocated resources (images, mlx, etc.), free here

    free(game);
}


