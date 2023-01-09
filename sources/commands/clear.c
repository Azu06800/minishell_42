/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 23:43:38 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 22:24:12 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_clear(t_parser_token *token, t_minishell *minishell)
{
	(void) token;
	(void) minishell;
	printf("\033[2J\033[1;1H");
	return (0);
}
