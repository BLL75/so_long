/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 12:39:06 by bluque-l          #+#    #+#             */
/*   Updated: 2022/04/23 12:39:51 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			idx;
	unsigned char	*ptr;

	idx = 0;
	ptr = (unsigned char *)s;
	while (idx < n)
	{
		*ptr = (unsigned char)c;
		idx++;
		ptr++;
	}
	return (s);
}
/*int main(void)
{
    char *str[50] = "Probando el tema del memset";
    size_t n;

    n = 5;

    ft_memset(str + 5, 'T', n);

}*/
