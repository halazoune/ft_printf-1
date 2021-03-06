/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 11:23:37 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/09 09:26:58 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include "libft.h"

# include <stdarg.h>
# include <wchar.h>

# define HASF(c)	(ft_strchr(opt->flags, (c)) != NULL)

# define LONG_BUFF	(40)

typedef struct	s_ldouble_bits
{
	t_ulong			fract:64;
	t_uint			e:15;
	t_bool			sign:1;
}				t_ldouble_bits;

typedef union	u_ldouble
{
	t_ldouble_bits	b;
	long double		d;
}				t_ldouble;

# define EXP(d)		((((t_ldouble)(d)).b).e)

typedef struct	s_format
{
	char			name;
	void			(*func)();
	char			*disabled;
}				t_format;

typedef struct	s_opt
{
	char			*flags;
	int				width;
	int				preci;
	t_bool			preci_set;
	char const		*length;
	t_format		*format;
}				t_opt;

typedef struct	s_meta
{
	char			*name;
	char			*value;
}				t_meta;

/*
** parser.c
*/
void			parsef(t_string *out, const char *format, va_list *ap);

/*
** parse_format.c
*/
int				parse_format(t_string *out, const char *format, va_list *ap);

/*
** parse_meta.c
*/
int				parse_meta(t_string *out, const char *format);

/*
** ftutils.c
*/
void			ft_stringaddupper(t_string *str, const char *add, int len);
void			ft_stringaddlower(t_string *str, const char *add, int len);
int				ft_atoin(const char *str, int len);

/*
** utils.c
*/
void			add_string(t_string *out, const char *add, int len, t_opt *opt);
void			add_nchar(t_string *out, char c, int len, t_opt *opt);
void			pad_preci(t_string *str, int start, t_opt *opt);
t_bool			is_separator(char c);
void			clear_dis(t_opt *opt);

/*
** wutils.c
*/
t_uint			ft_wstrlen(wchar_t *wstr);
int				ft_wstrconv(char *buff, wchar_t *wstr);
int				ft_wstrnconv(char *buff, wchar_t *wstr, int n);
int				ft_widetoa(char *buff, wchar_t w);

/*
** argsutils.c
*/
t_long			get_arg(t_opt *opt, va_list *ap);
t_ulong			get_unsigned_arg(t_opt *opt, va_list *ap);
long double		get_float_arg(t_opt *opt, va_list *ap);

/*
** flags
*/
void			flag_percent(t_string *out, t_opt *opt, va_list *ap);
void			flag_s(t_string *out, t_opt *opt, va_list *ap);
void			flag_d(t_string *out, t_opt *opt, va_list *ap);
void			flag_o(t_string *out, t_opt *opt, va_list *ap);
void			flag_u(t_string *out, t_opt *opt, va_list *ap);
void			flag_x(t_string *out, t_opt *opt, va_list *ap);
void			flag_c(t_string *out, t_opt *opt, va_list *ap);
void			flag_n(t_string *out, t_opt *opt, va_list *ap);
void			flag_p(t_string *out, t_opt *opt, va_list *ap);
void			flag_e(t_string *out, t_opt *opt, va_list *ap);
void			flag_f(t_string *out, t_opt *opt, va_list *ap);
void			flag_b(t_string *out, t_opt *opt, va_list *ap);
void			flag_r(t_string *out, t_opt *opt, va_list *ap);
void			flag_g(t_string *out, t_opt *opt, va_list *ap);

#endif
