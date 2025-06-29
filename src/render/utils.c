/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:18:29 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/28 18:19:20 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	load_animation(t_game *game, t_direction dir, int w, int h)
{
	if (dir == DIR_LEFT)
	{
		game->textures.player[DIR_LEFT][0] = mlx_xpm_file_to_image(game->mlx,
    		"assets/sprites/player_left_1.xpm", &w, &h);
		game->textures.player[DIR_LEFT][1] = mlx_xpm_file_to_image(game->mlx,
    		"assets/sprites/player_left_2.xpm", &w, &h);
	}
	if (dir == DIR_RIGHT)
	{
		game->textures.player[DIR_RIGHT][0] = mlx_xpm_file_to_image(game->mlx,
    		"assets/sprites/player_right_1.xpm", &w, &h);
		game->textures.player[DIR_RIGHT][1] = mlx_xpm_file_to_image(game->mlx,
    		"assets/sprites/player_right_2.xpm", &w, &h);
	}
	if (dir == DIR_UP)
	{
		game->textures.player[DIR_UP][0] = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/player_up_1.xpm", &w, &h);
		game->textures.player[DIR_UP][1] = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/player_up_2.xpm", &w, &h);
	}
	if (dir == DIR_DOWN)
	{
		game->textures.player[DIR_DOWN][0] = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/player_down_1.xpm", &w, &h);
		game->textures.player[DIR_DOWN][1] = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/player_down_2.xpm", &w, &h);
	}
}

int	load_player(t_game *game, int w, int h)
{
	int	i;
	int	j;

	load_animation(game, DIR_LEFT, w, h);
	load_animation(game, DIR_DOWN, w, h);
	load_animation(game, DIR_RIGHT, w, h);
	load_animation(game, DIR_UP, w, h);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 2)
		if (!game->textures.player[i][j])
		{
			free_textures(game);
			return (0);
		}
	}
	return (1);
}

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/wall.xpm", &width, &height);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/floor.xpm", &width, &height);
	game->textures.items = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/items.xpm", &width, &height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/exit.xpm", &width, &height);
	if (!load_player(game, width, height))
		return (0);
	if (!game->textures.wall || !game->textures.floor
			|| !game->textures.items || !game->textures.exit)
	{
		free_textures(game);
		return (0);
	}
	return (1);
}

