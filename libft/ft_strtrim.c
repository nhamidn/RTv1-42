/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 16:45:44 by ymoukhli          #+#    #+#             */
/*   Updated: 2018/10/15 21:15:40 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*c;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
	{
		if (!(c = (char *)malloc(1)))
			return (NULL);
		c[0] = '\0';
		return (c);
	}
	while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
		j--;
	if (!(c = ft_strsub(s, i, j - i)))
		return (NULL);
	return (c);
}
