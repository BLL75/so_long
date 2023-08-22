/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 09:38:12 by bluque-l          #+#    #+#             */
/*   Updated: 2022/05/10 12:55:48 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	idx;

	idx = 0;
	while (idx < n)
	{
		((char *)s)[idx] = 0;
		idx++;
	}
}
/*
 * int main(void)
{
    char s[20] = "Caracola";
    size_t n;

    n = 4;
    ft_bzero(s, n);
}*/
