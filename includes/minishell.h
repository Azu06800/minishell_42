/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:29:39 by baroun            #+#    #+#             */
/*   Updated: 2022/11/25 16:30:16 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "minishell$ "
# include <readline/readline.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <sys/signal.h>
# include "../libft/libft.h"

typedef struct token
{
	struct token	*next;
	struct token	*prev;
	char			*str;
}	t_token;

typedef struct s_minishell
{
	char	*path;
	char	**env;
	char	**builtins;
}	t_minishell;

int		ft_isspace(int c);
int		is_in_env(char *cmd, t_minishell *ms);
void	set_path(t_minishell *ms);
char	*get_path(t_minishell *ms);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlen(const char *str);

// COMMANDS
int		ft_cd(char *cmd);
int		ft_echo(char *text, int no_new_line);
int		ft_env(void);
int		ft_exit(void);
int		ft_export(char *cmd);
int		ft_pwd(void);
int		ft_unset(char *name);

#endif
