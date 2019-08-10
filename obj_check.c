/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:10:39 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/09 14:12:19 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtparse.h"

char	ft_check_cone(char *obj)
{
	if (ft_check(obj, "pos:", 3) || ft_check(obj, "trs:", 3)
	|| ft_check(obj, "col:", 3) || ft_check(obj, "dir:", 3)
	|| ft_check(obj, "rot:", 3) || ft_check(obj, "ang:", 1))
		return (-1);
	return (0);
}

char	ft_check_sphere(char *obj)
{
	if (ft_check(obj, "pos:", 3) || ft_check(obj, "trs:", 3)
	|| ft_check(obj, "col:", 3) || ft_check(obj, "rad:", 1))
		return (-1);
	return (0);
}

char	ft_check_cylinder(char *obj)
{
	if (ft_check(obj, "pos:", 3) || ft_check(obj, "trs:", 3)
	|| ft_check(obj, "col:", 3) || ft_check(obj, "dir:", 3)
	|| ft_check(obj, "rot:", 3) || ft_check(obj, "rad:", 1))
		return (-1);
	return (0);
}

int		ft_check_objects(char *obj_str)
{
	char *obj;

	obj = obj_str;
	while ((obj = ft_pobj_str(obj + 1, "plane {", "}")) != NULL)
		if (ft_check_plane(obj))
			return (ft_error(NULL, 5));
	obj = obj_str;
	while ((obj = ft_pobj_str(obj + 1, "cone {", "}")) != NULL)
		if (ft_check_cone(obj))
			return (ft_error(NULL, 4));
	obj = obj_str;
	while ((obj = ft_pobj_str(obj + 1, "cylinder {", "}")) != NULL)
		if (ft_check_cylinder(obj))
			return (ft_error(NULL, 3));
	obj = obj_str;
	while ((obj = ft_pobj_str(obj + 1, "sphere {", "}")) != NULL)
	{
		if (ft_check_sphere(obj))
			return (ft_error(NULL, 2));
	}
	ft_strdel(&obj_str);
	return (0);
}

int		ft_obj_check(char *str_file)
{
	char *obj_str;

	if (!(obj_str = ft_obj_pick_str(str_file, "obj {", '}', '{')))
		return (ft_error(NULL, 12));
	if (ft_strstr(obj_str, "cam {") != NULL || ft_strstr(obj_str, "light {"))
		return (ft_error(&obj_str, 7));
	if (ft_strstr(obj_str, "plane {") == NULL &&
			ft_strstr(obj_str, "sphere {") == NULL &&
			ft_strstr(obj_str, "cylinder {") == NULL &&
			ft_strstr(obj_str, "cone {") == NULL)
		return (ft_error(&obj_str, 6));
	return (ft_check_objects(obj_str));
}
