/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:09:31 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/16 11:01:05 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_parse_ray(t_cam cam, t_params *init)
{
	t_obj	*obj;
	t_val	*v;

	v = (t_val *)malloc(sizeof(t_val));
	v->dis = INFINIT;
	obj = init->obj;
	while (obj)
	{
		if (obj->type == plane)
			ft_plane(cam, *obj, v, 1);
		if (obj->type == sphere)
			ft_sphere(cam, *obj, v, 1);
		if (obj->type == cylinder)
			ft_cylinder(cam, *obj, v, 1);
		if (obj->type == cone)
			ft_cone(cam, *obj, v, 1);
		obj = obj->next;
	}
	if (v->dis < INFINIT)
	{
		v->col = v->obj.col;
		ft_light(init, v, cam);
	}
	free(v);
}

t_vect	ft_get_position(t_params *init)
{
	t_vect pos;

	pos.x = init->sce->cam_pos.x + init->sce->cam_trs.x;
	pos.y = init->sce->cam_pos.y + init->sce->cam_trs.y;
	pos.z = init->sce->cam_pos.z + init->sce->cam_trs.z;
	return (pos);
}

void	rot_x(t_vect *vect, float x)
{
	t_vect	tmp;

	tmp.x = vect->x;
	tmp.y = vect->y * cos(x) - vect->z * sin(x);
	tmp.z = vect->y * sin(x) + vect->z * cos(x);
	*vect = tmp;
}

void	rot_y(t_vect *vect, float y)
{
	t_vect	tmp;

	tmp.x = vect->x * cos(y) + vect->z * sin(y);
	tmp.y = vect->y;
	tmp.z = vect->x * -sin(y) + vect->z * cos(y);
	*vect = tmp;
}

void	rot_z(t_vect *vect, float z)
{
	t_vect	tmp;

	tmp.x = vect->x * cos(z) - vect->y * sin(z);
	tmp.y = vect->x * sin(z) + vect->y * cos(z);
	tmp.z = vect->z;
	*vect = tmp;
}
