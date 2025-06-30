/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 21:40:14 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 21:40:33 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_H
# define ENEMY_H
# include "game.h"

void	move_enemy(t_game *game, t_enemy *enemy);
void	draw_enemy(t_game *game, t_enemy enemy);
void	update_enemy_animation(t_enemy *enemy);

#endif
