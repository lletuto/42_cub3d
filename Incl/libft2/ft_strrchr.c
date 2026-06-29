/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:18:29 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:57:51 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int tofind)
{
	int				i;
	unsigned char	*sstr;
	unsigned char	stofind;

	sstr = (unsigned char *)str;
	stofind = (unsigned char) tofind;
	i = 0;
	while (sstr[i])
		i++;
	while (i >= 0)
	{
		if (sstr[i] == stofind)
		{
			return ((char *)&sstr[i]);
		}
		i--;
	}
	if (stofind == 0)
		return ((char *)&sstr[i]);
	return ((void *)0);
}

/*#include <string.h>
#include <stdio.h>
int main()
{
	const char *str = "ratatata";
	int tofind = 't';
	printf("%s\n", ft_strrchr(str, tofind));
	printf("%s", strrchr(str, tofind));
	return (0);
}*/
