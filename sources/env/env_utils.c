/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:05:27 by emorvan           #+#    #+#             */
/*   Updated: 2023/01/09 16:07:59 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}

size_t	malloc_size(void *ptr)
{
	size_t	*size_ptr;
	size_t	size;

	size_ptr = (size_t *)ptr - 1;
	size = *size_ptr;
	return (size);
}

void *realloc(void *ptr, size_t size)
{
	if (size == 0)
	{
		free(ptr);
		return NULL;
	}
	if (!ptr)
	{
		return malloc(size);
	}
	void *new_ptr = malloc(size);
	if (!new_ptr)
	{
		return NULL;
	}
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return new_ptr;
}


int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (
		str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r'
	)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

void	print_env(t_minishell *minishell)
{
	char **envp = minishell->envp;

	while (*envp != NULL)
	{
		ft_putstr_fd(*envp, 1);
		ft_putstr_fd("\n", 1);
		envp++;
	}
}
