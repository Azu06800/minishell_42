/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 07:56:43 by baroun            #+#    #+#             */
/*   Updated: 2023/01/09 16:27:15 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_history(t_parser_token *token, t_minishell *minishell)
{
	HIST_ENTRY	**history;
	int			i;

	(void)token;
	(void)minishell;
	i = -1;
	history = history_list();
	while (history[++i])
		printf("%d  %s\n", i, history[i]->line);
	exit(0);
	return (0);
}
