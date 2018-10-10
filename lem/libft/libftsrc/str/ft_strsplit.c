/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vzomber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:07:57 by vzomber           #+#    #+#             */
/*   Updated: 2017/12/01 19:30:38 by vzomber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	t_pack	help_func(t_pack *struc)
{
	size_t	len;
	size_t	j;

	while (struc->s[struc->i] == struc->c && struc->s[struc->i])
		struc->i++;
	if (!(struc->arr[struc->k] = (char*)malloc(sizeof(char) *
					(len = ft_chars(&struc->s[struc->i], struc->c)) + 1)))
		return (*struc);
	j = 0;
	while (j < len)
	{
		struc->arr[struc->k][j] = struc->s[struc->i];
		struc->i++;
		j++;
	}
	struc->arr[struc->k++][j] = '\0';
	struc->i++;
	return (*struc);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		wordsnum;
	t_pack	struc;

	if (!s || !(arr = (char**)malloc(sizeof(char*) * (ft_wordnum(s, c) + 1))))
		return (NULL);
	struc.k = 0;
	struc.i = 0;
	wordsnum = ft_wordnum(s, c);
	struc.s = (char *)s;
	struc.c = c;
	struc.arr = arr;
	while (struc.k < wordsnum)
		struc = help_func(&struc);
	arr[struc.k] = NULL;
	return (arr);
}
