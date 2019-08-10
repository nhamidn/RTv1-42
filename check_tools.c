/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:38:36 by nhamid            #+#    #+#             */
/*   Updated: 2019/08/09 14:12:54 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtparse.h"

char	*ft_pobj_str(char *str, char *start, char *end)
{
	char	*p_s;
	char	*p_e;

	p_s = ft_strstr(str, start);
	if (p_s == NULL)
		return (NULL);
	if (p_s[1] != '\0')
		p_e = ft_strstr(p_s + 1, end);
	else
		return (NULL);
	if (p_s == NULL || p_e == NULL)
		return (NULL);
	return (p_s);
}

void	ft_init_obj_pick(int *i, char *start, int *count, int *j)
{
	*i = ft_strlen(start);
	*count = 0;
	*j = 0;
}

char	*ft_obj_pick_str(char *str, char *start, char end, char skip_end)
{
	char	*p_s;
	int		i;
	int		count;
	int		j;

	if (!(p_s = ft_strstr(str, start)))
		return (NULL);
	ft_init_obj_pick(&i, start, &count, &j);
	while (p_s[i] != 0)
	{
		if (p_s[i] == end)
		{
			if (count == 0)
			{
				j = i;
				break ;
			}
			count != 0 ? count-- : count;
		}
		p_s[i] == skip_end ? count++ : count;
		i++;
	}
	if (j == 0)
		return (0);
	return (ft_strsub(p_s, 0, j + 1));
}

int		ft_check2(char *str_pick, int i, int *k)
{
	while (str_pick[i] != '\0')
	{
		if (str_pick[i] == '-' || str_pick[i] == '+')
			i++;
		if (ft_isdigit(str_pick[i]))
		{
			*k += 1;
			while (ft_isdigit(str_pick[i]))
				i++;
			if (str_pick[i] == '-' || str_pick[i] == '+')
				return (-1);
		}
		if (str_pick[i] == ';')
			return (i);
		else if (str_pick[i] != ',' && str_pick[i] != ' ' &&
				str_pick[i] != '\t' && str_pick[i] != '\n')
			return (-1);
		if (str_pick[i] != '\0')
			i++;
	}
	return (i);
}

int		ft_check(char *str, char *pick, int nnum)
{
	char	*str_pick;
	int		i;
	int		k;

	if (!(str_pick = ft_strstr(str, pick)))
		return (-1);
	i = ft_strlen(pick);
	k = 0;
	if (ft_check2(str_pick, i, &k) == -1)
		return (-1);
	if (k == nnum)
		return (0);
	return (-1);
}
