/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tayeo <tayeo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:36:53 by tayeo             #+#    #+#             */
/*   Updated: 2022/07/08 16:25:06 by tayeo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		format_str_parser(va_list arg_ptr, char format);
int		put_uint(unsigned int num);
int		put_hex_int(int num, char c);
int		put_hex_addr(void *addr);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int nb);
size_t	ft_strlen(const char *s);
#endif
