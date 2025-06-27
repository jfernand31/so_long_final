/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:40:29 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/27 12:45:12 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/game.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	ft_printf("Key pressed: %d\n", keycode);
    if (keycode == 65307) // Escape key
	{
		close_win(game);
		exit(0);
	}
	return (0);
}

void	run_game(t_game *game)
{
	t_data	img;
	int	x;
	int	y;
	int	color;
	int	i;

	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, (game->width * game->tile_size), (game->height * game->tile_size), game->level_paths[game->current_level]);
	img.img = mlx_new_image(game->mlx, (game->width * game->tile_size), (game->height * game->tile_size));
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	color = create_trgb(0, 0xFF, 0xC0, 0xCB);
	i = 1;
	y  = 10;
	while (y < 100)
	{
		x = 10;
		while (x < 100)
		{
			my_mlx_pixel_put(&img, x, y, (color));
			x++;
			i++;
		}
		y++;
	
    }
	mlx_key_hook(game->win, key_press, game);
	mlx_put_image_to_window(game->mlx, game->win, img.img, 0, 0);
	mlx_hook(game->win, 17, 0, close_win, game);
	mlx_loop(game->mlx);
}
