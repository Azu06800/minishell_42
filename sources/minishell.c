/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:59:43 by baroun            #+#    #+#             */
/*   Updated: 2022/12/14 16:46:11 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_freeall(char **token, char *str)
{
	int i;

	i = -1;
	while (token[++i])
		free(token[i]);
	free(token[i]);
	free(str);
	free(token);
}

void boucle()
{
	char *str;
	char **token;
	
	init_signal();
	while(1)
	{
		str = readline(prompt);
		if (*str == '\0')
			continue;
		if (!ft_isspace(*str))
			add_history(str);
		token = ft_lexer(str);
		tester_lexer(token);
		ft_parsing(token);
		ft_freeall(token, str);
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
