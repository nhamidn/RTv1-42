/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 00:23:06 by ymoukhli          #+#    #+#             */
/*   Updated: 2018/10/13 00:56:57 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define CHECK(n)	n < 0 ? i : i + 1

static int		ft_size(int i)
{
	int j;

	j = 1;
	while (i > 9 || i < 0)
	{
		i = i / 10;
		j++;
	}
	return (j);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		i;
	int		ss;

	ss = 1;
	i = ft_size(n);
	if (!(s = (char *)malloc(i + 1)))
		return (NULL);
	if (n < 0)
	{
		ss = -1;
		s[0] = '-';
	}
	s[i--] = '\0';
	while (CHECK(n) > 0)
	{
		s[i--] = ((n % 10) * ss) + '0';
		if (n > 9 || n < -9)
			n = n / 10;
	}
	return (s);
}
