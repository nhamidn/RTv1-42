/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stmdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 12:25:52 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/11 21:20:21 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stmdup(char *str, int j)
{
	int		i;
	char	*s;

	i = ft_strlen(str);
	s = (char *)malloc(i - j);
	i = 0;
	while (str[i + j] != '\0')
	{
		s[i] = str[i + j];
		i++;
	}
	s[i] = '\0';
	return (s);
}
