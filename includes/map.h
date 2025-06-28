/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfernand <jfernand@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 09:31:13 by jfernand          #+#    #+#             */
/*   Updated: 2025/06/27 09:32:30 by jfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "game.h"

int		validate_map(t_game *game, char **argv);
void	parse_grid(int fd, t_game *game);
int		get_height(int fd);
int		check_outer_wall(char *line);
int		check_borders(char *line);
int		check_player(char *line, int y, t_game *game);
int		check_exit(char *line);
int		check_valid_chars(char *line);
int		check_collectibles(char *line);
int		check_shape(char **grid, t_game *game);
char	**copy_grid(char **grid, int height);
int		is_map_valid(t_game *game, const char *path);

#endif
