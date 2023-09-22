/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:10:06 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/22 22:18:19 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_arg_valid(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	if (ft_strlen(argv[1]) < 4)
		return (0);
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 4))
		return (0);
	return (1);
}
