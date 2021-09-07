/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:35:11 by sungmcho          #+#    #+#             */
/*   Updated: 2021/08/27 14:51:09 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	print_chr(va_list *args);
void	print_str(va_list *args);
void	print_ptr(va_list *args);
void	print_int(va_list *args);
void	print_un(va_list *args);
void	print_hex(va_list *args, int capitals);
void	itoh(long n, int capitals);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(const char *s, int fd);
size_t	ft_strlen(const char *src);

#endif
