/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:09:27 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/28 17:10:48 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/map.h"

void	load_new_level(t_game *game)
{
	game->collected = 0;
	game->items = 0;
	if (!is_map_valid(game, game->level_paths[game->current_level]))
	{
    	ft_printf("Error loading level %d\n", game->current_level);
    	close_win(game);
    	exit(1);
	}
	center_map(game);
	ft_printf("Loaded level %d\n", game->current_level + 1);
	return ;
}


void handle_exit_event(t_game *game)
{
    if (game->current_level + 1 < game->total_levels)
    {
		game->steps++;
        game->current_level++;
        load_new_level(game);
        draw_map(game);
    }
    else
    {
		game->steps++;
        ft_printf("Congratulations! You completed all levels.\n");
        close_win(game);
        exit(0);
    }
}

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	handle_exit(t_game *game)
{
	if (game->collected == game->items)
		handle_exit_event(game);
	return (0);
}

int	game_loop(t_game *game)
{
	update_animation(game);
	draw_map(game);
	return (0);
}
