/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapperce <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:49:04 by tapperce          #+#    #+#             */
/*   Updated: 2016/11/23 13:52:02 by tapperce         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *nptr)
{
	int		result;
	int		i;
	int		neg;

	result = 0;
	neg = 0;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t' ||
			nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = 1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0')
	{
		result *= 10;
		result += nptr[i] - '0';
		i++;
	}
	if (neg == 1)
		return (-result);
	return (result);
}
