/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:13:37 by nde-vant          #+#    #+#             */
/*   Updated: 2024/03/19 16:17:26 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen_gnl(src);
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

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		i;
	size_t		s_len;

	i = 0;
	s_len = ft_strlen_gnl(s + start);
	if (s_len < len)
		len = s_len;
	sub_str = (char *) malloc(len + 1);
	if (!sub_str)
		return (NULL);
	ft_strlcpy_gnl(sub_str, s + start, len + 1);
	return (sub_str);
}

char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	int		len1;
	int		len2;
	char	*str;

	len1 = ft_strlen_gnl(s1);
	len2 = ft_strlen_gnl(s2);
	str = (char *) malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	ft_strlcpy_gnl(str, s1, len1 + 1);
	ft_strlcpy_gnl(str + len1, s2, len2 + 1);
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

void	*ft_memset_gnl(void *b, int c, size_t len)
{
	size_t		i;
	char		*p_b;

	i = 0;
	p_b = b;
	while (i < len)
	{
		p_b[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
