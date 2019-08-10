/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freedup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:02:02 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/11 21:22:09 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freedup(char *s)
{
	char	*s1;
	int		i;

	i = ft_strlen(s);
	if (!(s1 = (char *)malloc(i)))
		return (NULL);
	s1 = ft_strcpy(s1, s);
	free(s);
	return (s1);
}
