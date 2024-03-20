/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:08:52 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/11 13:09:35 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*mem;
	int		len;

	len = ft_strlen(s1) + 1;
	mem = (char *)malloc(len);
	if (!mem)
		return (NULL);
	ft_strlcpy(mem, s1, len);
	return (mem);
}
