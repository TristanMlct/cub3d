/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:18:12 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/23 01:15:28 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	analyse_line(char *line, t_settings *settings)
{
	if (settings->map->start_line != 0 && !is_valid_map_line(line))
		return (1);
	if (is_valid_map_line(line))
	{
		if (is_map_last(line, settings))
			ft_printf("Map found and last\n");
		else
			return (1);
	}
	else if (is_settings(line))
		feed_settings(settings, line);
	else if (!is_empty_line(line))
		return (1);
	return (0);
}

int	parse_file(char *path, t_settings *settings)
{
	int		fd;
	char	*line;
	int		r;

	r = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line && !r)
	{
		if (analyse_line(line, settings))
			r = 1;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (r);
}

// return (r || verify_settings(settings));


// static int	verify_settings(t_settings *settings)
// {
// 	return (verify_textures(settings) \
// 			|| verify_colors(settings));
// 			// || verify_map(settings));
// }

// TODO : error if not valid element
// feed_settings_textures(settings, line);
// feed_settings_colors(settings, line);
// if (feed_settings_map(settings, line))
// {
// 	ft_printf("Map found but not last\n");
// 	r = 1;
// }