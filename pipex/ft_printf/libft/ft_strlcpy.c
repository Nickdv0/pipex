/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:36:49 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/10 14:05:30 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (i < dstsize - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (len);
}
/*
#include <stdio.h>
#include <libc.h>

int	main(void)
{
	char	test_dest[100];
	char	dest[100];
	char	src[] = "Hello World";

	ft_strlcpy(dest, src, 0);
	strlcpy(test_dest, src, 0);
	printf("test with ft %s\n", dest);
	printf("test without ft %s\n", test_dest);
}
*/