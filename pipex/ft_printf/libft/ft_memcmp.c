/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:26:41 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/10 16:26:45 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	const char		*p_s1;
	const char		*p_s2;

	i = 0;
	p_s1 = s1;
	p_s2 = s2;
	while (i < n)
	{
		if ((unsigned char)p_s1[i] != (unsigned char)p_s2[i])
		{
			return ((unsigned char)p_s1[i] - (unsigned char)p_s2[i]);
		}
		i++;
	}
	return (0);
}
