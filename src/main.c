/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:50:54 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/22 10:40:56 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	null_settings(t_settings *settings)
{
	settings->no = NULL;
	settings->so = NULL;
	settings->we = NULL;
	settings->ea = NULL;
	settings->fs = NULL;
	settings->cs = NULL;
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
	if (settings->fs)
		free(settings->fs);
	if (settings->cs)
		free(settings->cs);
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
	return (1);
}

int	main(int argc, char **argv)
{
	t_settings	settings;

	null_settings(&settings);
	if (check_arg(argc, argv))
		return (exit_error(&settings));
	if (parse_file(argv[1], &settings))
		return (exit_error(&settings));
	free_settings(&settings);
	return (0);
}
