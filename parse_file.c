/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:16:25 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/09 14:05:32 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtparse.h"

int			ft_check_file(char *file_name)
{
	char *str_file;

	if ((str_file = ft_file(file_name)) == NULL)
	{
		ft_error(NULL, 13);
		exit(0);
	}
	ft_strlower(str_file);
	if (ft_light_check(str_file) == -1 ||
			ft_cam_check(str_file) == -1 ||
			ft_obj_check(str_file) == -1)
	{
		ft_strdel(&str_file);
		return (-1);
	}
	ft_strdel(&str_file);
	return (0);
}

t_config	ft_stock_file(char *file_name)
{
	char		*str_file;
	t_config	data;

	if ((str_file = ft_file(file_name)) == NULL)
		exit(0);
	ft_strlower(str_file);
	data.obj = ft_stock_obj(str_file);
	data.scene = ft_stock_scene(str_file);
	ft_strdel(&str_file);
	return (data);
}

t_config	ft_parse_file(char *file_name)
{
	t_config	data;

	if (ft_check_file(file_name) == -1)
		exit(0);
	data = ft_stock_file(file_name);
	return (data);
}
