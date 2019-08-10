/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:03:43 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/11 20:24:17 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	ft_inter_cylinder(t_cam cam, t_obj obj, t_val *v)
{
	t_vect	x;
	t_var	var;
	float	t1;

	x = vec_sub(cam.pos, obj.pos);
	var.a = (vec_dot(cam.ray, cam.ray) - (vec_dot(cam.ray, obj.dir)
			* vec_dot(cam.ray, obj.dir)));
	var.b = 2 * (vec_dot(cam.ray, x) - (vec_dot(cam.ray, obj.dir)
				* vec_dot(x, obj.dir)));
	var.c = (vec_dot(x, x) - (vec_dot(x, obj.dir) *
				vec_dot(x, obj.dir)) - (obj.rad * obj.rad));
	var.d = var.b * var.b - (4 * var.a * var.c);
	if (var.d < 0)
		return (INFINIT);
	var.t1 = (-var.b + sqrtf(var.d)) / (2 * var.a);
	var.t2 = (-var.b - sqrtf(var.d)) / (2 * var.a);
	if ((var.t1 < 0 && var.t2 < 0))
		return (INFINIT);
	t1 = ft_min_posi(var.t1, var.t2);
	t1 -= 0.2;
	if (t1 < v->dis)
		v->m = vec_dot(cam.ray, obj.dir) * t1 + (vec_dot(x, obj.dir));
	return (ft_min_posi(var.t1, var.t2));
}

void	ft_sphere(t_cam cam, t_obj obj, t_val *v, int i)
{
	float distance;

	distance = ft_inter_sphere(cam, obj);
	if (v->dis > distance)
	{
		v->dis = distance;
		if (i == 1)
			v->obj = obj;
	}
}

void	ft_plane(t_cam cam, t_obj obj, t_val *v, int i)
{
	float distance;

	distance = ft_inter_plane(cam, obj);
	if (v->dis > distance)
	{
		v->dis = distance;
		if (i == 1)
			v->obj = obj;
	}
}

void	ft_cone(t_cam cam, t_obj obj, t_val *v, int i)
{
	float distance;

	distance = ft_inter_cone(cam, obj, v);
	if (v->dis > distance)
	{
		v->dis = distance;
		if (i == 1)
			v->obj = obj;
	}
}

void	ft_cylinder(t_cam cam, t_obj obj, t_val *v, int i)
{
	float distance;

	distance = ft_inter_cylinder(cam, obj, v);
	if (v->dis > distance)
	{
		v->dis = distance;
		if (i == 1)
			v->obj = obj;
	}
}
