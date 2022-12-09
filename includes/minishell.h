/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 13:29:39 by baroun            #+#    #+#             */
/*   Updated: 2022/12/09 19:30:29 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

//------------------INCLUDES------------------//

# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <sys/wait.h>
# include <dirent.h>
# include <fcntl.h>

# include <stdio.h>


# define prompt "minishell$ "

//-------------------LEXER-------------------//
	//is
int	ft_isspace(int c);
int ft_issep(int c);
int	ft_isquote(int c);
int ft_isfle(int c);
	//malloc split
size_t	cpt_quote(char *s);
size_t	cpt_word(char *str, int a);
	//sep
char    *ft_remove_spcqu(char *arg);
char    *ft_add_spcqu(char *arg);
char    *ft_remove_spc(char *arg);
char    *ft_add_spc(char *arg);
	//split
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_lexer(char *arg);
char    **ft_lasttoken(char **token);

//-------------------PARSER-------------------//
int	cmp_str(char *str, char *cmp);
void	ft_parsing(char **token);

//--------------------EXEC--------------------//
void	ft_echo(char **token);
void	ft_exit(char **token);

//-------------------SIGNAL-------------------//
void	init_signal(void);

//-------------------ERROR-------------------//
int		error_quote(char *str);
char 	**listofcmd(void);
int		check_cmd(char *str);
int		ft_cmdcmp(char *s1, char **s2);
int		ft_strcmp(const char *s1, const char *s2);

//-------------------UTILS-------------------//
int	ft_cinstr(char *str, char c);
int ft_onlyspace(char *str);

//tester
void tester_lexer(char **token);


#endif
