/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 17:09:27 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:57:07 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/level_loader.h"
#include "../../includes/player.h"
#include "../../includes/render.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		close_win(game);
		exit(0);
	}
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		if (move_player(game, keycode))
		{
			change_dir(game, keycode);
			game->steps++;
			ft_printf("Steps: %d\n", game->steps);
			draw_map(game);		
		}
	return (0);
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


