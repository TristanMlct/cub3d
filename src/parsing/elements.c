/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:58:56 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/21 01:56:40 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_texture_path(char **element)
{
	char	*tmp;
	char	**tmp_split;

	tmp = ft_strtrim(*element, " \n");
	free(*element);
	*element = tmp;
	tmp_split = ft_split(*element, ' ');
	if (ft_splitsize(tmp_split) != 2 || ft_strlen(tmp_split[1]) < 3 \
		|| ft_strncmp(tmp_split[1], "./", 2))
	{
		ft_freesplit(tmp_split);
		return (1);
	}
	free(*element);
	*element = ft_strdup(tmp_split[1]);
	ft_freesplit(tmp_split);
	return (0);
}

static int	verify_textures(t_settings *settings)
{
	if (!settings->no || !settings->so || !settings->we || !settings->ea)
		return (1);
	if (get_texture_path(&settings->no))
		return (1);
	if (get_texture_path(&settings->so))
		return (1);
	if (get_texture_path(&settings->we))
		return (1);
	if (get_texture_path(&settings->ea))
		return (1);
	ft_printf("NO : %s & len : %d\n", settings->no, ft_strlen(settings->no));
	ft_printf("SO : %s\n", settings->so);
	ft_printf("WE : %s\n", settings->we);
	ft_printf("EA : %s\n", settings->ea);
	return (0);
}

static void	feed_settings(t_settings *settings, char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	free(line);
	line = tmp;
	if (line[0] == 'N' && line[1] == 'O')
		settings->no = ft_strdup(line);
	else if (line[0] == 'S' && line[1] == 'O')
		settings->so = ft_strdup(line);
	else if (line[0] == 'W' && line[1] == 'E')
		settings->we = ft_strdup(line);
	else if (line[0] == 'E' && line[1] == 'A')
		settings->ea = ft_strdup(line);
	free(line);
}

int	get_textures(char *path, t_settings *settings)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		feed_settings(settings, line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (verify_textures(settings));
}
