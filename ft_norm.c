/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 14:11:33 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/09 14:15:14 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtparse.h"

char	*ft_pick_str(char *str, char *start, char *end)
{
	int		i;
	char	*p_s;
	char	*p_e;
	char	*stri;

	i = 0;
	p_s = ft_strstr(str, start);
	if (p_s == NULL)
		return (NULL);
	if (p_s[1] != '\0')
		p_e = ft_strstr(p_s + 1, end);
	else
		return (NULL);
	if (p_s == NULL || p_e == NULL)
		return (NULL);
	i = p_e - p_s;
	stri = ft_strsub(p_s, 0, i + 1);
	return (stri);
}

char	ft_check_plane(char *obj)
{
	if (ft_check(obj, "pos:", 3) || ft_check(obj, "trs:", 3)
	|| ft_check(obj, "col:", 3) || ft_check(obj, "nor:", 3)
	|| ft_check(obj, "rot:", 3))
		return (-1);
	return (0);
}

void	ft_stock_plane(t_obj **obj, char *str_file, char *p_obj, int *a)
{
	t_obj *n_obj;

	n_obj = ft_new_obj(*obj, str_file);
	n_obj->type = plane;
	n_obj->id = *a;
	*a = *a + 1;
	n_obj->trs = ft_stock_vec(p_obj, "trs:", 3);
	n_obj->rot = ft_stock_vec(p_obj, "rot:", 3);
	n_obj->pos = ft_stock_vec(p_obj, "pos:", 3);
	n_obj->col = ft_stock_vec(p_obj, "col:", 3);
	n_obj->nor = ft_stock_vec(p_obj, "nor:", 3);
	ft_putobj(obj, n_obj);
}
