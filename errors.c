/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 23:37:11 by nhamid            #+#    #+#             */
/*   Updated: 2019/08/09 13:07:01 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtparse.h"

void	ft_error_2(char *str[14])
{
	str[5] = "error in plane function;\nshould be: plane {\npos:\
		n,n,n;\ntrs:n,n,n;\ncol: n,n,n;\nrot:n,n,n;\nnor:n,n,n;}\n";
	str[4] = "error in cone function;\nshould be: cone {\npos: n,n,n;\ntrs\
		:n,n,n;\ncol: n,n,n;\nrot:n,n,n;\ndir:n,n,n;\nang:n;}\n";
	str[3] = "error in cylinder function;\nshould be: cylinder {\npos: n,n,n;\
		\ntrs:n,n,n;\ncol: n,n,n;\nrot:n,n,n;\ndir:n,n,n;\nrad:n;}\n";
	str[2] = "error in sphere function;\nshould be: sphere {\n\
		pos: n,n,n;\ntrs:n,n,n;\ncol: n,n,n;\nrad:n;}\n";
}

int		ft_error(char **p_free, int i)
{
	char *str[14];

	str[0] = "error in light: \"int\" or \"pos\" are not included \
		or bad numbers are assigned\n";
	str[1] = "error in light: \"trs\",\"rot\",\"pos\" are not\
		included or bad numbers are assigned\n";
	str[10] = "couldn't find cam, in config file\nex:\ncam { pos:... }\n";
	str[11] = "couldn't find light, in config file\nex:\nlight\
		{ pos:...; int:...; }\n";
	str[12] = "bad obj syntax, in config file\nex:\nobj { sphere {...} }\n";
	str[13] = "Please enter the configuration file !\n./RTv1\
		< Configuration File >\n";
	str[9] = "obj or cam are in light { },,\nex: light {cam{}}\nsould \
		be: light {}cam{}\n";
	str[8] = "obj or light are in cam { },,\nex: cam {obj{}}\nsould be:\
		cam {}light{}\n";
	str[7] = "cam or light are in obj { },,\nex: obj {cam{}}\nsould be: \
		obj {}cam{}\n";
	str[6] = "no object found in obj { } function;\n";
	ft_error_2(str);
	ft_strdel(p_free);
	ft_putstr(str[i]);
	return (-1);
}
