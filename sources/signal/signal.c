/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 18:57:54 by baroun            #+#    #+#             */
/*   Updated: 2022/12/14 16:32:34 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	tester_lexer(char **token)
{
	int	i;

	i = -1;
	while (token[++i])
		printf("\ntoken %i = %s\n", i, token[i]);
}
