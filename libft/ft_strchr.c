/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:13:58 by ymoukhli          #+#    #+#             */
/*   Updated: 2018/10/15 21:15:35 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;
	char	*v;

	i = 0;
	a = (char)c;
	v = (char *)s;
	while (v[i] != '\0')
	{
		if (v[i] == a)
			return (v + i);
		i++;
	}
	if (v[i] == a)
		return (v + i);
	return (0);
}
