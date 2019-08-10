/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtparse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 12:19:52 by ymoukhli          #+#    #+#             */
/*   Updated: 2019/08/09 14:15:12 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTPARSE_H
# define RTPARSE_H
# include "./libft/includes/libft.h"
# include "stdio.h"
# include "rtv1.h"

void		ft_freeobj(t_obj **obj);
char		*ft_pick_str(char *str, char *start, char *end);
char		*ft_nextnum(char *p);
t_obj		*ft_new_obj(t_obj *obj, char *str_file);
void		ft_putobj(t_obj **obj, t_obj *n_obj);
t_vect		ft_stock_vec(char *p_obj, char *to_pick, int num);
void		ft_strlower(char *str);
char		*ft_pobj_str(char *str, char *start, char *end);
char		ft_check_plane(char *obj);
t_sce		ft_stock_scene(char *str_file);
void		ft_stock_plane(t_obj **obj, char *str_file, char *p_obj, int *a);
t_vect		ft_stock_vec(char *p_obj, char *to_pick, int num);
t_obj		*ft_stock_obj(char *str_file);
int			ft_error(char **p_free, int i);
int			ft_cam_check(char *str_file);
char		*ft_pick_str(char *str, char *start, char *end);
char		*ft_obj_pick_str(char *str, char *start, char end, char skip_end);
int			ft_obj_check(char *str_file);
int			ft_check(char *str, char *pick, int nnum);
int			ft_light_check(char *str_file);
char		*ft_file(char *file_name);
int			ft_check_file(char *file_name);
t_config	ft_parse_file(char *str);
void		ft_test(void);
#endif
