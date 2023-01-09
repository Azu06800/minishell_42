/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:59:43 by baroun            #+#    #+#             */
/*   Updated: 2023/01/09 20:09:43 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

pid_t	g_pid;

void	init_minishell(t_minishell *minishell, char **env)
{
	minishell->builtins = malloc(sizeof(char *) * 10);
	minishell->builtins[0] = "echo";
	minishell->builtins[1] = "cd";
	minishell->builtins[2] = "pwd";
	minishell->builtins[3] = "export";
	minishell->builtins[4] = "unset";
	minishell->builtins[5] = "env";
	minishell->builtins[6] = "exit";
	minishell->builtins[7] = "clear";
	minishell->builtins[8] = "history";
	minishell->builtins[9] = NULL;
	ft_initenv(minishell, env);
}

void	execute_from_args(t_minishell *minishell, char *arg)
{
	t_tokens		*tokens;
	t_parser_token	*parser_token;

	if (err_unclosed_quote(arg))
		return ;
	tokens = ft_lexer(arg);
	parser_token = ft_parse_tokens(tokentostr(tokens), minishell, tokens);
	ft_expander(parser_token, minishell);
	ft_executor(parser_token, minishell);
	g_pid = 0;
}

void	refresh_env(t_minishell *minishell)
{
	int		i;
	char	*tmp;

	i = 0;
	minishell->envp = malloc(sizeof(char *) * minishell->env_size);
	while (i < minishell->env_size)
	{
		tmp = ft_strjoin(minishell->env[i].name, "=");
		tmp = ft_strjoin(tmp, minishell->env[i].value);
		tmp = ft_strjoin(tmp, "\0");
		minishell->envp[i] = ft_strdup(tmp);
		free(tmp);
		i++;
	}
	minishell->envp[i] = NULL;
}

void	shell(t_minishell *minishell)
{
	char			*str;
	t_parser_token	*parser_token;
	t_tokens		*tokens;

	init_signal();
	while (1)
	{
		refresh_env(minishell);
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
		parser_token = ft_parse_tokens(tokentostr(tokens), minishell, tokens);
		if (ft_validator(parser_token))
		{
			ft_expander(parser_token, minishell);
			print_token(parser_token);
			ft_executor(parser_token, minishell);
		}
		g_pid = 0;
	}
}

int	main(int ac, char **av, char **env)
{
	t_minishell	*minishell;

	if (ac >= 3 && !ft_strcmp(av[1], "-c"))
	{
		minishell = malloc(sizeof(t_minishell));
		if (!minishell)
			return (0);
		init_minishell(minishell, env);
		execute_from_args(minishell, av[2]);
		return (0);
	}
	minishell = malloc(sizeof(t_minishell));
	if (!minishell)
		return (0);
	init_minishell(minishell, env);
	shell(minishell);
	return (1);
}
