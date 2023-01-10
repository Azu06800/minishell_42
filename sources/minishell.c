/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:59:43 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 18:43:02 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_minishell(char **env)
{
	g_minishell->builtins = malloc(sizeof(char *) * 10);
	g_minishell->builtins[0] = "echo";
	g_minishell->builtins[1] = "cd";
	g_minishell->builtins[2] = "pwd";
	g_minishell->builtins[3] = "export";
	g_minishell->builtins[4] = "unset";
	g_minishell->builtins[5] = "env";
	g_minishell->builtins[6] = "exit";
	g_minishell->builtins[7] = "clear";
	g_minishell->builtins[8] = "history";
	g_minishell->builtins[9] = NULL;
	ft_initenv(env);
}

void	refresh_env(void)
{
	int		i;
	char	*tmp;

	i = 0;
	g_minishell->envp = malloc(sizeof(char *) * g_minishell->env_size);
	while (i < g_minishell->env_size)
	{
		tmp = ft_strjoin(g_minishell->env[i].name, "=");
		tmp = ft_strjoin(tmp, g_minishell->env[i].value);
		tmp = ft_strjoin(tmp, "\0");
		g_minishell->envp[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	g_minishell->envp[i] = NULL;
	if (ft_getenv("PWD") == NULL)
		ft_modenv("PWD", getcwd(NULL, 0));
}

void	fetch_command(char *str, t_parser_token *parser_token, t_tokens *tokens)
{
	tokens = ft_lexer(str);
	parser_token = ft_parse_tokens(tokentostr(tokens), tokens);
	if (ft_validator(parser_token))
	{
		//ft_expander(parser_token);
		ft_executor(parser_token);
	}
}

void	shell(void)
{
	char			*str;
	t_parser_token	*parser_token;
	t_tokens		*tokens;

	parser_token = NULL;
	tokens = NULL;
	init_signal();
	while (1)
	{
		refresh_env();
		g_minishell->cur_proc_pid = 0;
		str = readline("minishell$ ");
		if (!str)
		{
			ft_putstr_fd("exit\n", 2);
			exit(0);
		}
		if (str == NULL || str[0] == '\0')
			continue ;
		add_history(str);
		if (err_unclosed_quote(str))
			continue ;
		fetch_command(str, parser_token, tokens);
	}
}

int	main(int ac, char **av, char **env)
{
	(void) ac;
	(void) av;
	g_minishell = malloc(sizeof(t_minishell));
	if (!g_minishell)
		return (0);
	init_minishell(env);
	shell();
	return (0);
}
