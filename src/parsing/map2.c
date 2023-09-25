/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:27:47 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/25 10:08:35 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_only_one_player(t_settings *settings)
{
	int		i;
	int		j;
	int		player_found;

	i = -1;
	player_found = 0;
	while (++i < settings->map->height)
	{
		j = -1;
		while (settings->map->map[i][++j])
		{
			if (settings->map->map[i][j] == 'N' \
				|| settings->map->map[i][j] == 'S' \
				|| settings->map->map[i][j] == 'W' \
				|| settings->map->map[i][j] == 'E')
			{
				if (player_found)
					return (0);
				player_found = 1;
			}
		}
	}
	if (!player_found)
		return (0);
	return (1);
}

static int	is_map_closed(t_settings *settings, int pos_x, int pos_y)
{
	if (pos_x < 0 || pos_x >= settings->map->width \
		|| pos_y < 0 || pos_y >= settings->map->height)
		return (0);
	if ((settings->map->map[pos_y][pos_x] != settings->map->player) \
		&& (settings->map->map[pos_y][pos_x] == '1' \
		|| settings->map->map[pos_y][pos_x] == 'F'))
		return (1);
	if (settings->map->map[pos_y][pos_x] != settings->map->player)
		settings->map->map[pos_y][pos_x] = 'F';
	return (is_map_closed(settings, pos_x - 1, pos_y) \
			&& is_map_closed(settings, pos_x + 1, pos_y) \
			&& is_map_closed(settings, pos_x, pos_y - 1) \
			&& is_map_closed(settings, pos_x, pos_y + 1));
}

int	is_map_valid(t_settings *settings)
{
	if (!is_only_one_player(settings) || !is_map_closed(settings, \
		settings->map->pos_x, settings->map->pos_y))
		return (0);
	return (1);
}
