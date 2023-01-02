/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:57:54 by baroun            #+#    #+#             */
/*   Updated: 2023/01/01 23:52:18 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	ft_signalhandler(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
	else if (sig == SIGTERM)
	{
		ft_putstr_fd("exit", 2);
		ft_putstr_fd("\n", 2);
		exit(0);
	}
}

void	init_signal(void)
{
	signal(SIGINT, ft_signalhandler);
	signal(SIGQUIT, ft_signalhandler);
}
