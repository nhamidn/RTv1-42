/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:00:07 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/11 20:24:17 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	ft_inter_sphere(t_cam cam, t_obj obj)
{
	t_vect	x;
	t_var	var;

	x = vec_sub(cam.pos, obj.pos);
	var.a = vec_dot(cam.ray, cam.ray);
	var.b = 2 * vec_dot(cam.ray, x);
	var.c = vec_dot(x, x) - (obj.rad * obj.rad);
	var.d = var.b * var.b - (4 * var.a * var.c);
	if (var.d < 0)
		return (INFINIT);
	var.t1 = (-var.b + sqrtf(var.d)) / (2 * var.a);
	var.t2 = (-var.b - sqrtf(var.d)) / (2 * var.a);
	if ((var.t1 < 0 && var.t2 < 0))
		return (INFINIT);
	return (ft_min_posi(var.t1, var.t2));
}

float	ft_inter_plane(t_cam cam, t_obj obj)
{
	t_vect	x;
	t_var	var;

	x = vec_sub(cam.pos, obj.pos);
	var.a = vec_dot(x, obj.nor);
	var.b = vec_dot(cam.ray, obj.nor);
	if (var.b == 0)
		return (INFINIT);
	var.d = -var.a / var.b;
	if (var.d > 0)
		return (var.d);
	return (INFINIT);
}

float	ft_sqrs(float x)
{
	return (x * x);
}

float	ft_deg_to_rad(float angle)
{
	return ((angle / 180.0) * M_PI);
}

float	ft_inter_cone(t_cam cam, t_obj obj, t_val *v)
{
	t_vect	x;
	t_var	var;
	float	k;
	float	t1;

	k = tan(ft_deg_to_rad(obj.dif) / 2.0);
	x = vec_sub(cam.pos, obj.pos);
	var.a = vec_dot(cam.ray, cam.ray) - ((1 + ft_sqrs(k)) *
			ft_sqrs(vec_dot(cam.ray, obj.dir)));
	var.b = 2.0 * (vec_dot(cam.ray, x) - (1 + ft_sqrs(k))
			* vec_dot(cam.ray, obj.dir) * vec_dot(x, obj.dir));
	var.c = vec_dot(x, x) - ((1 + ft_sqrs(k)) * ft_sqrs(vec_dot(x, obj.dir)));
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
