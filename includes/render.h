/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:44:27 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 21:41:06 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "game.h"
# include "map.h"

void	center_map(t_game *game);
void	free_textures(t_game *game);
void	draw_player(t_game *game, int y, int x);
void	update_animation(t_game *game);
int		load_textures(t_game *game);
void	draw_map(t_game *game);
void	draw_tile(t_game *game, char tile, int x, int y);

#endif
