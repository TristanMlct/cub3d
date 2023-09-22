/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:10:20 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/23 01:04:55 by tmilcent         ###   ########.fr       */
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
}				t_map;

// src/parsing/arg_handler.c
int		is_arg_valid(int argc, char **argv);

// src/parsing/analyse_file.c
int		parse_file(char *path, t_settings *settings);

// src/parsing/analyse_line.c
int		is_valid_map_line(char *line);
int		is_map_last(char *line, t_settings *settings);
int		is_settings(char *line);
int		is_empty_line(char *line);

// src/parsing/utils.c
void	init_map(t_settings *settings);

// src/parsing/textures.c
void	feed_settings_textures(t_settings *settings, char *line);
int		verify_textures(t_settings *settings);

// src/parsing/colors.c
void	feed_settings_colors(t_settings *settings, char *line);
int		verify_colors(t_settings *settings);

// src/parsing/map.c
int		feed_settings_map(t_settings *settings, char *line);
// int		verify_map(t_settings *settings);


#endif