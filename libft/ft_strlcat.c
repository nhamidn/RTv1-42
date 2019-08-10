/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:01:19 by ymoukhli          #+#    #+#             */
/*   Updated: 2018/10/12 00:18:08 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t t;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	while (dst[j] != '\0')
		j++;
	t = i + j;
	if (j > size)
		return (i + size);
	while (*src && j < size - 1)
		dst[j++] = *src++;
	dst[j] = '\0';
	return (t);
}
