/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:29:39 by baroun            #+#    #+#             */
/*   Updated: 2022/11/16 17:22:17 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define PROMPT "minishell$ "
# include <readline/readline.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct token
{
	struct token	*next;
	struct token	*prev;
	char			*str;
}	t_token;

typedef struct s_minishell
{
	char	*path;
}	t_minishell;

int		ft_isspace(int c);
int		is_in_env(char *cmd, t_minishell *ms);
void	set_path(t_minishell *ms);
char	*get_path(t_minishell *ms);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);

// COMMANDS
int		ft_pwd(void);
int		ft_echo(char *text, int no_new_line);
int		ft_exit(void);

#endif
