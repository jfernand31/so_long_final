/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 17:04:45 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 17:08:04 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/enemy.h"

void	check_if_hit(t_game *game, t_enemy *enemy)
{
	if (enemy->enemy_x == game->player_x && enemy->enemy_y == game->player_y)
	{
		ft_printf("GAME OVER\n");
		close_win(game);
	}
}

void	where_is_player(t_game *game, t_enemy *enemy, int *x, int *y)
{
	if (enemy->enemy_x < game->player_x)
		*x = 1;
	else if (enemy->enemy_x > game->player_x)
		*x = -1;
	if (enemy->enemy_y < game->player_y)
		*y = 1;
	else if (enemy->enemy_y > game->player_y)
		*y = -1;
}

void	move_enemy(t_game *game, t_enemy *enemy)
{
	int	dx;
	int	dy;
	int	new_x;
	int	new_y;

	dx = 0;
	dy = 0;
	if (enemy->move_cooldown > 0)
	{
		enemy->move_cooldown--;
		return ;
	}
	where_is_player(game, enemy, &dx, &dy);
	new_x = enemy->enemy_x + dx;
	new_y = enemy->enemy_y + dy;
	if (game->grid[new_y][new_x] != '1' && game->grid[new_y][new_x] != 'E')
	{
		enemy->enemy_x = new_x;
		enemy->enemy_y = new_y;
		enemy->move_cooldown = 500;
	}
}
