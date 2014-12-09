/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:45:15 by jaguillo          #+#    #+#             */
/*   Updated: 2014/12/09 17:45:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			flag_b(t_string *out, t_opt *opt, va_list *ap)
{
	t_long			b;
	char			*binary;
	t_string		*tmp;

	b = get_unsigned_arg(opt, ap);
	binary = ft_itobase(b, "01");
	if (ft_strchr(opt->flags, '#') && b > 0)
	{
		tmp = ft_stringnews("0");
		ft_stringaddc(tmp, opt->format->name);
		ft_stringadd(tmp, binary);
		add_string(out, tmp->content, tmp->length, opt);
		ft_stringkil(tmp);
	}
	else
		add_string(out, binary, ft_strlen(binary), opt);
	free(binary);
}
