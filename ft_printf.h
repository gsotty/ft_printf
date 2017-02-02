/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsotty <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 10:40:26 by gsotty            #+#    #+#             */
/*   Updated: 2017/02/02 10:06:27 by gsotty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./Libft/libft.h"
# include <stdarg.h>
# include <string.h>
# include <stdint.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_flag
{
	unsigned int	tiret : 1;
	unsigned int	plus : 1;
	unsigned int	espace : 1;
	unsigned int	diese : 1;
	unsigned int	zero : 1;
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
	unsigned int	h : 1;
	unsigned int	hh : 1;
	unsigned int	l : 1;
	unsigned int	ll : 1;
	unsigned int	j : 1;
	unsigned int	z : 1;
}					t_lenght;

typedef struct		s_specifier
{
	unsigned int	c : 1;
	unsigned int	cm : 1;
	unsigned int	d : 1;
	unsigned int	dm : 1;
	unsigned int	i : 1;
	unsigned int	o : 1;
	unsigned int	om : 1;
	unsigned int	s : 1;
	unsigned int	sm : 1;
	unsigned int	u : 1;
	unsigned int	um : 1;
	unsigned int	x : 1;
	unsigned int	xm : 1;
	unsigned int	p : 1;
	unsigned int	pourcent : 1;
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
	int				len_buf;
	int				len_str;
	int				pos_buf;
	int				pos_str;
}					t_len;

int					ft_printf(const char *str, ...);
int					write_buf(t_struc *struc, char **buf, t_len *len,
		va_list ap);
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
size_t				ft_wcstombs(char *dest, const wchar_t *src, size_t n);
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
int					write_sm(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_c(t_struc *struc, char **buf, t_len *len,
		va_list ap);
int					write_cm(t_struc *struc, char **buf, t_len *len,
		va_list ap);

#endif
