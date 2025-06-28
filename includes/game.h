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

# define WINDOW_WIDTH  1920
# define WINDOW_HEIGHT 1080

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*items;
}			t_textures;

typedef struct s_game
{
	int			x_offset;
	int			y_offset;
	void		*mlx;
	void		*win;
	char		**grid;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			items;
	int			collected;
	int			steps;
	char		**level_paths;
	int			current_level;
	int			total_levels;
	int			tile_size;
	t_textures	textures;
}				t_game;

void	handle_exit_event(t_game *game);
int		has_ber_extension(char *filename);
void	free_grid(char **grid, int height);
void	free_game(t_game *game);
int		run_game(t_game *game);
int		load_textures(t_game *game);
void	draw_map(t_game *game);
int		close_win(t_game *game);
void	center_map(t_game *game);

#endif
