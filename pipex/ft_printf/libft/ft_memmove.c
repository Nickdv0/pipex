/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:12:33 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/10 14:05:46 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*p_src;
	char		*p_dst;

	p_src = src;
	p_dst = dst;
	if (p_src < p_dst)
	{
		while (len > 0)
		{
			p_dst[len - 1] = (unsigned char)p_src[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(p_dst, p_src, len);
	return (p_dst);
}
