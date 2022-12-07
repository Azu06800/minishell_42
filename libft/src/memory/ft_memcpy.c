/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emorvan <emorvan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 09:31:48 by emorvan           #+#    #+#             */
/*   Updated: 2022/05/02 13:28:37 by emorvan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_c;
	unsigned char	*src_c;

	if (!dst && !src)
		return (NULL);
	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	while (n--)
		*dst_c++ = *src_c++;
	return (dst);
}
