/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:09:47 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/15 10:35:49 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_overflow(long long res, int sign, char current_char)
{
	if (sign > 0 && res > (INT_MAX - (current_char - '0')) / 10)
	{
		write (1, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
	else if (sign < 0 && (-res < (INT_MIN + (current_char - '0')) / 10))
	{
		write (1, "Error\n", 6);
		exit (EXIT_FAILURE);
	}
}

int	ft_atoi(const char *str)
{
	int			sign;
	long long	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		check_overflow(res, sign, *str);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(res * sign));
}

/*
int main(void)
{
    const char str[] = "   //  bb7777";
    printf("%d", ft_atoi(str));
}
*/
