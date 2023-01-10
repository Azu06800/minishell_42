/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:57:54 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 18:57:16 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	sigq(void)
{
	if (g_minishell->cur_proc_pid)
	{
		if (!kill(g_minishell->cur_proc_pid, SIGQUIT))
			printf("Quit: 3\n");
	}
	else
	{
		rl_on_new_line();
		rl_redisplay();
	}
	g_minishell->cur_proc_pid = 0;
}

void	sigi(void)
{
	printf("\n");
	if (g_minishell->cur_proc_pid)
		kill(g_minishell->cur_proc_pid, SIGINT);
	else
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_minishell->cur_proc_pid = 0;
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
