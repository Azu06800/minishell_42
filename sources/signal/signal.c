/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:57:54 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 09:41:25 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

pid_t	g_pid;

void	sigq(void)
{
	if (g_pid)
	{
		if (!kill(g_pid, SIGQUIT))
			printf("%i	Quit:\n", g_pid);
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
	g_pid = 0;
}

void	sigi(void)
{
	printf("\n");
	if (g_pid)
		kill(g_pid, SIGINT);
	else
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_pid = 0;
}

static void	ft_signalhandler(int sig)
{
	if (sig == SIGINT)
		sigi();
	else if (sig == SIGQUIT)
		sigq();
	else if (sig == SIGTERM)
	{
		ft_putstr_fd("exit", 2);
		ft_putstr_fd("\n", 2);
		exit(0);
	}
}

void	init_signal(void)
{
	echo_control_seq(0);
	signal(SIGINT, ft_signalhandler);
	signal(SIGQUIT, ft_signalhandler);
}
