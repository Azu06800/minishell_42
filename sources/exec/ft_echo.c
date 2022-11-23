/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:40:01 by baroun            #+#    #+#             */
/*   Updated: 2022/11/22 16:35:29 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/*void echo_print(char **token,int i)
{

}*/
void	ft_echo(char **token)
{
	int	i;

	i = 0;

	//if ())
		//option -n
	while (token[++i])
		printf("%s ",token[i]);
	printf("\n");
}


