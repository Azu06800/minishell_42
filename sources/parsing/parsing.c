/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:26:52 by baroun            #+#    #+#             */
/*   Updated: 2022/11/17 16:59:41 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_parsing(char **token)
{
	if (cmp_str(token[0], "echo"))
		ft_echo(token);
	//else if (cmp_str(token[0],"cd"))
		//exec cd
	//else if (cmp_str(token[0],"pwd"))
		//exec pwd
	//else if (cmp_str(token[0],"export"))
		//exec export 
	//else if (cmp_str(token[0],"unset"))
		//exec unset 
	//else if (cmp_str(token[0],"env"))
		//exec env
	else if (cmp_str(token[0],"exit"))
		ft_exit(token);
	//else
}		//error
