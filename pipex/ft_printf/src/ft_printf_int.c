/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:49:41 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/24 13:50:20 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	ft_print_int(int *len, int nbr)
{
	if (nbr >= 0)
		nbr = -nbr;
	else
	{
		write(1, "-", 1);
		(*len)++;
	}
	if (nbr / 10)
		ft_print_int(len, (unsigned int)(-nbr) / 10);
	write(1, &"0123456789"[(unsigned int)(-nbr) % 10], 1);
	(*len)++;
	return (*len);
}

int	ft_print_preint(int nbr)
{
	int			len;

	len = 0;
	return (ft_print_int(&len, nbr));
}
