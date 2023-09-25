/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:42:24 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/23 23:58:04 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_valid_rgb(char *line)
{
	char	**tmp_split;
	int		r;

	r = 1;
	tmp_split = ft_split(line, ',');
	if (ft_splitsize(tmp_split) != 3)
		r = 0;
	else if (!ft_isdigit_str(tmp_split[0]) \
			|| !ft_isdigit_str(tmp_split[1]) \
			|| !ft_isdigit_str(tmp_split[2]))
		r = 0;
	else if (ft_atoi_plus(tmp_split[0]) < 0 || ft_atoi_plus(tmp_split[0]) > 255 \
			|| ft_atoi_plus(tmp_split[1]) < 0 \
			|| ft_atoi_plus(tmp_split[1]) > 255 \
			|| ft_atoi_plus(tmp_split[2]) < 0 \
			|| ft_atoi_plus(tmp_split[2]) > 255)
		r = 0;
	ft_freesplit(tmp_split);
	return (r);
}

int	is_valid_color(char *line)
{
	char	**tmp_split;
	char	*tmp;
	int		r;

	r = 1;
	tmp = ft_strtrim(line, " \n");
	tmp_split = ft_split(tmp, ' ');
	if (ft_splitsize(tmp_split) != 2 || ft_strlen(tmp_split[0]) != 1)
		r = 0;
	else if (ft_strncmp(tmp, "F", 1) && ft_strncmp(tmp, "C", 1))
		r = 0;
	else
	{
		if (!is_valid_rgb(tmp_split[1]))
			r = 0;
	}
	free(tmp);
	ft_freesplit(tmp_split);
	return (r);
}

int	*get_color(char *color_line)
{
	char	**tmp_split;
	char	**tmp_split2;
	char	*tmp;
	int		*color;

	tmp = ft_strtrim(color_line, " \n");
	tmp_split = ft_split(tmp, ' ');
	free(tmp);
	tmp_split2 = ft_split(tmp_split[1], ',');
	ft_freesplit(tmp_split);
	color = malloc(sizeof(int) * 3);
	color[0] = ft_atoi_plus(tmp_split2[0]);
	color[1] = ft_atoi_plus(tmp_split2[1]);
	color[2] = ft_atoi_plus(tmp_split2[2]);
	ft_freesplit(tmp_split2);
	return (color);
}
