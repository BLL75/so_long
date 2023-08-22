/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bluque-l <bluque-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:41:32 by bluque-l          #+#    #+#             */
/*   Updated: 2022/05/15 12:38:15 by bluque-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	const char	*initial_char;

	initial_char = str;
	while (*str)
		str++;
	return (str - initial_char);
}

static int	ft_count_words(char const *s, char c)
{
	int	words;
	int	control;

	words = 0;
	control = 0;
	while (*s)
	{
		if (*s != c && control == 0)
		{
			control = 1;
			words++;
		}
		else if (*s == c)
		{
			control = 0;
		}
		s++;
	}
	return (words);
}

static char	*ft_word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || split == NULL)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = ft_word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
/*int main(void)
{
	char **new;
	int		i;

	i = 0;
	new  = ft_split("Utilizando el espacio se ve mucho mejor", ' ');
	while (new[i] != '\0')
	{
		printf("%s\n", new[i]);
		i++;
	}

}
*/
