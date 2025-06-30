/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 08:45:47 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/30 16:44:35 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <X11/X.h>
# include <stdio.h>

# define WINDOW_WIDTH  1920
# define WINDOW_HEIGHT 1080
# define FRAME_DELAY 200
# define WALK_FRAMES 2
# define MOVE_COOLDOWN_FRAMES 40

typedef enum e_direction
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT,
}	t_direction;

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*player[4][WALK_FRAMES];
	void	*exit;
	void	*items;
}			t_textures;

typedef struct s_game
{
	t_direction		dir;
	int				x_offset;
	int				y_offset;
	void			*mlx;
	void			*win;
	char			**grid;
	int				width;
	int				height;
	int				player_x;
	int				player_y;
	int				items;
	int				collected;
	int				steps;
	char			**level_paths;
	int				current_level;
	int				total_levels;
	int				tile_size;
	t_textures		textures;
	int				frame_index;
	int				frame_counter;
	int				move_cooldown;
}					t_game;

int		key_press(int keycode, t_game *game);
void	handle_exit_event(t_game *game);
int		close_win(t_game *game);
int		handle_exit(t_game *game);
int		game_loop(t_game *game);
void	free_grid(char **grid, int height);
void	free_game(t_game *game);
int		run_game(t_game *game);

#endif
