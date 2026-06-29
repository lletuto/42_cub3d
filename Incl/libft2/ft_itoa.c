/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:26:00 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:48:41 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	lenb(int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		len++;
	while (nb != 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	len;
	unsigned int	n2;
	char			*asci;

	len = lenb(n);
	asci = malloc(len + 1);
	if (!asci)
		return (NULL);
	asci[len] = '\0';
	if (n == 0)
		asci[0] = '0';
	if (n < 0)
	{
		asci[0] = '-';
		n2 = -n;
	}
	else
		n2 = n;
	while (n2 > 0)
	{
		asci[len - 1] = (n2 % 10) + '0';
		n2 = n2 / 10;
		len--;
	}
	return (asci);
}
/*
#include <stdio.h>

int main ()
{
	int	n = 0;
	n = -2147483648;
	char *str = NULL;
	str = ft_itoa(n);
	printf("str = %s", str);
	free(str);
	return(0);
}*/
