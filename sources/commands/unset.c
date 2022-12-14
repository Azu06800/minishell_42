/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:40:18 by emorvan           #+#    #+#             */
/*   Updated: 2022/12/14 15:30:36 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// TODO: If variable has been set, then delete it.
int	ft_unset(char **token)
{
	int	i;

	if (!token[0])
	{
		printf("unset: not enough arguments\n");
		return (1);
	}
	i = 0;
	while (token[i])
	{
		i++;
	}
	return (0);
}
