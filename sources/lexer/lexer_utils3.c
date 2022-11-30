/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:19:43 by baroun            #+#    #+#             */
/*   Updated: 2022/11/30 18:37:55 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlenspc(char *arg)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	while(arg[++i])
	{
		if (ft_isfle(arg[i]))
			j += 2;	
	}
	return (i + j);
}

char    *ft_add_spc(char *arg)
{
    char	*r;
    int		i;
    int		j;

    i = 0;
    j = 0;
    r = malloc((ft_strlenspc(arg)) * sizeof(char));
    while (arg[i])
    {
        if (ft_isfle(arg[i]))
        {
            r[j++] = ' ';
            r[j++] = arg[i++];
            r[j++] = ' ';
        }
        r[j++] = arg[i++];
    }
	r[j] = '\0';
    return (r);
}
