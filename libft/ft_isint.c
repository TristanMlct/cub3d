/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 00:29:44 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/22 00:59:09 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(const char *str)
{
	int			i;
	long long	res;
	int			neg;

	i = -1;
	res = 0;
	neg = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (str[0] == '-')
			neg = -1;
		i++;
	}
	while (str[++i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + (str[i] - '0');
		if (res > INT_MAX || res < INT_MIN)
			return (0);
		if (i == 1 && neg == -1)
			res *= -1;
	}
	return (1);
}
