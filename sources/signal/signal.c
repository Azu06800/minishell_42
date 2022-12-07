/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:29:17 by baroun            #+#    #+#             */
/*   Updated: 2022/12/07 15:08:43 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_signalhandler(int sig)
{
	if (sig == SIGINT)
	{
	}
	else if (sig == SIGQUIT)
	{

	}
}

void	init_signal(void)
{
	signal(SIGINT, ft_signalhandler);
	signal(SIGQUIT, ft_signalhandler);
}

//afficher un nouveau prompt
