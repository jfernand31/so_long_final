/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:17:53 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/29 16:19:21 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/map.h"

void	change_dir(t_game *game, int keycode)
{
	if (keycode == 119)
		game->dir = DIR_UP;
	else if (keycode == 115)
		game->dir = DIR_DOWN;
	else if (keycode == 97)
		game->dir = DIR_LEFT;
	else if (keycode == 100)
		game->dir = DIR_RIGHT;
}

void	update_animation(t_game *game)
{
	game->frame_counter++;
	if (game->frame_counter >= FRAME_DELAY)
	{
		game->frame_counter = 0;
		game->frame_index = (game->frame_index + 1) % WALK_FRAMES;
	}
}

