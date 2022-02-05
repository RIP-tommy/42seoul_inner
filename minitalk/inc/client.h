/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 22:47:12 by sungmcho          #+#    #+#             */
/*   Updated: 2022/02/05 16:21:00 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../Libft/libft.h"
# include "../printf/ft_printf.h"

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <errno.h>

void	send_msg(int pid, char *s);

#endif
