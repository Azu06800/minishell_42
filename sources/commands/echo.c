/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:12:46 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/14 17:54:47 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_echo(char **token)
{
	int	i;
	int	should_nl;
	int	start;

	i = 0;
	start = 0;
	should_nl = 1;
	if (ft_strcmp(token[1], "-n"))
	{
		should_nl = 0;
		i++;
	}
	
	while (token[++i])
		print()
		printf("%s", token[i]);
	if (should_nl)
		printf("\n");
	return (0);
}
