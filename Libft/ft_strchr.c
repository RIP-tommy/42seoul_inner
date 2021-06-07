/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:13:04 by sungmcho          #+#    #+#             */
/*   Updated: 2021/06/07 16:13:06 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strchr(const char *str, int c)
{
    while (*str != '\0')
    {
        if (*str == c)
            return ((char *)str);
        ++str;
    }
    if (c == '\0')
        return ((char *)str);
    return (0);
}
