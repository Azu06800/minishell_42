/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:59:43 by baroun            #+#    #+#             */
/*   Updated: 2023/01/10 13:15:25 by emorvan          ###   ########.fr       */
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

void	execute_from_args(char *arg)
{
	t_tokens		*tokens;
	t_parser_token	*parser_token;

	if (err_unclosed_quote(arg))
		return ;
	tokens = ft_lexer(arg);
	parser_token = ft_parse_tokens(tokentostr(tokens), tokens);
	ft_expander(parser_token);
	ft_executor(parser_token);
	g_minishell->cur_proc_pid = 0;
}

void	refresh_env()
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

void	shell()
{
	char			*str;
	t_parser_token	*parser_token;
	t_tokens		*tokens;

	init_signal();
	while (1)
	{
		refresh_env();
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
		tokens = ft_lexer(str);
		parser_token = ft_parse_tokens(tokentostr(tokens), tokens);
		if (ft_validator(parser_token))
		{
			ft_expander(parser_token);
			print_token(parser_token);
			ft_executor(parser_token);
		}
		g_minishell->cur_proc_pid = 0;
	}
}

int	main(int ac, char **av, char **env)
{
	g_minishell = malloc(sizeof(t_minishell));
	if (!g_minishell)
		return (0);
	init_minishell(env);
	if (ac >= 3 && !ft_strcmp(av[1], "-c"))
	{
		execute_from_args(av[2]);
		return (0);
	}
	shell();
	return (0);
}
