/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:07:03 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/07/12 12:17:46 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rot(t_vect *vect, t_vect *angle)
{
	rot_x(vect, ft_deg_to_rad(angle->x));
	rot_y(vect, ft_deg_to_rad(angle->y));
	rot_z(vect, ft_deg_to_rad(angle->z));
}

void	trans(t_vect *cam, t_vect *trans)
{
	cam->x += trans->x;
	cam->y += trans->y;
	cam->z += trans->z;
}

void	ft_rot_cam(t_params *init)
{
	init->sce->cam_rot.x += init->varx;
	init->sce->cam_rot.y += init->vary;
	init->sce->cam_rot.z += init->varz;
}

t_cam	ft_camcam(t_params *init, t_cam cam, int x, int y)
{
	cam.ray.z = 1;
	cam.ray.y = ft_map_y(y);
	cam.ray.x = ft_map_x(x);
	rot(&cam.ray, &init->sce->cam_rot);
	cam.x = x;
	cam.y = y;
	cam.ray = vec_normalise(cam.ray);
	return (cam);
}

void	ft_calcule(t_params *init)
{
	int		x;
	int		y;
	t_cam	cam;

	ft_rot_cam(init);
	cam.pos = ft_get_position(init);
	trans(&cam.pos, &init->trans);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			cam = ft_camcam(init, cam, x, y);
			ft_parse_ray(cam, init);
			x++;
		}
		y++;
	}
}
