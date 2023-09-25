/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:58:56 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/24 00:00:11 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_texture(char *line)
{
	char	**tmp_split;
	char	*tmp;
	int		r;

	r = 1;
	tmp = ft_strtrim(line, " \n");
	tmp_split = ft_split(tmp, ' ');
	if (ft_splitsize(tmp_split) != 2 || ft_strlen(tmp_split[0]) != 2)
		r = 0;
	else if (ft_strncmp(tmp, "NO", 2) \
			&& ft_strncmp(tmp, "SO", 2) \
			&& ft_strncmp(tmp, "WE", 2) \
			&& ft_strncmp(tmp, "EA", 2))
		r = 0;
	else
	{
		free(tmp);
		tmp = ft_strtrim(tmp_split[1], " \n");
		if (ft_strlen(tmp) < 3 || ft_strncmp(tmp, "./", 2))
			r = 0;
	}
	free(tmp);
	ft_freesplit(tmp_split);
	return (r);
}

char	*get_path(char *texture_line)
{
	char	**tmp_split;
	char	*path;

	tmp_split = ft_split(texture_line, ' ');
	path = ft_strtrim(tmp_split[1], " \n");
	ft_freesplit(tmp_split);
	return (path);
}
