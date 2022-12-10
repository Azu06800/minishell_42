/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:29:39 by baroun            #+#    #+#             */
/*   Updated: 2022/12/07 15:05:17 by emorvan          ###   ########.fr       */
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
//-------------------LEXER-------------------//
	//is
int	ft_isspace(int c);
int ft_issep(int c);
int	ft_isquote(int c);
int ft_isfle(int c);
	//malloc split
size_t	cpt_quote(char *s);
size_t cpt_word(char *str);
	//sep
int		ft_strlenspc(char *arg);
char    *ft_add_spc(char *arg);
	//split
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_lexer(char *arg);

//-------------------PARSER-------------------//
int	cmp_str(char *str, char *cmp);
void	ft_parsing(char **token);

//--------------------EXEC--------------------//
void	ft_echo(char **token);
void	ft_exit(char **token);

//-------------------SIGNAL-------------------//
void	ctrl_c(int sig);

//-------------------ERROR-------------------//
int		err_unclosed_quote(char *str);
char **listofcmd(void);
int		check_cmd(char *str, t_minishell *minishell);
int		ft_cmdcmp(char *s1, char **s2);
int	ft_strcmp(const char *s1, const char *s2);


//tester
void tester_lexer(char **token);

#endif
