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
#include "../../includes/map.h"

void	update_tile(t_game *game, int y, int x)
{
	game->grid[game->player_y][game->player_x] = '0';
	game->grid[y][x] = 'P';
	game->player_y = y;
	game->player_x = x;
}

int	move_player(t_game *game, int keycode)
{
	int	p_y;
	int	p_x;

	if (game->move_cooldown > 0)
        return 0;  // still cooling down, ignore move
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

int	key_press(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		close_win(game);
		exit(0);
	}
	if (keycode == 119 || keycode == 97 || keycode == 115 || keycode == 100)
		if (move_player(game, keycode))
		{
			change_dir(game, keycode);
			game->steps++;
			ft_printf("Steps: %d\n", game->steps);
			draw_map(game);		
		}
	return (0);
}

int	run_game(t_game *game)
{	
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	if (!load_textures(game))
	{
		ft_printf("Failed to load textures\n");
		return (0);
	}
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			"So Long");
	game->items = 0;
	if (!is_map_valid(game, game->level_paths[game->current_level]))
			return (0);
	center_map(game);
	ft_printf("Loaded level %d\n", game->current_level + 1);
	draw_map(game);
	mlx_loop_hook(game->mlx, game_loop, game);
	mlx_hook(game->win, 2, 1L << 0, key_press, game);
	mlx_hook(game->win, 17, 0, close_win, game);
	mlx_loop(game->mlx);
	return (1);
}
