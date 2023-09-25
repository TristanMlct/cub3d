/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 14:00:19 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/24 14:01:55 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



static int	is_in_charset(char c, char const *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
	{
		if (charset[i] == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim_right(char const *str, char const *set)
{
	int		end;
	int		len_str;
	int		i;
	char	*r;

	if (!str)
		return (0);
	len_str = ft_strlen(str);
	end = len_str - 1;
	while (str[end] && is_in_charset(str[end], set))
		end--;
	r = malloc((end + 2) * sizeof(char));
	if (!r)
		return (0);
	i = -1;
	while (++i <= end)
		r[i] = str[i];
	r[i] = '\0';
	return (r);
}
