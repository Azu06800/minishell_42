/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:59:43 by baroun            #+#    #+#             */
/*   Updated: 2022/12/01 17:16:55 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void boucle()
{
	char *str;
	char **token;
	
	signal(SIGINT, ctr_c);
	while(1)
	{
		str = readline(prompt);
		if (*str == '\0')
			continue;
		add_history(str);
		if (error_quote(str))
			continue;
		token = ft_lexer(str);
		free(str);
		tester_lexer(token);
		ft_parsing(token);
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
