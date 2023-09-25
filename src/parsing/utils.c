/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:20:15 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/24 14:10:31 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_to_null(t_settings *settings)
{
	settings->map = malloc(sizeof(t_map));
	settings->map->map = NULL;
	settings->map->width = 0;
	settings->map->height = 0;
	settings->map->start_line = 0;
	settings->map->end_line = 0;
	settings->map->player = 0;
	settings->map->pos_x = 0;
	settings->map->pos_y = 0;
}

void	settings_to_null(t_settings *settings)
{
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->f = NULL;
	settings->c = NULL;
	settings->map = NULL;
}

int	free_settings(t_settings *settings)
{
	if (settings->no)
		free(settings->no);
	if (settings->so)
		free(settings->so);
	if (settings->we)
		free(settings->we);
	if (settings->ea)
		free(settings->ea);
	if (settings->f)
		free(settings->f);
	if (settings->c)
		free(settings->c);
	if (settings->map)
		free(settings->map);
	return (1);
}

int	exit_error(t_settings *settings)
{
	free_settings(settings);
	ft_printf("Error\n");
	return (1);
}
