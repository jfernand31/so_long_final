/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:46:07 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:56:21 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/render.h"
#include "../../includes/enemy.h"

void	center_map(t_game *game)
{
	int	map_w_px;
	int	map_h_px;

	map_w_px = game->width * game->tile_size;
	map_h_px = game->height * game->tile_size;
	game->x_offset = (WINDOW_WIDTH - map_w_px) / 2;
	game->y_offset = (WINDOW_HEIGHT - map_h_px) / 2;
	if (game->x_offset < 0)
		game->x_offset = 0;
	if (game->y_offset < 0)
		game->y_offset = 0;
}

void	draw_tile(t_game *game, char tile, int x, int y)
{
	int		px;
	int		py;

	px = game->x_offset + x * game->tile_size;
	py = game->y_offset + y * game->tile_size;
	if (tile == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.wall, px, py);
		return ;
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->textures.floor, px, py);
	if (tile == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.items, px, py);
	else if (tile == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->textures.exit, px, py);
}

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;
	char	msg[32];

	mlx_clear_window(game->mlx, game->win);
	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			tile = game->grid[y][x];
			draw_tile(game, tile, x, y);
		}
	}
	if (game->enemy_count > 0)
		draw_enemy(game, game->enemies);
	draw_player(game,
		game->y_offset + game->player_y * game->tile_size,
		game->x_offset + game->player_x * game->tile_size);
	snprintf(msg, sizeof(msg), "Steps: %d", game->steps);
	mlx_string_put(game->mlx, game->win, 10, 10, 0xFFFFFF, msg);
}
