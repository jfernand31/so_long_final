/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:14:43 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:34:23 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# include "game.h"

void	update_tile(t_game *game, int y, int x);
void	update_cooldown(t_game *game);
int		move_player(t_game *game, int keycode);

#endif
