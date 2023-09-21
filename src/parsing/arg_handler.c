/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:10:06 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/21 01:23:55 by tmilcent         ###   ########.fr       */
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

static void	init_settings(t_settings *settings)
{
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->f = -1;
	settings->c = -1;
	settings->map = NULL;
}

static int	free_settings(t_settings *settings)
{
	if (settings->no)
		free(settings->no);
	if (settings->so)
		free(settings->so);
	if (settings->we)
		free(settings->we);
	if (settings->ea)
		free(settings->ea);
	if (settings->map)
		free(settings->map);
	return (1);
}

int	parse_map(char *path, t_settings *settings)
{
	init_settings(settings);
	if (get_textures(path, settings))
		return (ft_error("Error\n") && free_settings(settings));
	// if (get_colors(path))
	// 	return (ft_error("Error\n"));
	// if (get_map(path))
	// 	return (ft_error("Error\n"));
	// if (check_map())
	// 	return (ft_error("Error\n"));
	free_settings(settings);
	return (0);
}
