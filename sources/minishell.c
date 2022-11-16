/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:59:43 by baroun            #+#    #+#             */
/*   Updated: 2022/11/16 18:59:28 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void boucle()
{
	char *str;
	char **token;
	
	while(1)
	{
		str = readline(prompt);
		token = lexer(str);
		tester_lexer(token);
	}
}

int	main(int ac ,char **av ,char **envp)
{
	(void)ac;
	(void)av;
	(void) envp;//init env

	//init sign
	boucle();
		//parser
		//expander
		//excuter
}
