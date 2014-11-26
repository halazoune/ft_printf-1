/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 13:34:31 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/26 13:34:32 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

t_string		*ft_format(const char *format, ...)
{
	t_string		*output;
	va_list			ap;

	output = ft_stringnew();
	va_start(ap, format);
	formater(output, (char*)format, &ap);
	va_end(ap);
	return (output);
}

int				ft_printf(const char *format, ...)
{
	t_string		*output;
	va_list			ap;
	int				tmp;

	output = ft_stringnew();
	va_start(ap, format);
	formater(output, (char*)format, &ap);
	va_end(ap);
	write(1, output->content, output->length);
	tmp = output->length;
	free(output->content);
	free(output);
	return (tmp);
}

int				ft_printf_fd(const int fd, const char *format, ...)
{
	t_string		*output;
	va_list			ap;
	int				tmp;

	output = ft_stringnew();
	va_start(ap, format);
	formater(output, (char*)format, &ap);
	va_end(ap);
	write(fd, output->content, output->length);
	tmp = output->length;
	free(output->content);
	free(output);
	return (tmp);
}
