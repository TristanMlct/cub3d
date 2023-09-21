/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:33:16 by tmilcent          #+#    #+#             */
/*   Updated: 2023/09/20 18:43:36 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join(char *s1, char *s2, int size)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = malloc((ft_strlen(s1) + 1) * sizeof(char));
	i = -1;
	while (s1[++i])
		tmp[i] = s1[i];
	tmp[i] = '\0';
	free(s1);
	s1 = malloc(sizeof(char) * (size + 1));
	i = -1;
	while (tmp[++i])
		s1[i] = tmp[i];
	free(tmp);
	j = -1;
	while (s2[++j])
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return (s1);
}

char	*find_line(char *str)
{
	char	*r;
	int		i;

	i = -1;
	while (str[++i] != '\n' && str[i])
		continue ;
	if (str[i] == '\n')
		i++;
	if (!i)
		return (0);
	r = malloc(sizeof(char) * (i + 1));
	r[i] = '\0';
	while (--i >= 0)
		r[i] = str[i];
	return (r);
}

char	*remove_first_line(char *str)
{
	char					*r;
	long unsigned int		i;
	int						j;

	i = -1;
	while (str[++i] != '\n' && str[i])
		continue ;
	if (i == ft_strlen(str))
	{
		free(str);
		return (0);
	}
	else
	{
		r = malloc((ft_strlen(str) - i) * sizeof(char));
		j = -1;
		while (str[++i])
			r[++j] = str[i];
		r[++j] = '\0';
		free(str);
		return (r);
	}
}

char	*init_curr_line(void)
{
	char	*r;

	r = malloc(sizeof(char));
	r[0] = '\0';
	return (r);
}

char	*get_next_line(int fd)
{
	static char	*curr_line = 0;
	char		*r;
	char		buffer[BUFFER_SIZE + 1];
	int			size;

	if (!curr_line)
		curr_line = init_curr_line();
	while (!is_bn_in_line(curr_line))
	{
		size = read(fd, buffer, BUFFER_SIZE);
		if (size == -1)
		{
			free(curr_line);
			curr_line = 0;
			return (0);
		}
		buffer[size] = '\0';
		if (size == 0)
			break ;
		curr_line = ft_join(curr_line, buffer, ft_strlen(curr_line) + size);
	}
	r = find_line(curr_line);
	curr_line = remove_first_line(curr_line);
	return (r);
}
