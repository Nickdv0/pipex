/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:07:09 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/17 17:07:20 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n >= 0)
		n = -n;
	else
		write(fd, "-", 1);
	if (n / 10)
		ft_putnbr_fd((unsigned int)(-n) / 10, fd);
	write(fd, &"0123456789"[(unsigned int)(-n) % 10], 1);
}
