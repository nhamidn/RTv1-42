/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcule.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:30:43 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/23 17:05:55 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	ft_nor_cylinder(t_cam cam, t_val *v)
{
	t_vect nor;

	nor = vec_sub(cam.pos, v->obj.pos);
	nor = vec_sub(nor, vec_mult(v->m, v->obj.dir));
	nor = vec_normalise(nor);
	return (nor);
}

t_vect	ft_nor_cone(t_obj obj, t_cam cam, t_val *v)
{
	t_vect	nor;
	float	k;

	k = tan(ft_deg_to_rad(obj.dif) / 2.0);
	nor = vec_sub(cam.pos, v->obj.pos);
	nor = vec_sub(nor, vec_mult((1 + ft_sqrs(k)), vec_mult(v->m, v->obj.dir)));
	nor = vec_normalise(nor);
	return (nor);
}

void	ft_light_angle(t_val *v, t_cam cam)
{
	t_vect	nor;
	float	f;

	if (v->obj.type == plane)
		nor = v->obj.nor;
	if (v->obj.type == cone)
		nor = ft_nor_cone(v->obj, cam, v);
	if (v->obj.type == sphere)
		nor = vec_sub(cam.pos, v->obj.pos);
	if (v->obj.type == cylinder)
		nor = ft_nor_cylinder(cam, v);
	nor = vec_normalise(nor);
	f = vec_dot(nor, cam.ray);
	if (f < 0)
		f = 0;
	v->col = vec_mult(f, v->col);
}

int		ft_light_power(t_obj *obj, t_cam cam, t_val *v, float dist)
{
	while (obj)
	{
		if (obj->type == plane)
			ft_plane(cam, *obj, v, 0);
		if (obj->type == sphere)
			ft_sphere(cam, *obj, v, 0);
		if (obj->type == cylinder)
			ft_cylinder(cam, *obj, v, 0);
		if (obj->type == cone)
			ft_cone(cam, *obj, v, 0);
		if ((v->dis + 0.001) < dist)
			return (-1);
		obj = obj->next;
	}
	return (0);
}

void	ft_light(t_params *init, t_val *v, t_cam cam)
{
	t_sce	sce;
	t_obj	*obj;
	float	dist;

	obj = init->obj;
	v->dis -= 0.2;
	sce = *(init->sce);
	cam.pos = vec_sum(vec_mult(v->dis, cam.ray), cam.pos);
	cam.ray = vec_sub(sce.light_pos, cam.pos);
	dist = vec_module(cam.ray);
	cam.ray = vec_normalise(cam.ray);
	v->dis = INFINIT;
	if (ft_light_power(obj, cam, v, dist) == -1)
		v->col = vec_mult(0, v->col);
	else
		ft_light_angle(v, cam);
	ft_light_pixel(init, *v, cam);
}
