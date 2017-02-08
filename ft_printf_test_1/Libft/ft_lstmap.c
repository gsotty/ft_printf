/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:46:52 by tapperce          #+#    #+#             */
/*   Updated: 2016/11/24 18:10:56 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_lst;
	t_list	*list;

	begin_lst = NULL;
	while (lst)
	{
		if (!(list = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		list = f(lst);
		ft_lstputback(&begin_lst, list);
		lst = lst->next;
	}
	return (begin_lst);
}
