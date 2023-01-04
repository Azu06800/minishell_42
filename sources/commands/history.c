/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 07:56:43 by baroun            #+#    #+#             */
/*   Updated: 2023/01/04 08:22:51 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void ft_history()
{
    HIST_ENTRY **history;
    int i;

    i = -1;
    history = history_list();
    while (history[++i])
        printf("%d  %s\n", i, history[i]->line);
}
