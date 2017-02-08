/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstputback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:31:46 by tapperce          #+#    #+#             */
/*   Updated: 2017/01/05 15:54:15 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstputback(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!(*alst))
		*alst = new;
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
