/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 09:24:17 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/25 09:24:17 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_ptr(int *len, unsigned long nbr)
{
	if (nbr / 16)
	{
		ft_print_ptr(len, nbr / 16);
	}
	ft_putchar_fd("0123456789abcdef"[nbr % 16], 1);
	(*len)++;
	return (*len);
}

int	ft_print_preptr(unsigned long nbr)
{
	int			len;

	ft_putstr_fd("0x", 1);
	len = 2;
	if (!nbr)
	{
		ft_putchar_fd('0', 1);
		len++;
		return (len);
	}
	return (ft_print_ptr(&len, nbr));
}

//#include <stdio.h>
//
//int	main(void)
//{
//	unsigned long val = 708990;
//	unsigned long *ptr = &val;
//
//	printf("%p\n", ptr);
//	int count = ft_print_preptr((unsigned long)ptr);
//	printf("\n%i\n", count);
//}