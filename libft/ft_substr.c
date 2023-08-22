/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 09:40:25 by bluque-l          #+#    #+#             */
/*   Updated: 2022/05/15 12:44:18 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs2;
	size_t	len_s;
	size_t	cont;

	cont = 0;
	if (!s)
	{
		return (0);
	}
	len_s = ft_strlen(s);
	if (start < len_s)
	{
		cont = len_s - start;
	}
	if (cont > len)
	{
		cont = len;
	}
	subs2 = (char *)malloc(sizeof (char) * (cont + 1));
	if (subs2 == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(subs2, s + start, cont + 1);
	return (subs2);
}
