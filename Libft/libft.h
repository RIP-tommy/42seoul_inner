/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:40:41 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/02 21:53:00 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H_
  #define LIBFT_H_

#include <stddef.h>

	void		*ft_memset(void *b, int c, size_t len);
	void		ft_bzero(void *s, size_t n);
	void		*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
	void		*ft_memccpy(void *restrict dst, const void *restrict src, int c, size_t n);
	void		*ft_memmove(void *dst, const void *src, size_t len);
	void		*ft_memchr(const void *s, int c, size_t n);
	int			ft_memcmp(const void *s1, const void *s2, size_t n);
	size_t		ft_strlen(const char *s);
	size_t		ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize);
	size_t		ft_strlcat(char * restrict dst, const char * restrict src, size_t dstsize);
	char		*ft_strchr(const char *s, int c);
	char		*ft_strrchr(const char *s, int c);
	char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
	int			ft_strncmp(const char *s1, const char *s2, size_t n);
	int			ft_atoi(const char *str);
	int			ft_isalpha(int c);
	int			ft_isdigit(int c);
	int			ft_isalnum(int c);
	int			ft_isascii(int c);
	int			ft_isprint(int c);
	int			ft_toupper(int c);
	int			ft_tolower(int c);
	void		*ft_calloc(size_t count, size_t size);
	char		*ft_strdup(const char *s1);
	char		*ft_substr(char const *s, unsigned int start, size_t len);

#endif
