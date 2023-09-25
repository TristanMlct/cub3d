/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:50:54 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/24 18:00:21 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	// TODO : change flags in makefile
	// TODO : add explicit error messages
	t_settings	settings;

	settings_to_null(&settings);
	map_to_null(&settings);
	if (!is_arg_valid(argc, argv))
		return (exit_error(&settings));
	if (parse_file(argv[1], &settings))
		return (exit_error(&settings));
	if (init_map(argv[1], &settings))
		return (exit_error(&settings));
	free_settings(&settings);
	return (0);
}
