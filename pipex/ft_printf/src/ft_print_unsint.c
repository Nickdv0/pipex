/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:33:36 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/26 11:33:41 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

static int	ft_print_unsint(int *len, unsigned int nbr)
{
	if (nbr / 10)
	{
		ft_print_unsint(len, nbr / 10);
	}
	ft_putchar_fd("0123456789"[nbr % 10], 1);
	(*len)++;
	return (*len);
}

int	ft_print_preunsint(unsigned int nbr)
{
	int			len;

	len = 0;
	return (ft_print_unsint(&len, nbr));
}
