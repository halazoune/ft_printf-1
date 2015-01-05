/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftutils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 17:08:10 by jaguillo          #+#    #+#             */
/*   Updated: 2015/01/05 17:45:15 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_uint			ft_strtrim2(char *str, t_uint len, const char *trim)
{
	t_uint			i;

	i = 0;
	while (ft_strchr(trim, str[i]) != NULL)
		i++;
	ft_memmove(str, str + i, len - i);
	i = len - i - 1;
	while (ft_strchr(trim, str[i]) != NULL)
		i--;
	ft_bzero(str + i + 1, len - i);
	return (i + 1);
}

int				ft_atoin(const char *str, int len)
{
	int				nb;
	int				sign;

	sign = 1;
	nb = 0;
	if (*str == '-')
	{
		sign = -1;
		str++;
		len--;
	}
	else if (*str == '+')
	{
		len--;
		str++;
	}
	while (*str >= '0' && *str <= '9' && len-- > 0)
		nb = nb * 10 + (*(str++) - '0');
	return (nb * sign);
}