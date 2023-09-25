/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:18:12 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/24 12:58:07 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	analyse_line(char *line, t_settings *settings, int line_nb)
{
	if (is_valid_map_line(line))
	{
		if (is_map_last(settings) || !settings->map->end_line)
		{
			if (!settings->map->start_line)
				settings->map->start_line = line_nb;
			if (feed_map_settings(settings, line, line_nb))
				return (1);
		}
		else
			return (1);
	}
	else if (is_element(line))
	{
		if (!is_valid_texture(line) && !is_valid_color(line))
			return (1);
		feed_elements(settings, line);
	}
	else if (!is_empty_line(line))
		return (1);
	else if (is_empty_line(line) && settings->map->start_line)
		settings->map->end_line = line_nb - 1;
	return (0);
}

int	parse_file(char *path, t_settings *settings)
{
	int		fd;
	char	*line;
	int		r;
	int		line_nb;

	r = 0;
	line_nb = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line && !r)
	{
		if (analyse_line(line, settings, ++line_nb))
			r = 1;
		free(line);
		line = get_next_line(fd);
	}
	if (settings->map->start_line && !settings->map->end_line)
		settings->map->end_line = line_nb;
	free(line);
	close(fd);
	return (r);
}
