/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:10:20 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/24 17:29:03 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define PI 3.14159265358979323846

# define SPEED 0.1
# define ROT_SPEED 0.1

# define FOV 60

# define TILE_SIZE 64

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

typedef struct s_map	t_map;

typedef struct s_settings
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		*f;
	int		*c;
	t_map	*map;
}				t_settings;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
	int		start_line;
	int		end_line;
	char	player;
	int		pos_x;
	int		pos_y;
}				t_map;

// src/parsing/arg_handler.c
int		is_arg_valid(int argc, char **argv);

// src/parsing/analyse_file.c
int		parse_file(char *path, t_settings *settings);

// src/parsing/analyse_line.c
int		is_valid_map_line(char *line);
int		is_map_last(t_settings *settings);
int		is_element(char *line);
int		is_empty_line(char *line);
void	feed_elements(t_settings *settings, char *line);

// src/parsing/utils.c
void	map_to_null(t_settings *settings);
void	settings_to_null(t_settings *settings);
int		free_settings(t_settings *settings);
int		exit_error(t_settings *settings);

// src/parsing/textures.c
int		is_valid_texture(char *line);
char	*get_path(char *texture_line);

// src/parsing/colors.c
int		is_valid_color(char *line);
int		*get_color(char *color_line);

// src/parsing/map.c
int		feed_map_settings(t_settings *settings, char *line, int line_nb);
int		init_map(char *path, t_settings *settings);

// src/parsing/map2.c
int		is_map_valid(t_settings *settings);

#endif