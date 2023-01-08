/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:31:26 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/08 18:59:19 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

pid_t	g_pid;

int	exec_builtin(t_parser_token *token, t_minishell *minishell)
{
	if (token->command[0] && !ft_strcmp(token->command[0], "echo"))
		return (ft_echo(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "cd"))
		return (ft_cd(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "pwd"))
		return (ft_pwd(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "export"))
		return (ft_export(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "unset"))
		return (ft_unset(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "env"))
		return (ft_env(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "exit"))
		return (ft_exit(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "clear"))
		return (ft_clear(token, minishell));
	else if (token->command[0] && !ft_strcmp(token->command[0], "history"))
		return (ft_history(token, minishell));
	return (2);
}

int execute_command(t_parser_token *token, int fd_in, int fd_out) {
	int pid = fork();
	int status;
	if (pid == 0) {
		char *command = token->command[0];
		char *args[token->command_size + 1];
		for (size_t i = 0; i < token->command_size; i++) {
			args[i] = token->command[i];
		}
		args[token->command_size] = NULL;
		if (fd_in != STDIN_FILENO) {
			dup2(fd_in, STDIN_FILENO);
			close(fd_in);
		}
		if (fd_out != STDOUT_FILENO) {
			dup2(fd_out, STDOUT_FILENO);
			close(fd_out);
		}
		if (execvp(command, args) < 0) {
			perror("Error executing command");
			return (1);
		}
	} else if (pid < 0) {
		perror("Error creating child process");
		return (1);
	} else {
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (1);
		}
	}
	return (0);
}

void execute_commands(t_parser_token *tokens) {
	int fd_in = STDIN_FILENO;
	int fd_out = STDOUT_FILENO;
	int	fd[2];
	
	for (int i = 0; tokens[i].type != TOKEN_END; i++) {
    	if (tokens[i].type == TOKEN_CMD) {
    		if (tokens[i + 1].type == TOKEN_REDIR && tokens[i + 1].redirection[0] == REDIR_PIPE) {
    			if (pipe(fd) < 0) {
    				perror("Error creating pipe");
    				exit(1);
    			}
    			fd_out = fd[1];
    		} else {
    			fd_out = STDOUT_FILENO;
    		}
    		execute_command(&tokens[i], fd_in, fd_out);
			if (fd_out != STDOUT_FILENO) {
      			close(fd_out);
      			fd_in = fd[0];
      		}
    	}
  	}
}


int	ft_executor(t_parser_token *tokens, t_minishell *minishell)
{
	(void)minishell;
	if (tokens[0].type == TOKEN_END)
		return (0);
	if (exec_builtin(tokens, minishell) == 2)
		execute_commands(tokens);
	return (0);
}
