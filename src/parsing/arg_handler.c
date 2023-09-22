/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:10:06 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/22 01:00:45 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_arg(int argc, char **argv)
{
	if (argc != 2)
		return (ft_error("Error\n"));
	if (ft_strlen(argv[1]) < 4)
		return (ft_error("Error\n"));
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
		return (ft_error("Error\n"));
	return (0);
}

static int	verify_settings(t_settings *settings)
{
	return (verify_textures(settings) \
			|| verify_colors(settings));
			// || verify_map(settings));
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
	while (line)
	{
		feed_settings_textures(settings, line);
		feed_settings_colors(settings, line);
		// if (feed_settings_map(settings, line))
		// {
		// 	r = 1;
		// 	break ;
		// }
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (r || verify_settings(settings));
}
