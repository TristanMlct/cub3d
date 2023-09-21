/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:44:37 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/09 13:54:16 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	size_t	i;

	ptr = (void *)malloc(n * size);
	if (!ptr)
		return (0);
	i = -1;
	while (++i < n * size)
		*(unsigned char *)(ptr + i) = 0;
	return (ptr);
}
