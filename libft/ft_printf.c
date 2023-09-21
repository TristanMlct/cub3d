/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmilcent <tmilcent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:14:46 by tmilcent          #+#    #+#             */
/*   Updated: 2022/11/20 22:05:57 by tmilcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_int(int nb)
{
	int		r;
	char	*str;

	str = ft_itoa(nb);
	ft_putstr_fd(str, 1);
	r = ft_strlen(str);
	free(str);
	return (r);
}

int	print_unsigned_int(unsigned int nb)
{
	int		r;
	char	*str;

	str = ft_uitoa(nb);
	ft_putstr_fd(str, 1);
	r = ft_strlen(str);
	free(str);
	return (r);
}

int	print_hex(unsigned int nb, char type)
{
	int		c;
	char	tab[9];
	char	*hex;

	if (type == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	ft_bzero(tab, 9);
	c = 0;
	if (nb == 0)
		return (print_char('0'));
	while (nb > 0)
	{
		tab[c] = hex[nb % 16];
		nb /= 16;
		c++;
	}
	while (--c >= 0)
		ft_putchar_fd(tab[c], 1);
	return (ft_strlen(tab));
}

int	print_format(char c, va_list args)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	else if (c == 's')
		return (print_string(va_arg(args, char *)));
	else if (c == 'p')
		return (print_ptr_hex(va_arg(args, void *)));
	else if (c == 'd' || c == 'i')
		return (print_int(va_arg(args, int)));
	else if (c == 'u')
		return (print_unsigned_int(va_arg(args, unsigned int)));
	else if (c == 'x')
		return (print_hex(va_arg(args, unsigned int), 'x'));
	else if (c == 'X')
		return (print_hex(va_arg(args, unsigned int), 'X'));
	else if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		c;

	va_start(args, str);
	i = -1;
	c = 0;
	while (str[++i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			c += print_format(str[++i], args);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			c++;
		}
	}
	va_end(args);
	return (c);
}
