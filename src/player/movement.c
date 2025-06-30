/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:02:41 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 17:00:13 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/player.h"

void	update_tile(t_game *game, int y, int x)
{
	game->grid[game->player_y][game->player_x] = '0';
	game->grid[y][x] = 'P';
	game->player_y = y;
	game->player_x = x;
}

void	update_cooldown(t_game *game)
{
	if (game->move_cooldown > -1)
		game->move_cooldown--;
}

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

int	move_player(t_game *game, int keycode)
{
	int	p_y;
	int	p_x;

	if (game->move_cooldown > 0)
		return (0);
	p_y = game->player_y;
	p_x = game->player_x;
	if (keycode == 119)
		p_y -= 1;
	else if (keycode == 115)
		p_y += 1;
	else if (keycode == 97)
		p_x -= 1;
	else if (keycode == 100)
		p_x += 1;
	if (game->grid[p_y][p_x] == '1')
		return (0);
	if (game->grid[p_y][p_x] == 'C')
		game->collected += 1;
	if (game->grid[p_y][p_x] == 'E')
		if (!handle_exit(game))
			return (0);
	update_tile(game, p_y, p_x);
	game->move_cooldown = MOVE_COOLDOWN_FRAMES;
	return (1);
}
