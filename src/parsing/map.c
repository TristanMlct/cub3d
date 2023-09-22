/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 23:57:48 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/22 10:32:06 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *settings)
{
	map->map = NULL;
	map->map_size = 0;
	map->map_width = 0;
	map->map_height = 0;
	map->map_start = 0;
	map->map_end = 0;
}
