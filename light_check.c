/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:20:42 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/09 12:22:19 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtparse.h"

int		ft_light_check(char *str_file)
{
	char *light_str;

	if (!(light_str = ft_pick_str(str_file, "light {", "}")))
		return (ft_error(NULL, 11));
	if (ft_strstr(light_str, "cam {") != NULL || ft_strstr(light_str, "obj {"))
		return (ft_error(&light_str, 9));
	if (ft_check(light_str, "pos:", 3) || ft_check(light_str, "int:", 1))
		return (ft_error(&light_str, 0));
	ft_strdel(&light_str);
	return (1);
}
