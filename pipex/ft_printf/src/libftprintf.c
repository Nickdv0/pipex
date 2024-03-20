/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 15:35:54 by nde-vant          #+#    #+#             */
/*   Updated: 2024/02/27 14:42:14 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	redirect(char c, va_list args)
{
	if (c == 'c')
		return (ft_print_chr(va_arg(args, int)));
	else if (c == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_print_preptr(va_arg(args, unsigned long)));
	else if (c == 'd')
		return (ft_print_preint(va_arg(args, int)));
	else if (c == 'i')
		return (ft_print_preint(va_arg(args, int)));
	else if (c == 'u')
		return (ft_print_preunsint(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print_prehex(va_arg(args, unsigned int), c));
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			count;
	int			temp;

	va_start(args, format);
	i = -1;
	count = 0;
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			temp = redirect(format[i++ + 1], args);
			if (temp == -1)
				return (-1);
			count += temp;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}
