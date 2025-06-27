/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:45:47 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/27 12:43:48 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <X11/X.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**grid;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		items;
	int		collected;
	int		steps;
	char	**level_paths;
	int		current_level;
	int		total_levels;
	int		tile_size;
}			t_game;

void	free_game(t_game *game);
void	run_game(t_game *game);

#endif
