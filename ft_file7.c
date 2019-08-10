/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file7.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:43:39 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/08 20:13:16 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rtparse.h"
#include "rtv1.h"

void	objects_translation(t_vect *pos, t_vect *trans)
{
	pos->x += trans->x;
	pos->y += trans->y;
	pos->z += trans->z;
}

void	ft_change_param(t_params *init)
{
	t_obj	*obj;
	t_cam	cam;
	float	f;

	cam.pos = ft_get_position(init);
	obj = init->obj;
	while (obj)
	{
		objects_translation(&obj->pos, &obj->trs);
		if (obj->type == plane)
		{
			obj->nor = vec_normalise(obj->nor);
			f = vec_dot(obj->nor, vec_normalise(vec_sub(cam.pos, obj->pos)));
			if (f < 0)
				obj->nor = vec_mult(-1, obj->nor);
			rot(&obj->nor, &obj->rot);
		}
		else
		{
			obj->dir = vec_normalise(obj->dir);
			rot(&obj->dir, &obj->rot);
		}
		obj = obj->next;
	}
}

int		config_check(char *file_name, t_params *init)
{
	t_config data;

	data = ft_parse_file(file_name);
	init->sce = &(data.scene);
	init->obj = data.obj;
	ft_change_param(init);
	ft_init(init);
	ft_calcule(init);
	return (1);
}
