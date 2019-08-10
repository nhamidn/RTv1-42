/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:37:28 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/04/18 18:03:38 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenth(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s1_2;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = ft_lenth((char *)s1);
	while (s2[j++] != '\0')
		i++;
	if (!(s1_2 = (char *)malloc(i + 1)))
		return (NULL);
	s1_2 = ft_strcpy(s1_2, s1);
	s1_2 = ft_strcat(s1_2, s2);
	return (s1_2);
}
