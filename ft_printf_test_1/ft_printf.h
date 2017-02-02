/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 10:40:26 by gsotty            #+#    #+#             */
/*   Updated: 2017/01/27 16:47:31 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

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
	t_flag			flag;
	t_width			width;
	t_precision		precision;
	t_lenght		lenght;
	t_specifier		specifier;
}					t_struc;

typedef struct		s_len
{
	int				len_str;
	int				pos_buf;
	int				pos_str;
}					t_len;

char				*ft_itoa_base(int n, int base);
char				*ft_unsigned_itoa(unsigned int n);
char				*ft_unsigned_itoa_base(unsigned int n, int base);
char				*ft_unsigned_itoa_base_m(unsigned int n, int base);
char				*ft_long_itoa_base(long n, int base);
char				*ft_unsigned_long_itoa_base(unsigned long n, int base);
char				*ft_unsigned_long_itoa_base_m(unsigned long n, int base);
char				*ft_intmax_t_itoa_base(intmax_t n, int base);
char				*ft_intmax_t_itoa_base_m(intmax_t n, int base);
char				*ft_remalloc(char *dest, int len_f);
int					check_specifier(t_struc *struc, const char *str, int z);
int					check_flag(t_struc *struc, const char *str, int z, int y);
int					check_width(t_struc *struc, const char *str, int z, int y);
int					check_precision(t_struc *struc, const char *str,
		int z, int y);
int					check_lenght(t_struc *struc, const char *str,
		int z, int y);
int					write_d_and_i(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_pourcent(t_struc *struc, char **buf, t_len *len);
int					write_o(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_om(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_x(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_xm(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_u(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_dm(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_p(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_um(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_s(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_c(t_struc *struc, char **buf, t_len *len,
		va_list ap);

#endif
