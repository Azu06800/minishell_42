/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:12:46 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/14 15:45:01 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(char **token)
{
	int	i;

	i = 0;
	while (token[++i])
	{
		printf("%s ", token[i]);
	}
	if (!no_new_line)
		printf("\n");
	return (0);
}
