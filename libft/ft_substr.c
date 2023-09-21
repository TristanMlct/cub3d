/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:40:14 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/09 13:16:13 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*r;

	if (!s)
		return (0);
	r = malloc((len + 1) * sizeof(char));
	if (!r)
		return (0);
	if (start >= ft_strlen(s))
	{
		r[0] = 0;
		return (r);
	}
	i = 0;
	while (i < len && s[start + i])
	{
		r[i] = s[start + i];
		i++;
	}
	r[i] = '\0';
	return (r);
}
