/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 19:46:07 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/27 19:50:02 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	center_map(t_game *game)
{
    int	map_w_px = game->width * game->tile_size;
    int	map_h_px = game->height * game->tile_size;

    game->x_offset = (WINDOW_WIDTH  - map_w_px) / 2;
    game->y_offset = (WINDOW_HEIGHT - map_h_px) / 2;

    if (game->x_offset < 0)
        game->x_offset = 0;
    if (game->y_offset < 0)
        game->y_offset = 0;
}

static void	free_textures(t_game *game)
{
	if (game->textures.wall)
		mlx_destroy_image(game->mlx, game->textures.wall);
	if (game->textures.floor)
		mlx_destroy_image(game->mlx, game->textures.floor);
	if (game->textures.player)
		mlx_destroy_image(game->mlx, game->textures.player);
	if (game->textures.items)
		mlx_destroy_image(game->mlx, game->textures.items);
	if (game->textures.exit)
		mlx_destroy_image(game->mlx, game->textures.exit);
}

int	load_textures(t_game *game)
{
	int	width;
	int	height;

	game->textures.wall = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/wall.xpm", &width, &height);
	game->textures.floor = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/floor.xpm", &width, &height);
	game->textures.player = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/player.xpm", &width, &height);
	game->textures.items = mlx_xpm_file_to_image(game->mlx,
			"assets/sprites/items.xpm", &width, &height);
	game->textures.exit = mlx_xpm_file_to_image(game->mlx,
			"assets/textures/exit.xpm", &width, &height);
	if (!game->textures.wall || !game->textures.floor
			|| !game->textures.player || !game->textures.items
			|| !game->textures.exit)
	{
		free_textures(game);
		return (0);
	}
	return (1);
}

void draw_tile(t_game *game, char tile, int x, int y)
{
    int px = game->x_offset + x * game->tile_size;
    int py = game->y_offset + y * game->tile_size;

    if (tile == '1')
        mlx_put_image_to_window(game->mlx, game->win,
            game->textures.wall, px, py);
    else if (tile == '0')
        mlx_put_image_to_window(game->mlx, game->win,
            game->textures.floor, px, py);
    else if (tile == 'P')
        mlx_put_image_to_window(game->mlx, game->win,
            game->textures.player, px, py);
    else if (tile == 'C')
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
}
