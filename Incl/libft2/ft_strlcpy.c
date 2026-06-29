/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:46:33 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:57:31 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < size - 1)
		{	
			dest[i] = src[i];
			i++;
		}
	dest[i] = '\0';
	}
	while (src[i])
	{
		i++;
	}
	return (i);
}
/*
#include<stdio.h>
int main()
{
	char *s = "coucou c chaud";
	char s2[56];
	size_t size = 8;
	printf("%zu", ft_strlcpy(s2, s, size));
return(0);
}*/
