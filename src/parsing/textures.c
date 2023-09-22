/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:58:56 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/22 00:53:20 by tmilcent         ###   ########.fr       */
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
	if (ft_splitsize(tmp_split) != 2 || ft_strlen(tmp_split[1]) < 3
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

int	verify_textures(t_settings *settings)
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

void	feed_settings_textures(t_settings *settings, char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (tmp[0] == 'N' && tmp[1] == 'O')
		settings->no = ft_strdup(tmp);
	else if (tmp[0] == 'S' && tmp[1] == 'O')
		settings->so = ft_strdup(tmp);
	else if (tmp[0] == 'W' && tmp[1] == 'E')
		settings->we = ft_strdup(tmp);
	else if (tmp[0] == 'E' && tmp[1] == 'A')
		settings->ea = ft_strdup(tmp);
	free(tmp);
}
