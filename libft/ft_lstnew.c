/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymoukhli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 17:14:01 by ymoukhli          #+#    #+#             */
/*   Updated: 2018/10/15 22:09:13 by ymoukhli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*s_new;

	if (!(s_new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	s_new->next = NULL;
	if (content == NULL)
	{
		s_new->content = NULL;
		s_new->content_size = 0;
	}
	else
	{
		if (!(s_new->content = malloc(content_size)))
		{
			free(s_new);
			return (NULL);
		}
		ft_memcpy(s_new->content, content, content_size);
		s_new->content_size = content_size;
	}
	return (s_new);
}
