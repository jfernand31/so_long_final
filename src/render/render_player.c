/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:17:53 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:56:19 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"

void	update_animation(t_game *game)
{
	game->frame_counter++;
	if (game->frame_counter >= FRAME_DELAY)
	{
		game->frame_counter = 0;
		game->frame_index = (game->frame_index + 1) % WALK_FRAMES;
	}
}

void	draw_player(t_game *game, int y, int x)
{
	int		frame;
	void	*sprite;

	frame = game->frame_index;
	sprite = game->textures.player[game->dir][frame];
	if (!sprite)
		return ;
	mlx_put_image_to_window(game->mlx, game->win, sprite, x, y);
}
