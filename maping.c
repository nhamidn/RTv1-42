/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 19:52:42 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/11 20:24:16 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_light_pixel(t_params *init, t_val v, t_cam cam)
{
	int i;

	if (cam.x < 0 || cam.y < 0 || cam.y > HEIGHT || cam.x > WIDTH)
		return ;
	i = (cam.x * 4) + (cam.y * WIDTH * 4);
	init->data[i] = (unsigned char)v.col.z;
	init->data[i + 1] = (unsigned char)v.col.y;
	init->data[i + 2] = (unsigned char)v.col.x;
}

float	ft_map_x(int xx)
{
	float x;

	x = ((float)xx * (float)MAP_SIZE / WIDTH) - 0.5;
	return (x);
}

float	ft_map_y(int yy)
{
	float	y;

	y = ((float)yy * (float)MAP_SIZE / HEIGHT) - 0.5;
	return (y);
}

t_vect	ft_init_cam(void)
{
	t_vect	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	return (v);
}

float	ft_min_posi(float t1, float t2)
{
	if (t1 < t2)
	{
		if (t1 > 0)
			return (t1);
		else
			return (t2);
	}
	else if (t1 > t2)
	{
		if (t2 > 0)
			return (t2);
		else
			return (t1);
	}
	return (INFINIT);
}
