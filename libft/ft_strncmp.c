/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 10:28:42 by bluque-l          #+#    #+#             */
/*   Updated: 2022/05/12 10:43:44 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	b1 = (unsigned char *)s1;
	b2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (b1[i] != b2[i] || b1[i] == 0 || b2[i] == 0)
			return (b1[i] - b2[i]);
		i++;
	}
	return (0);
}
/*
int main(void)
{
    char *s1 = "Hola";
    char *s2 = "hola";
    size_t n;

    n = 3;
    printf("%d\n", ft_strncmp(s1, s2, n));
}
*/
