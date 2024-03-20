/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 17:37:02 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/30 12:01:36 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_checker(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		len;
	char	*str_empty;

	i = 0;
	if (!s1[0])
	{
		str_empty = (char *)malloc(1);
		if (!str_empty)
			return (NULL);
		*str_empty = 0;
		return (str_empty);
	}
	while (s1[i] && set_checker(set, s1[i]))
		i++;
	start = i;
	while (s1[i])
		i++;
	i--;
	while (i > -1 && s1[i] && set_checker(set, s1[i]))
		i--;
	len = i - start + 1;
	return (ft_substr(s1, (unsigned int)start, (size_t)len));
}
