/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vroussea <vroussea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:13:27 by vroussea          #+#    #+#             */
/*   Updated: 2015/12/10 20:21:05 by vroussea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sizetab(char const *s, char c)
{
	size_t	i;
	size_t	word_nb;
	size_t	j;

	i = 0;
	word_nb = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		if (j)
			word_nb++;
	}
	return (word_nb);
}

static char		**ft_strsplitter(char **dst, char c, char const *s)
{
	size_t	idx_word;
	size_t	i;
	size_t	j;

	i = 0;
	idx_word = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i + j] != c && s[i + j])
			j++;
		if (j)
		{
			if (!(dst[idx_word] = ft_strsub(s, i, j)))
			{
				ft_memdel((void **)dst);
				return (NULL);
			}
			i = i + j;
			idx_word++;
		}
	}
	return (dst);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dst;
	size_t	word_nb;

	word_nb = ft_sizetab(s, c);
	if (!(dst = (char **)ft_memalloc(sizeof(*dst) * (word_nb + 1))))
		return (NULL);
	ft_strsplitter(dst, c, s);
	dst[word_nb] = NULL;
	return (dst);
}
