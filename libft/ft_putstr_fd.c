/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:46:43 by bluque-l          #+#    #+#             */
/*   Updated: 2022/05/13 16:39:35 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
/*int main(void)
{
   const char* cadena = "Hola, mundo";
   int file = open ("file_putstr", O_CREAT|O_WRONLY,0744);
  
   if (file == -1)
   {
       printf("Error con File");
       return (0);  
   }

   ft_putstr_fd(str, file);
   close(file);
   return 0;
}
*/
