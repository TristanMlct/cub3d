/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:35:52 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/22 00:59:55 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_plus(const char *str)
{
	int			neg;
	int			i;
	long int	r;

	i = 0;
	neg = 1;
	if (!ft_isint(str))
		return (-1);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	r = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		r *= 10;
		r += (str[i] - '0');
		i++;
	}
	return (r * neg);
}
