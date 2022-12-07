/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:54:39 by emorvan           #+#    #+#             */
/*   Updated: 2022/06/21 18:27:28 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libft.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	len;

	if (s == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}

int	ft_putnbr(int nbr)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(nbr);
	printf("[%s]", num);
	len = ft_putstr(num);
	free(num);
	return (len);
}
