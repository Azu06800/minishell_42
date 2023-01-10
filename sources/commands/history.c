/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 07:56:43 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 18:54:38 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_history(t_parser_token *token)
{
	HIST_ENTRY	**history;
	int			i;

	(void)token;
	i = -1;
	history = history_list();
	while (history[++i])
		printf("%d  %s\n", i, history[i]->line);
	return (0);
}
