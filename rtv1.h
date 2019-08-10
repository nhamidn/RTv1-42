/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:32:17 by nhamid            #+#    #+#             */
/*   Updated: 2019/08/08 19:08:44 by nhamid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "libft/includes/libft.h"
# include <unistd.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <fcntl.h>
# define BUF_SIZE 100
# define HEIGHT 600
# define WIDTH 600
# define MAP_SIZE 1
# define INFINIT 1e5

typedef struct	s_vect
{
	float	x;
	float	y;
	float	z;
}				t_vect;

enum {sphere = 1, cone, cylinder, plane};
enum {trs = 1, rt, dir, col, pos, nor};

typedef struct	s_cam
{
	t_vect	ray;
	t_vect	pos;
	float	x;
	float	y;
	t_vect	hit_col;
}				t_cam;

typedef struct	s_var
{
	float a;
	float b;
	float c;
	float d;
	float t1;
	float t2;
}				t_var;

typedef struct	s_obj
{
	int				id;
	int				type;
	t_vect			pos;
	t_vect			trs;
	t_vect			rot;
	t_vect			col;
	t_vect			dir;
	float			rad;
	float			dif;
	t_vect			nor;
	struct s_obj	*next;
}				t_obj;

typedef struct	s_sce
{
	t_vect			cam_pos;
	t_vect			cam_rot;
	t_vect			cam_trs;
	t_vect			light_pos;
	float			power;
}				t_sce;

typedef struct	s_val
{
	float	dis;
	t_obj	obj;
	t_vect	col;
	float	m;
}				t_val;

typedef struct	s_config
{
	t_sce scene;
	t_obj *obj;
}				t_config;

typedef struct	s_params
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*file;
	unsigned char	*data;
	int				type;
	float			varx;
	float			vary;
	float			varz;
	t_vect			trans;
	double			x;
	double			y;
	double			vect_x;
	double			vect_y;
	int				endian;
	int				s_l;
	int				bpp;
	t_sce			*sce;
	t_obj			*obj;
}				t_params;

void			ft_o_free(t_params *init);
int				ft_tablen(char **arr);
void			rot_cam_event(int key, t_params *params);
void			tans_event(int key, t_params *params);
void			ft_init(t_params *params);
void			addnodes(t_obj *spher);
int				obj_check(char **arr);
void			ft_isobj(int *k, char *obj);
void			objects_translation(t_vect *pos, t_vect *trans);
void			ft_change_param(t_params *init);
void			ft_light(t_params *init, t_val *v, t_cam cam);
void			ft_parse_ray(t_cam cam, t_params *init);
t_obj			*ft_last_obj(t_obj *obj);
void			rot_x(t_vect *vect, float x);
void			rot_y(t_vect *vect, float y);
void			rot_z(t_vect *vect, float z);
void			rot(t_vect *vect, t_vect *angle);
void			trans(t_vect *cam, t_vect *trans);
void			ft_rot_cam(t_params *init);
t_cam			ft_camcam(t_params *init, t_cam cam, int x, int y);
float			ft_inter_cylinder(t_cam cam, t_obj obj, t_val *v);
void			ft_sphere(t_cam cam, t_obj obj, t_val *v, int i);
void			ft_plane(t_cam cam, t_obj obj, t_val *v, int i);
void			ft_cone(t_cam cam, t_obj obj, t_val *v, int i);
void			ft_cylinder(t_cam cam, t_obj obj, t_val *v, int i);
float			ft_inter_sphere(t_cam cam, t_obj obj);
float			ft_inter_plane(t_cam cam, t_obj obj);
float			ft_sqrs(float x);
float			ft_deg_to_rad(float angle);
float			ft_inter_cone(t_cam cam, t_obj obj, t_val *v);
float			ft_min_posi(float t1, float t2);
t_vect			ft_init_cam(void);
float			ft_map_x(int xx);
float			ft_map_y(int yy);
void			ft_light_pixel(t_params *init, t_val v, t_cam cam);
void			ft_free_arr(char **arr);
t_vect			ft_get_position(t_params *init);
float			vec_dot(t_vect v_1, t_vect v_0);
t_vect			vec_sum(t_vect v_1, t_vect v_0);
t_vect			vec_mult(float r, t_vect v_0);
t_vect			vec_sub(t_vect v_1, t_vect v_0);
t_vect			vec_normalise(t_vect v);
float			vec_module(t_vect v);
void			ft_calcule(t_params *init);
int				config_check(char *file_str, t_params *init);
int				red_cross(t_params *params);
int				key_press(int keycode, t_params *params);
int				get_next_line(const int fd, char **line);

#endif
