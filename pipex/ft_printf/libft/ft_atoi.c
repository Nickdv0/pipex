/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:07:35 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/11 10:07:39 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

static int	plus_minus(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	num;

	i = 0;
	num = 0;
	neg = 0;
	while (ft_isspace(str[i]))
		i++;
	if (plus_minus(str[i]) != 0)
		neg = plus_minus(str[i++]);
	while (ft_isdigit(str[i]))
	{
		num *= 10;
		num -= str[i++] - '0';
	}
	if (!neg)
		return (num * -1);
	else
		return (num * -neg);
}
