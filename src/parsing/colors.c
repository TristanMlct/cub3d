/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 11:42:24 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/22 10:36:27 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_rgb_int(int r, int g, int b)
{
	if (r < 0 || r > 255)
		return (1);
	if (g < 0 || g > 255)
		return (1);
	if (b < 0 || b > 255)
		return (1);
	return (0);
}

static int	get_rgb_value(char **element, t_settings *settings, int is_floor)
{
	char	**tmp_split;

	tmp_split = ft_split(*element, ',');
	if (ft_splitsize(tmp_split) != 3)
	{
		ft_freesplit(tmp_split);
		return (1);
	}
	if (is_floor)
	{
		settings->f[0] = ft_atoi_plus(tmp_split[0]);
		settings->f[1] = ft_atoi_plus(tmp_split[1]);
		settings->f[2] = ft_atoi_plus(tmp_split[2]);
	}
	else
	{
		settings->c[0] = ft_atoi_plus(tmp_split[0]);
		settings->c[1] = ft_atoi_plus(tmp_split[1]);
		settings->c[2] = ft_atoi_plus(tmp_split[2]);
	}
	ft_freesplit(tmp_split);
	return (0);
}

static int	get_color_value(char **element, t_settings *settings, int is_floor)
{
	char	*tmp;
	char	**tmp_split;

	tmp = ft_strtrim(*element, " \n");
	free(*element);
	*element = tmp;
	tmp_split = ft_split(*element, ' ');
	if (ft_splitsize(tmp_split) != 2)
	{
		ft_freesplit(tmp_split);
		return (1);
	}
	if (get_rgb_value(&tmp_split[1], settings, is_floor))
	{
		ft_freesplit(tmp_split);
		return (1);
	}
	ft_freesplit(tmp_split);
	return (0);
}

int	verify_colors(t_settings *settings)
{
	if (!settings->f || !settings->c)
		return (1);
	if (get_color_value(&settings->fs, settings, 1))
		return (1);
	if (get_color_value(&settings->cs, settings, 0))
		return (1);
	if (is_rgb_int(settings->f[0], settings->f[1], settings->f[2]))
		return (1);
	if (is_rgb_int(settings->c[0], settings->c[1], settings->c[2]))
		return (1);
	ft_printf("F : %d %d %d\n", settings->f[0], settings->f[1], settings->f[2]);
	ft_printf("C : %d %d %d\n", settings->c[0], settings->c[1], settings->c[2]);
	return (0);
}

void	feed_settings_colors(t_settings *settings, char *line)
{
	char	*tmp;

	tmp = ft_strtrim(line, " ");
	if (tmp[0] == 'F')
	{
		settings->fs = ft_strdup(tmp);
		settings->f = malloc(sizeof(int) * 3);
	}
	else if (tmp[0] == 'C')
	{
		settings->cs = ft_strdup(tmp);
		settings->c = malloc(sizeof(int) * 3);
	}
	free(tmp);
}
