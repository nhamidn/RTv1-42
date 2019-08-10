/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file8.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 20:48:03 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/08 19:20:05 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init(t_params *params)
{
	params->varx = 0;
	params->vary = 0;
	params->varz = 0;
	params->trans.x = 0;
	params->trans.y = 0;
	params->trans.z = 0;
	params->mlx_ptr = mlx_init();
	params->win_ptr = mlx_new_window(params->mlx_ptr, WIDTH, HEIGHT, "RTv1");
	params->img_ptr = mlx_new_image(params->mlx_ptr, WIDTH, HEIGHT);
	params->data = (unsigned char *)mlx_get_data_addr(params->img_ptr,
			&params->bpp, &params->s_l, &params->endian);
}

int		red_cross(t_params *params)
{
	(void)params;
	exit(0);
	return (0);
}

int		key_press(int key, t_params *params)
{
	if (key == 53)
	{
		ft_o_free(params);
		mlx_destroy_image(params->mlx_ptr, params->img_ptr);
		mlx_destroy_window(params->mlx_ptr, params->win_ptr);
		exit(0);
	}
	return (0);
}
