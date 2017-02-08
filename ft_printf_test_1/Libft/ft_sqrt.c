/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:37:56 by tapperce          #+#    #+#             */
/*   Updated: 2016/11/28 17:51:09 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int n)
{
	int		i;

	i = 0;
	while ((i * i) <= n)
	{
		if ((i * i) == n)
			return (i);
		i++;
	}
	return (0);
}