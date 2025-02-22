/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaniatt <tbaniatt@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:04:10 by tbaniatt          #+#    #+#             */
/*   Updated: 2024/09/11 00:07:56 by tbaniatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <limits.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_putcharpf(char c);
int	ft_putstrpf(const char *str);
int	ft_mod(const char *str, va_list args);
int	ft_printf(const char *str, ...);
int	ft_putnbr_base(long num, char *base, int base_len);
int	ft_putpoin(void *args);

#endif
