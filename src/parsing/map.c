/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:57:48 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/25 16:17:57 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	feed_map_settings(t_settings *settings, char *line, int line_nb)
{
	int		i;
	char	*tmp;

	tmp = ft_strtrim_right(line, " \n");
	i = -1;
	while (tmp[++i])
	{
		if ((tmp[i] == 'N' || tmp[i] == 'S' || tmp[i] == 'W' \
			|| tmp[i] == 'E') && !settings->map->player)
		{
			settings->map->player = tmp[i];
			settings->map->pos_x = i;
			settings->map->pos_y = line_nb - settings->map->start_line;
		}
		else if (tmp[i] != '1' && tmp[i] != '0' && tmp[i] != ' ')
		{
			free(tmp);
			return (1);
		}
	}
	if (i > settings->map->width)
		settings->map->width = i;
	free(tmp);
	return (0);
}

static void	free_map(t_settings *settings)
{
	int	i;

	i = -1;
	while (++i < settings->map->height)
		free(settings->map->map[i]);
	free(settings->map->map);
}

static void	feed_map_line(t_settings *settings, char *line, int line_nb)
{
	int		i;

	i = -1;
	if (line_nb >= settings->map->start_line \
		&& line_nb <= settings->map->end_line)
	{
		while (++i < settings->map->width)
		{
			if (i < (int)ft_strlen(line))
				settings->map->map[line_nb - settings->map->start_line][i] \
					= line[i];
			else
				settings->map->map[line_nb - settings->map->start_line][i] \
					= ' ';
		}
	}
}

static void	feed_map(char *path, t_settings *settings)
{
	int		fd;
	char	*line;
	int		line_nb;
	char	*tmp;

	line_nb = 1;
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strtrim_right(line, " \n");
		feed_map_line(settings, tmp, line_nb);
		free(tmp);
		free(line);
		line = get_next_line(fd);
		line_nb++;
	}
}

static void	print_map(t_settings *settings)
{
	int	i;

	i = -1;
	while (++i < settings->map->height)
		printf("%s\n", settings->map->map[i]);
}

int	init_map(char *path, t_settings *settings)
{
	int	i;

	settings->map->height = settings->map->end_line \
		- settings->map->start_line + 1;
	settings->map->map = malloc(sizeof(char *) * settings->map->height);
	if (!settings->map->map)
		return (1);
	i = -1;
	while (++i < settings->map->height)
	{
		settings->map->map[i] = malloc(sizeof(char) * settings->map->width + 1);
		if (!settings->map->map[i])
			return (1);
		settings->map->map[i][settings->map->width] = '\0';
	}
	feed_map(path, settings);
	if (!is_map_valid(settings))
	{
		free_map(settings);
		return (1);
	}
	print_map(settings); // TODO : remove
	free_map(settings);
	return (0);
}
