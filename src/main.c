/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:56:05 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/28 21:57:28 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/map.h"

int	has_ber_extension(char *filename)
{
	int	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}

void	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->width = 0;
	game->height = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->grid = NULL;
	game->items = 0;
	game->collected = 0;
	game->steps = 0;
	game->level_paths = NULL;
	game->current_level = 0;
	game->total_levels = 0;
	game->tile_size = 64;
	game->x_offset = 0;
	game->y_offset = 0;
	game->frame_counter = 0;
	game->frame_index = 0;
	game->move_cooldown = 0;
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
	{
		ft_printf("Usage: ./so_long [map.ber ...]\n");
		return (1);
	}
	game = malloc(sizeof(t_game));
	if (!game)
		return (1);
	init_game(game);
	game->total_levels = argc - 1;
	if (!validate_map(game, argv))
		return (1);
	run_game(game);
	free_game(game);
	return (0);
}
