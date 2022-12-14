/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:12:46 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/14 17:26:13 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(char **token)
{
	int	i;
	int	should_nl;

	i = 0;
	should_nl = 1;
	if (ft_strcmp(token[1], "-n"))
	{
		should_nl = 0;
		i++;
	}
	while (token[++i])
		printf("%s ", token[i]);
	if (should_nl)
		printf("\n");
	return (0);
}
