/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 16:05:52 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:56:57 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/level_loader.h"
#include "../../includes/map.h"
#include "../../includes/render.h"

void	load_new_level(t_game *game)
{
	game->collected = 0;
	game->items = 0;
	game->enemy_count = 0;
	if (!is_map_valid(game, game->level_paths[game->current_level]))
	{
		ft_printf("Error loading level %d\n", game->current_level);
		close_win(game);
		exit(1);
	}
	center_map(game);
	ft_printf("Loaded level %d\n", game->current_level + 1);
	return ;
}
