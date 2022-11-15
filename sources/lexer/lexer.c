/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:54:34 by baroun            #+#    #+#             */
/*   Updated: 2022/11/15 15:21:47 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	check_type(char c)
{
	//check les / > | 
}

void	check_command(char arg)
{
	//check les command
}

void	lexer(char *arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		check_type(arg[i]);
}
