/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 10:40:26 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/22 14:15:43 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"

typedef struct		s_flag
{
	int				tiret;
	int				plus;
	int				espace;
	int				diese;
	int				zero;
}					t_flag;

typedef struct		s_width
{
	int				number;
}					t_width;

typedef struct		s_precision
{
	int				number;
}					t_precision;

typedef struct		s_lenght
{
	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;
}					t_lenght;

typedef struct		s_specifier
{
	int				c;
	int				cm;
	int				d;
	int				dm;
	int				i;
	int				o;
	int				om;
	int				s;
	int				sm;
	int				u;
	int				um;
	int				x;
	int				xm;
	int				p;
	int				pourcent;
}					t_specifier;

typedef struct		s_struc
{
	t_flag			*flag;
	t_width			*width;
	t_precision		*precision;
	t_lenght		*lenght;
	t_specifier		*specifier;
}					t_struc;

char				*ft_itoa_base(int n, int base);
char				*ft_unsigned_itoa(unsigned int n);
char				*ft_unsigned_itoa_base(unsigned int n, int base);
char				*ft_unsigned_itoa_base_m(unsigned int n, int base);
char				*ft_long_itoa_base(long n, int base);
char				*ft_unsigned_long_itoa_base(unsigned long n, int base);
char				*remalloc(char *dest, int len_f);

#endif
