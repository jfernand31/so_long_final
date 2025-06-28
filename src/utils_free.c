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

void	free_grid(char **grid, int height)
{
	int	i;

	if (!grid)
		return ;
	i = -1;
	while (++i < height)
	{
		if (grid[i])
			free(grid[i]);
	}
	free(grid);
}

void	free_str_array(char **arr, int count)
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
	free(game);
}
