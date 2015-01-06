/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 19:47:13 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/06 11:39:12 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void			add_string(t_string *out, const char *add, int len, t_opt *opt)
{
	char			*left;
	char			*center;
	char			*start;

	left = ft_strrchr(opt->flags, '-');
	center = ft_strrchr(opt->flags, '^');
	start = ft_strrchr(opt->flags, '>');
	center = (center > left && center > start) ? center : NULL;
	left = (left > center && left > start) ? left : NULL;
	start = (start > center && start > left) ? start : NULL;
	if ((left == NULL && opt->width > 0 && start == NULL) || center != NULL)
		ft_stringaddcn(out, ' ', ((center != NULL) ? (opt->width - len) / 2 :
			opt->width - len));
	else if (start != NULL)
		ft_stringaddcn(out, ' ', opt->width - out->length);
	if (ft_strrchr(opt->flags, 'M') != NULL)
		ft_stringaddupper(out, add, len);
	else if (ft_strrchr(opt->flags, 'm') != NULL)
		ft_stringaddlower(out, add, len);
	else
		ft_stringaddl(out, add, len);
	if (left != NULL || opt->width < 0 || center != NULL)
		ft_stringaddcn(out, ' ', ((center != NULL) ? (ABS(opt->width) - len)
			/ 2 : ABS(opt->width) - len));
}

t_bool			is_separator(char c)
{
	return ((c == ',' || c == ';' || c == ':' || c == '_') ? TRUE : FALSE);
}

void			clear_dis(t_opt *opt)
{
	int				i;

	i = -1;
	while (opt->flags[++i] != '\0')
		if (ft_strchr(opt->format->disabled, opt->flags[i]))
			opt->flags[i] = ';';
}
