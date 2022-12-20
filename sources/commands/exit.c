/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:10:04 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/17 15:01:43 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(char **token, t_minishell *minishell)
{
	int	i;

	(void) minishell;
	i = -1;
	while (token[++i])
		free(token[i]);
	free(token[i]);
	free(token);
	exit(0);
}
