/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file9.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 21:30:45 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/12 12:04:25 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	vec_sub(t_vect v_1, t_vect v_0)
{
	t_vect v;

	v.x = v_1.x - v_0.x;
	v.y = v_1.y - v_0.y;
	v.z = v_1.z - v_0.z;
	return (v);
}

float	vec_dot(t_vect v_1, t_vect v_0)
{
	t_vect	v;
	float	r;

	v.x = v_1.x * v_0.x;
	v.y = v_1.y * v_0.y;
	v.z = v_1.z * v_0.z;
	r = v.x + v.y + v.z;
	return (r);
}
