/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:09:47 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:57:01 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"
#include "../../includes/render.h"
#include "../../includes/player.h"

int	game_loop(t_game *game)
{
	update_animation(game);
	update_cooldown(game);
	draw_map(game);
	return (0);
}
