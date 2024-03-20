/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:50:13 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/10 14:05:50 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*p_src;
	char		*p_dst;

	if (!dst && !src)
		return (dst);
	i = 0;
	p_src = src;
	p_dst = dst;
	while (i < n)
	{
		p_dst[i] = (unsigned char)p_src[i];
		i++;
	}
	return (dst);
}
