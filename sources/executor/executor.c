/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 22:31:26 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 15:26:15 by emorvan          ###   ########.fr       */
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
	return (0);
}

int	is_builtin(t_minishell *minishell, char *str)
{
	int	i;

	i = 0;
	while (minishell->builtins[i])
	{
		if (!ft_strcmp(str, minishell->builtins[i]))
			return (1);
		i++;
	}
	return (0);
}

int execute_command(t_parser_token *token, t_minishell *minishell, int fd_in, int fd_out) {
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
		if (execve(command, args, minishell->envp) < 0) {
			perror("Error executing command");
			exit(1);
		}
	} else if (pid < 0) {
		perror("Error creating child process");
		exit(1);
	} else {
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (1);
		}
	}
	return (0);
}

int execute_builtin(t_parser_token *token, t_minishell *minishell, int fd_in, int fd_out) {
	int pid = fork();
	int status;
	if (pid == 0) {
		if (fd_in != STDIN_FILENO) {
			dup2(fd_in, STDIN_FILENO);
			close(fd_in);
		}
		if (fd_out != STDOUT_FILENO) {
			dup2(fd_out, STDOUT_FILENO);
			close(fd_out);
		}
		if (exec_builtin(token, minishell) < 0) {
			perror("Error executing command");
			exit(1);
		}
	} else if (pid < 0) {
		perror("Error creating child process");
		exit(1);
	} else {
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (1);
		}
	}
	return (0);
}

char *read_heredoc(char *delimiter) {
	char *line = NULL;
	int len = 0;
	int delimiter_len = ft_strlen(delimiter);

	char *heredoc_content = malloc(1);
	if (heredoc_content == NULL) {
		perror("Error allocating memory for heredoc content");
		exit(1);
	}
	heredoc_content[0] = '\0';

	while ((line = readline("heredoc> ")) != NULL) {
		len = ft_strlen(line);
		if (len == delimiter_len && ft_strncmp(line, delimiter, delimiter_len) == 0) {
			break;
		}
		char *tmp = realloc(heredoc_content, ft_strlen(heredoc_content) + len + 2);
		if (tmp == NULL) {
			perror("Error reallocating memory for heredoc content");
			exit(1);
		}
		heredoc_content = tmp;
		ft_strcat(heredoc_content, line);
		ft_strcat(heredoc_content, "\n");
		free(line);
	}
	return heredoc_content;
}

int ft_executor(t_parser_token *tokens, t_minishell *minishell) {
	int fd_in = STDIN_FILENO;
	int fd_out = STDOUT_FILENO;
	int	fd[2];
	int skip_next_cmd = 0;
	t_parser_token *tmp;
	
	for (int i = 0; tokens[i].type != TOKEN_END; i++) {
    	if (tokens[i].type == TOKEN_CMD) {
			if (skip_next_cmd) {
				skip_next_cmd = 0;
				continue;
			}
    		if (tokens[i + 1].type == TOKEN_REDIR && tokens[i + 1].redirection[0] == REDIR_PIPE) {
    			if (pipe(fd) < 0) {
    				perror("Error creating pipe");
    				exit(1);
    			}
    			fd_out = fd[1];
    		} else if (tokens[i + 1].type == TOKEN_REDIR && tokens[i + 1].redirection[0] == REDIR_OUT) {
				tmp = &tokens[i + 2];
				skip_next_cmd = 1;
				fd_out = open(tmp->command[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			} else if (tokens[i + 1].type == TOKEN_REDIR && tokens[i + 1].redirection[0] == REDIR_APPEND) {
				tmp = &tokens[i + 2];
				skip_next_cmd = 1;
				fd_out = open(tmp->command[0], O_WRONLY | O_CREAT | O_APPEND, 0644);
			} else if (tokens[i + 1].type == TOKEN_REDIR && tokens[i + 1].redirection[0] == REDIR_IN) {
				tmp = &tokens[i + 2];
				skip_next_cmd = 1;
				fd_in = open(tmp->command[0], O_RDONLY);
			} else if (tokens[i + 1].type == TOKEN_REDIR && tokens[i + 1].redirection[0] == REDIR_HEREDOC) {
				char *delimiter = tokens[i + 2].command[0];
				char *heredoc_content = read_heredoc(delimiter);
				int fd = open("/tmp/heredoc_tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
				write(fd, heredoc_content, ft_strlen(heredoc_content));
				skip_next_cmd = 1;
				fd_in = open("/tmp/heredoc_tmp", O_RDONLY);
			}
			if (is_builtin(minishell, tokens[i].command[0]))
				execute_builtin(&tokens[i], minishell, fd_in, fd_out);
			else {
				//print_env(minishell);
				if (cmd_exists(&tokens[i], minishell)){
					execute_command(&tokens[i], minishell, fd_in, fd_out);
				}
				else
				{
					ft_putstr_fd("minishell: command not found: ", STDERR_FILENO);
					ft_putstr_fd(tokens[i].command[0], STDERR_FILENO);
					ft_putstr_fd("\n", STDERR_FILENO);
				}
			}
			if (fd_out != STDOUT_FILENO) {
      			close(fd_out);
      			fd_in = fd[0];
      		}
    	}
  	}
	return (0);
}
