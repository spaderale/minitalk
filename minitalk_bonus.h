/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abroslav <abroslav@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 02:34:04 by abroslav          #+#    #+#             */
/*   Updated: 2025/11/11 17:05:27 by abroslav         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "ft_printf/ft_printf.h"

void	handle_signal(int sig, siginfo_t *info, void *context);
void	setup_client_signals(void);
void	setup_server_signals(void);
void	handle_ack(int sig);
void	send_char(pid_t pid, unsigned char c);
void	send_messgae(pid_t server_pid, char *msg);
int		ft_atoi(const char *str);

#endif
