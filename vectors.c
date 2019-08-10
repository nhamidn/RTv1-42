/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:08:11 by nhamid            #+#    #+#             */
/*   Updated: 2019/07/11 21:30:30 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float	ft_sqr(float x)
{
	return (x * x);
}

float	vec_module(t_vect v)
{
	float x;
	float y;
	float z;
	float mod;

	x = ft_sqr(v.x);
	y = ft_sqr(v.y);
	z = ft_sqr(v.z);
	mod = sqrtf(x + y + z);
	return (mod);
}

t_vect	vec_normalise(t_vect v)
{
	t_vect	rv;
	float	mod;

	mod = vec_module(v);
	rv.x = v.x / mod;
	rv.y = v.y / mod;
	rv.z = v.z / mod;
	return (rv);
}

t_vect	vec_mult(float r, t_vect v_0)
{
	t_vect v;

	v.x = r * v_0.x;
	v.y = r * v_0.y;
	v.z = r * v_0.z;
	return (v);
}

t_vect	vec_sum(t_vect v_1, t_vect v_0)
{
	t_vect v;

	v.x = v_1.x + v_0.x;
	v.y = v_1.y + v_0.y;
	v.z = v_1.z + v_0.z;
	return (v);
}
