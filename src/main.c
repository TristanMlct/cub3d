/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:50:54 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/23 01:20:48 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	settings_to_null(t_settings *settings)
{
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->f = NULL;
	settings->c = NULL;
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
	if (settings->f)
		free(settings->f);
	if (settings->c)
		free(settings->c);
	if (settings->map)
		free(settings->map);
	return (1);
}

static int	exit_error(t_settings *settings)
{
	free_settings(settings);
	ft_printf("Error\n");
	return (1);
}

int	main(int argc, char **argv)
{
	// TODO : change flags in makefile
	t_settings	settings;

	settings_to_null(&settings);
	init_map(&settings);
	if (!is_arg_valid(argc, argv))
		return (exit_error(&settings));
	if (parse_file(argv[1], &settings))
		return (exit_error(&settings));
	free_settings(&settings);
	return (0);
}
