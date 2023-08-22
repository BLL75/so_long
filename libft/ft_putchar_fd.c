/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:43:33 by bluque-l          #+#    #+#             */
/*   Updated: 2022/05/10 13:46:38 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main(void)
{
   int file = open ("file_putchar", O_CREAT|O_WRONLY,0644);
   if (file == -1)
   {
       printf("Error con File2");
       return (0);
   }
   ft_putchar_fd('c', fichero);
   close(file);
   return 0;
}
*/
