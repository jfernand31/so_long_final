/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:40:29 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:57:04 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/map.h"
#include "../../includes/render.h"

int	run_game(t_game *game)
{	
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	if (!load_textures(game))
	{
		ft_printf("Failed to load textures\n");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"So Long");
	game->items = 0;
	if (!is_map_valid(game, game->level_paths[game->current_level]))
			return (0);
	center_map(game);
	ft_printf("Loaded level %d\n", game->current_level + 1);
	draw_map(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 0, close_win, game);
	mlx_loop(game->mlx);
	return (1);
}
