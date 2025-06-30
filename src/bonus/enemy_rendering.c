/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:20:49 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 17:26:42 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enemy.h"

void	draw_enemy(t_game *game, t_enemy enemy)
{
	int		px;
	int		py;
	void	*sprite;

	py = game->y_offset + enemy.enemy_y * game->tile_size;
	px = game->x_offset + enemy.enemy_x * game->tile_size;
	sprite = game->textures.enemy[enemy.enemy_frame_index];
	if (sprite)
		mlx_put_image_to_window(game->mlx, game->win, sprite, px, py);
}

void	update_enemy_animation(t_enemy *enemy)
{
	enemy->enemy_frame_counter++;
	if (enemy->enemy_frame_counter >= FRAME_DELAY)
	{
		enemy->enemy_frame_counter = 0;
		enemy->enemy_frame_index = (enemy->enemy_frame_index + 1)
			% ENEMY_FRAMES;
	}
}
