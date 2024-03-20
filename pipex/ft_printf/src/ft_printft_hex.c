/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printft_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:02:06 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/24 12:02:11 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	ft_print_hex(int *len, unsigned int nbr, int up_case)
{
	char	*alpha;

	alpha = "0123456789abcdef";
	if (up_case)
		alpha = "0123456789ABCDEF";
	if (nbr / 16)
	{
		ft_print_hex(len, nbr / 16, up_case);
	}
	ft_putchar_fd(alpha[nbr % 16], 1);
	(*len)++;
	return (*len);
}

int	ft_print_prehex(unsigned int nbr, char c)
{
	int			up_case;
	int			len;

	len = 0;
	up_case = 1;
	if (c == 'x')
		up_case = 0;
	return (ft_print_hex(&len, nbr, up_case));
}
/*
#include <stdio.h>

int	main(void)
{
	unsigned long val = 708990;
	unsigned long *ptr = &val;
	int  len  = 0;
	unsigned int nbr = 36556542;

	printf("%p\n", ptr);
	int count = ft_print_hex(&len, (unsigned int)ptr, 0);
	printf("\n%lX\n", (unsigned long)ptr);
	printf("%i\n", count);
}*/