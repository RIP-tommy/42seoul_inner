/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 13:35:11 by sungmcho          #+#    #+#             */
/*   Updated: 2021/09/09 20:16:14 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	print_chr(va_list *args, int *res);
void	print_str(va_list *args, int *res);
void	print_ptr(va_list *args, int *res);
void	print_int(va_list *args, int *res);
void	print_un(va_list *args, int *res);
void	print_hex(va_list *args, int capitals, int *res);
void	itoh(unsigned long long n, int capitals, int *res);
void	ft_putchar_fd(char c, int fd, int *res);
void	ft_putnbr_fd(long long n, int *res);
void	ft_putstr_fd(const char *s, int fd, int *res);
size_t	ft_strlen(const char *src);

#endif
