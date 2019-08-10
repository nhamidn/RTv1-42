/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:28:02 by nhamid            #+#    #+#             */
/*   Updated: 2019/08/08 19:18:16 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
{
	t_params params;

	if (argc == 2)
	{
		params.file = argv[1];
		config_check(params.file, &params);
		mlx_put_image_to_window(params.mlx_ptr, params.win_ptr,
				params.img_ptr, 0, 0);
		mlx_hook(params.win_ptr, 2, 1, key_press, &params);
		mlx_hook(params.win_ptr, 17, 1, red_cross, &params);
		mlx_loop(params.mlx_ptr);
	}
	else
	{
		ft_putstr("Please enter the configuration file !\n");
		ft_putstr("./RTv1 < Configuration File >\n");
	}
	return (0);
}
