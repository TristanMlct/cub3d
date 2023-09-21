/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 12:54:18 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/20 22:11:22 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_nbr_len(unsigned int n)
{
	int					c;

	c = 0;
	while (n / 10 != 0)
	{
		c++;
		n /= 10;
	}
	return (c + 1);
}

char	*ft_uitoa(unsigned int n)
{
	char				*s;
	int					size;

	size = print_nbr_len(n);
	s = malloc((size + 1) * sizeof(char));
	if (!s)
		return (0);
	s[size] = '\0';
	if (size == 1 && n == 0)
		s[0] = '0';
	while (n != 0 && --size >= 0)
	{
		s[size] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

int	print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	print_string(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	print_ptr_hex(void *ptr)
{
	unsigned long long	arg;
	char				to_print[16];
	int					c;
	char				*hex;

	hex = "0123456789abcdef";
	arg = (unsigned long long)ptr;
	c = 0;
	if (arg == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	while (arg > 0)
	{
		to_print[c] = hex[arg % 16];
		arg /= 16;
		c++;
	}
	to_print[c] = '\0';
	ft_putstr_fd("0x", 1);
	while (--c >= 0)
		ft_putchar_fd(to_print[c], 1);
	return (ft_strlen(to_print) + 2);
}
