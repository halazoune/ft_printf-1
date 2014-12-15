/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaguillo <jaguillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:57:19 by jaguillo          #+#    #+#             */
/*   Updated: 2014/11/04 14:57:21 by jaguillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t			len1;
	size_t			len2;
	char			*str;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = MAL(char, len1 + len2 + 1);
	if (len1 > 0)
		ft_memcpy(str, s1, len1);
	if (len2 > 0)
		ft_memcpy(str + len1, s2, len2);
	str[len1 + len2] = '\0';
	return (str);
}
