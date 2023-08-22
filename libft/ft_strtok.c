/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/09 21:47:39 by bluque-l          #+#    #+#             */
/*   Updated: 2023/07/11 17:34:32 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdbool.h>

#include <stdbool.h>

char	*ft_strtok(char *str, const char *delimiters)
{
	static char	*next_token;
	char		*token;

	if (str != NULL)
		next_token = str;
	if (next_token == NULL || *next_token == '\0')
		return (NULL);
	while (*next_token != '\0' && ft_strchr(delimiters, *next_token) != NULL)
		++next_token;
	if (*next_token == '\0')
		return (NULL);
	token = next_token;
	while (*next_token != '\0')
	{
		if (ft_strchr(delimiters, *next_token) != NULL)
		{
			*next_token = '\0';
			++next_token;
			break ;
		}
		++next_token;
	}
	return (token);
}
