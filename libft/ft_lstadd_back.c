/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 23:11:36 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/20 18:38:28 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *n)
{
	t_list	*last_elem;

	if (lst)
	{
		if (*lst)
		{
			last_elem = ft_lstlast(*lst);
			last_elem->next = n;
		}
		else
		{
			*lst = n;
		}
	}
}
