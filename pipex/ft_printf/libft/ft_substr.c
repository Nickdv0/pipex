/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:20:13 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/11 13:20:45 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		i;
	size_t		s_len;

	i = 0;
	if (start >= (size_t)ft_strlen(s) || len == 0)
		return (ft_strdup("\0"));
	s_len = ft_strlen(s + start);
	if (s_len < len)
		len = s_len;
	sub_str = (char *) malloc(len + 1);
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, s + start, len + 1);
	return (sub_str);
}
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub_str;
	size_t		i;
	size_t		s_len;

	i = 0;
	s_len = ft_strlen(s);
	if (s_len < len)
		len = s_len;
	sub_str = (char *) malloc(len + 1);
	if (!sub_str)
		return (NULL);
	while (i < len && (size_t)start < s_len && s[start])
	{
		sub_str[i] = s[start];
		start++;
		i++;
	}
	sub_str[i] = 0;
	return (sub_str);
}
*/