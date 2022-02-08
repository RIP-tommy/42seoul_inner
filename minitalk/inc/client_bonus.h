/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sungmcho <sungmcho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 16:19:43 by sungmcho          #+#    #+#             */
/*   Updated: 2022/02/08 17:22:56 by sungmcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H

# include <stdarg.h>
# include <unistd.h>

# include "../Libft/libft.h"
# include "../printf/ft_printf.h"

# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <stdlib.h>
# include <errno.h>

void	send_msg(int pid, char *s);

#endif
