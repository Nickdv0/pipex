/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:51:01 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/10 14:05:36 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = dstlen;
	j = 0;
	if (dstsize == 0 || dstsize <= dstlen)
		return (srclen + dstsize);
	while (src[j] && dstlen + j + 1 < dstsize)
	{
		dst[i++] = src[j++];
	}
	dst[i] = 0;
	return (dstlen + srclen);
}

/*{
    size_t    i;
    size_t    k;
    size_t    len_dest;
    size_t    len_src;

    len_dest = ft_strlen(dst);
    len_src = ft_strlen(src);
    k = len_dest;
    i = 0;
    if (dstsize == 0 || dstsize <= len_dest)
        return (len_src + dstsize);
    while (src[i] != '\0' && i < dstsize - len_dest - 1)
    {
        dst[k] = src[i];
        k++;
        i++;
    }
    dst[k] = '\0';
    return (len_dest + len_src);
}*/