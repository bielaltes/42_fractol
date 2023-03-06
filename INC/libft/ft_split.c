/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baltes-g <baltes-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:50:10 by baltes-g          #+#    #+#             */
/*   Updated: 2022/09/26 18:10:41 by baltes-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	sum;
	int	in_word;

	sum = 0;
	in_word = 0;
	while (*s != '\0')
	{
		if (*s != c && in_word == 0)
		{
			++sum;
			in_word = 1;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (sum);
}

static int	word_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**malloc_error(char **new, int j)
{
	while (j >= 0)
	{
		free(new[j]);
		--j;
	}
	free(new);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**new;

	new = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s, c))
	{
		while (s[i] == c)
			i++;
		new[j] = ft_substr(s, i, word_len(s, c, i));
		if (!new[j])
			return (malloc_error(new, j));
		i += word_len(s, c, i);
		++j;
	}
	new[j] = (NULL);
	return (new);
}
