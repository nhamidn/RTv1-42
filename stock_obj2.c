/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_obj2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:05:49 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/09 14:07:49 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtparse.h"

void	ft_freeobj(t_obj **obj)
{
	while (*obj != NULL)
	{
		free(*obj);
		*obj = (*obj)->next;
	}
}

t_obj	*ft_new_obj(t_obj *obj, char *str_file)
{
	t_obj *new_obj;

	if (!(new_obj = (t_obj *)malloc(sizeof(t_obj))))
	{
		ft_strdel(&str_file);
		ft_freeobj(&obj);
		exit(0);
	}
	new_obj->next = NULL;
	return (new_obj);
}

char	*ft_nextnum(char *p)
{
	int i;

	i = 0;
	while (p[i] != 0 && ft_iswhit(p[i]) == 1)
		i++;
	if (p[i] == '-')
		i++;
	while (ft_isdigit(p[i]) == 1)
		i++;
	while (ft_isdigit(p[i]) == 0 && p[i] != 0 && p[i] != '-')
		i++;
	if (p[i] == 0)
		return (NULL);
	return (p + i);
}

t_vect	ft_stock_vec(char *p_obj, char *to_pick, int num)
{
	t_vect	vec;

	vec = (t_vect){0, 0, 0};
	p_obj = ft_strstr(p_obj, to_pick) + ft_strlen(to_pick);
	vec.x = ft_atoi(p_obj);
	p_obj = ft_nextnum(p_obj);
	if (num == 1)
		return (vec);
	vec.y = ft_atoi(p_obj);
	p_obj = ft_nextnum(p_obj);
	if (num == 2)
		return (vec);
	vec.z = ft_atoi(p_obj);
	return (vec);
}

void	ft_putobj(t_obj **obj, t_obj *n_obj)
{
	t_obj *p;

	p = *obj;
	if (*obj == NULL)
		*obj = n_obj;
	else
	{
		while (p->next != NULL)
			p = p->next;
		p->next = n_obj;
	}
}
