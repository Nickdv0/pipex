/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-vant <nde-vant@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:56:26 by nde-vant          #+#    #+#             */
/*   Updated: 2024/02/27 14:45:52 by nde-vant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int	ft_print_chr(char c);
int	ft_print_str(char *str);
int	ft_print_prehex(unsigned int nbr, char c);
int	ft_print_preptr(unsigned long nbr);
int	ft_print_preint(int nbr);
int	ft_print_preunsint(unsigned int nbr);
int	ft_printf(const char *format, ...);

#endif //FT_PRINTF_H
