/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:30:30 by ymoukhli          #+#    #+#             */
/*   Updated: 2018/10/12 17:10:41 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned long i;
	unsigned char *s;

	i = 0;
	if (!(s = (unsigned char *)malloc(size * sizeof(unsigned char))))
		return (NULL);
	while (i < size)
		s[i++] = 0;
	return (s);
}
