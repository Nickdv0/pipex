/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 10:28:50 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/17 10:36:51 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_count(int n)
{
	int	i;

	i = 1;
	while (n / 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		num_size;
	char	*str;
	int		neg;

	neg = 0;
	num_size = num_count(n);
	if (n < 0)
		num_size++;
	if (n < 0)
		neg++;
	str = (char *) malloc((num_size + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	str[num_size] = 0;
	while (num_size > neg)
	{
		if (n >= 0)
			str[num_size-- - 1] = n % 10 + '0';
		else
			str[num_size-- - 1] = (unsigned int)(-n) % 10 + '0';
		n /= 10;
	}
	return (str);
}
