/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 22:20:15 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/23 01:05:02 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_settings *settings)
{
	settings->map = malloc(sizeof(t_map));
	settings->map->map = NULL;
	settings->map->width = 0;
	settings->map->height = 0;
	settings->map->start_line = 0;
	settings->map->end_line = 0;
}
