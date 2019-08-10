/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_scene.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 17:41:44 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/08 20:50:06 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtparse.h"

t_sce	ft_stock_scene(char *str_file)
{
	char	*str_scene;
	t_sce	scene;
	t_vect	v;

	str_scene = ft_strstr(str_file, "cam {");
	scene.cam_pos = ft_stock_vec(str_scene, "pos:", 3);
	scene.cam_rot = ft_stock_vec(str_scene, "rot:", 3);
	scene.cam_trs = ft_stock_vec(str_scene, "trs:", 3);
	str_scene = ft_strstr(str_file, "light {");
	scene.light_pos = ft_stock_vec(str_scene, "pos:", 3);
	v = ft_stock_vec(str_scene, "int:", 1);
	scene.power = v.x;
	return (scene);
}
