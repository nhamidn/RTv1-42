/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atois.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 20:21:36 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/11 21:23:27 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atois(char **sr)
{
	int		i;
	int		l;
	int		signe;
	char	*str;

	l = 0;
	i = 0;
	signe = 1;
	str = sr[0];
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			signe = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
		l = (l * 10) + ((int)str[i++] - '0');
	ft_mvadress(&sr[0], i);
	return (l * signe);
}
