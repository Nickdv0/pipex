/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:12:35 by nde-vant          #+#    #+#             */
/*   Updated: 2023/10/11 12:13:16 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	int	*mem;

	mem = (int *) malloc(count * size);
	if (!mem)
	{
		return (NULL);
	}
	ft_bzero(mem, count * size);
	return (mem);
}
