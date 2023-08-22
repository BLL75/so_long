/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:53:28 by bluque-l          #+#    #+#             */
/*   Updated: 2022/05/10 13:50:28 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}
/*
int main(void)
{ 
   const char* cadena = "Hola, mundo";
   int file = open ("file_putendl", O_CREAT|O_WRONLY,0844);

   if (file == -1)
   {
        printf("Error al abrir fichero:");
        exit(1);
   }
   if (file2 == -1)
   {
       printf("Error con File2");
       return (0);
   }
   ft_putendl_fd(str, file);
   close(file);
   return 0;
}
*/
