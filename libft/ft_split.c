/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayusa <ayusa@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:49:40 by ayusa             #+#    #+#             */
/*   Updated: 2025/07/05 18:36:09 by ayusa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		if (str[i] != '\0')
			count++;
		while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t'
			&& str[i] != '\n')
			i++;
	}
	return (count);
}

void	copy_words(char *tab, char *str, int start, int end)
{
	int	j;

	j = 0;
	while (start < end)
		tab[j++] = str[start++];
	tab[j] = '\0';
}

int	find_next_word(char *str, int *start, int *end)
{
	int	i;

	i = *end;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n'))
		i++;
	*start = i;
	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	*end = i;
	return (*start < *end);
}

//start, endをstr全体の変数として使っている。
int	ft_fill_words(char **tab, char *str)
{
	int	i;
	int	word;
	int	start;
	int	end;

	i = 0;
	word = 0;
	start = 0;
	end = 0;
	while (find_next_word(str, &start, &end))
	{
		tab[word] = malloc((end - start + 1) * sizeof(char));
		if (tab[word] == NULL)
		{
			i = 0;
			while (i < word)
				free(tab[i++]);
			free(tab);
			return (0);
		}
		copy_words(tab[word], str, start, end);
		word++;
	}
	tab[word] = NULL;
	return (1);
}

char	**ft_split(char *s)
{
	char	**out;
	int		size;

	size = count_words(s);
	out = malloc((sizeof(char *) * (size + 1)));
	if (!out)
		return (NULL);
	if (!ft_fill_words(out, s))
	{
		free(out);
		return (NULL);
	}
	return (out);
}

//#include <stdio.h>

//int main()
//{
//	char str[] = "111 222 333";
//	char **res = ft_split(str);
//	int i = 0;
//	while (*res[i])
//	{
//		ft_printf("%s\n", res[i]);
//		i++;
//	}
//}
