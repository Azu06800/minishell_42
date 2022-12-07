/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:41:09 by emorvan           #+#    #+#             */
/*   Updated: 2022/05/02 13:28:37 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strdup(const char *src)
{
	char	*target;
	int		i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	target = malloc(sizeof(char) * (i + 1));
	if (target == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		target[i] = src[i];
		i++;
	}
	target[i] = '\0';
	return (target);
}
