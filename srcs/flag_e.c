/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:11:25 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/02 16:24:38 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>

void			flag_e(t_string *out, t_opt *opt, va_list *ap)
{
	long double		e;
	t_string		str;

	e = get_float_arg(opt, ap);
	ft_stringini(&str);
	if (HASF('+') && e >= 0)
		ft_stringaddc(&str, '+');
	else if (HASF(' ') && e >= 0)
		ft_stringaddc(&str, ' ');
	ft_stringaddde(&str, e, (opt->preci_set) ? opt->preci : 6);
	if (opt->format->name == 'E')
		ft_strupper(str.content);
	add_string(out, str.content, str.length, opt);
	free(str.content);
}
