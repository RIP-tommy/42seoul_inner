/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:40:41 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/01 18:05:08 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H_
  #define LIBFT_H_

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>

	void		*ft_memset(void *b, int c, size_t len);
	void		ft_bzero(void *s, size_t n);
	void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
	void		*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
	void		*ft_memmove(void *dst, const void *src, size_t len);
	// ft_memchr()
	// ft_memcmp()
	size_t		ft_strlen(const char *s);
	// size_t		ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
	size_t		ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
	// ft_strchr()
	// ft_strrchr()
	// ft_strnstr()
	// ft_strncmp()
	int			ft_atoi(const char *str);
	// int			ft_isalpha()
	int			ft_isdigit(int c);
	// int			ft_isalnum()
	// int			ft_isascii()
	// int			ft_isprint()
	int			ft_toupper(int c);
	// int			ft_tolower()

#endif
