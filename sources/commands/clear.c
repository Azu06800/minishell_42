/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:43:38 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 16:23:38 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_clear(t_parser_token *token, t_minishell *minishell)
{
	(void) token;
	(void) minishell;
	printf("\033[2J\033[1;1H");
	exit(0);
	return (0);
}
