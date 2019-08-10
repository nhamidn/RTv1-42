/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:06:15 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/09 14:11:57 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtparse.h"

void	ft_stock_sphere(t_obj **obj, char *str_file, char *p_obj, int *a)
{
	t_obj	*n_obj;
	t_vect	v;

	n_obj = ft_new_obj(*obj, str_file);
	n_obj->type = sphere;
	n_obj->id = *a;
	*a = *a + 1;
	n_obj->trs = ft_stock_vec(p_obj, "trs:", 3);
	n_obj->pos = ft_stock_vec(p_obj, "pos:", 3);
	n_obj->col = ft_stock_vec(p_obj, "col:", 3);
	v = ft_stock_vec(p_obj, "rad:", 1);
	n_obj->rad = v.x;
	ft_putobj(obj, n_obj);
}

void	ft_stock_cylinder(t_obj **obj, char *str_file, char *p_obj, int *a)
{
	t_obj	*n_obj;
	t_vect	v;

	n_obj = ft_new_obj(*obj, str_file);
	n_obj->type = cylinder;
	n_obj->id = *a;
	*a = *a + 1;
	n_obj->trs = ft_stock_vec(p_obj, "trs:", 3);
	n_obj->pos = ft_stock_vec(p_obj, "pos:", 3);
	n_obj->col = ft_stock_vec(p_obj, "col:", 3);
	n_obj->dir = ft_stock_vec(p_obj, "dir:", 3);
	n_obj->rot = ft_stock_vec(p_obj, "rot:", 3);
	v = ft_stock_vec(p_obj, "rad:", 1);
	n_obj->rad = v.x;
	ft_putobj(obj, n_obj);
}

void	ft_stock_cone(t_obj **obj, char *str_file, char *p_obj, int *a)
{
	t_obj	*n_obj;
	t_vect	v;

	n_obj = ft_new_obj(*obj, str_file);
	n_obj->type = cone;
	n_obj->id = *a;
	*a = *a + 1;
	n_obj->trs = ft_stock_vec(p_obj, "trs:", 3);
	n_obj->pos = ft_stock_vec(p_obj, "pos:", 3);
	n_obj->col = ft_stock_vec(p_obj, "col:", 3);
	n_obj->dir = ft_stock_vec(p_obj, "dir:", 3);
	n_obj->rot = ft_stock_vec(p_obj, "rot:", 3);
	v = ft_stock_vec(p_obj, "ang:", 1);
	n_obj->dif = v.x;
	ft_putobj(obj, n_obj);
}

void	ft_strlower(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] = str[i] - 'A' + 'a';
		i++;
	}
}

t_obj	*ft_stock_obj(char *str_file)
{
	char	*str_obj;
	char	*p_obj;
	t_obj	*obj;
	int		a;

	a = 0;
	obj = NULL;
	str_obj = ft_strstr(str_file, "obj {");
	ft_strlower(str_obj);
	p_obj = str_obj;
	while ((p_obj = ft_strstr(p_obj + 1, "plane {")) != NULL)
		ft_stock_plane(&obj, str_file, p_obj, &a);
	p_obj = str_obj;
	while ((p_obj = ft_strstr(p_obj + 1, "cone {")) != NULL)
		ft_stock_cone(&obj, str_file, p_obj, &a);
	p_obj = str_obj;
	while ((p_obj = ft_strstr(p_obj + 1, "cylinder {")) != NULL)
		ft_stock_cylinder(&obj, str_file, p_obj, &a);
	p_obj = str_obj;
	while ((p_obj = ft_strstr(p_obj + 1, "sphere {")) != NULL)
		ft_stock_sphere(&obj, str_file, p_obj, &a);
	return (obj);
}
