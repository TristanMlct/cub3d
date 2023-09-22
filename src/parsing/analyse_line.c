/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyse_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:26:28 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/23 01:21:36 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_map_line(char *line)
{
	int		i;
	int		wall_found;
	char	*tmp;

	i = -1;
	wall_found = 0;
	while (line[++i] && line[i] != '\n')
	{
		if (line[i] == '1')
			wall_found = 1;
		if (!wall_found && line[i] != ' ')
			return (0);
		if (wall_found && line[i] != '1' && line[i] != '0' \
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'W' \
			&& line[i] != 'E' && line[i] != ' ')
			return (0);
	}
	tmp = ft_strtrim(line, " \n");
	if (tmp[ft_strlen(tmp) - 1] != '1' || !wall_found)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}

int	is_map_last(char *line, t_settings *settings)
{
	if (!settings->no || !settings->so || !settings->we || !settings->ea \
		|| !settings->f || !settings->c)
		return (0);
	return (1);
}

int	is_settings(char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " \n");
	if ((tmp[0] == 'N' && tmp[1] == 'O') \
		|| (tmp[0] == 'S' && tmp[1] == 'O') \
		|| (tmp[0] == 'W' && tmp[1] == 'E') \
		|| (tmp[0] == 'E' && tmp[1] == 'A') \
		|| (tmp[0] == 'F') \
		|| (tmp[0] == 'C'))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

int	is_empty_line(char *line)
{
	int		i;
	char	*tmp;

	i = -1;
	tmp = ft_strtrim(line, " \n");
	if (!ft_strlen(tmp))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

void	feed_settings(t_settings *settings, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		settings->no = get_path(line);
	else if (line[0] == 'S' && line[1] == 'O')
		settings->so = get_path(line);
	else if (line[0] == 'W' && line[1] == 'E')
		settings->we = get_path(line);
	else if (line[0] == 'E' && line[1] == 'A')
		settings->ea = get_path(line);
	else if (line[0] == 'F')
		settings->f = get_color(line);
	else if (line[0] == 'C')
		settings->c = get_color(line);
}
