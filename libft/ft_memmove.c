/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 17:01:53 by ymoukhli          #+#    #+#             */
/*   Updated: 2018/10/13 19:17:41 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*s;
	char	*sp;
	size_t	i;

	s = (char *)dst;
	sp = (char *)src;
	i = len;
	if (s > sp)
	{
		while (i--)
		{
			s[i] = sp[i];
		}
	}
	else
		while (len--)
			*s++ = *sp++;
	return (dst);
}
