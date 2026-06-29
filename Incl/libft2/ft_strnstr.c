/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:28:04 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:57:49 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *tofind, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (tofind[i] == 0)
		return ((char *)&str[i]);
	if (str[i] == 0)
		return ((void *)0);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == tofind[j] && (i + j) < len)
		{
			if (tofind[j + 1] == '\0')
				return ((char *)&str[i]);
			j++;
		}
		i++;
	}
	return ((void *)0);
}
/*
//a la compilation, mettre -lbsd
#include <bsd/string.h>
#include <stdio.h>
int main()
{
	const char	*str = "lorem ipsum dolor sit amet";
	const char	*tofind = "ipsumm";
	size_t len = 30;
	char *res = ft_strnstr(str, tofind, len);
	printf("%s\n", res);
//	const char	*str2 = "see ff your ff return ff now ff";
//	const char	*tofind2 = "ff";
//	printf("%s", strnstr(str2, tofind2, len)); 
	return (0);
}*/
