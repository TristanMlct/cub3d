/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:57:48 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/22 22:09:26 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_map(char *line)
{
	int	i;
	int	wall_found;

	i = -1;
	wall_found = 0;
	while (line[++i])
	{
		if (line[i] != '1' && line[i] != ' ' && line[i] != 'N' \
			&& line[i] != 'S' && line[i] != 'W' && line[i] != 'E' \
			&& line[i] != '0')
			return (0);
	}
	return (1);
}

static int	is_valid_map_line(char *line)
{
	int	i;
	int	wall_found;

	i = -1;
	wall_found = 0;
	while (line[++i])
	{
		if (line[i] == '1')
			wall_found = 1;
		if (!wall_found && (line[i] == 'N' || line[i] == 'S' \
			|| line[i] == 'W' || line[i] == 'E' || line[i] == '0'))
			return (0);
	}
	return (1);
}

static int	is_map_last(t_settings *settings, char *line)
{
	if (!is_map(line) || !is_valid_map_line(line))
		return (0);
	return (1);
}

int	feed_settings_map(t_settings *settings, char *line)
{
	if (!is_map_last(settings, line))
		return (1);
	return (0);
}

void	init_map(t_settings *settings)
{
	settings->map = malloc(sizeof(t_map));
	settings->map->map = NULL;
	settings->map->map_size = 0;
	settings->map->map_width = 0;
	settings->map->map_height = 0;
}
