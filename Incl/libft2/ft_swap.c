/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:41:37 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:57:59 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include "libft.h"

void	ft_swap(long long *a, long long *b)
{
	long long	c;

	c = *a;
	*a = *b;
	*b = c;
}
/*int	main(void)
{
	int	a_var;
	int	b_var;
	int*	a;
	int*	b;

	a_var = 3;
	b_var = 9;
	a = &a_var;
	b = &b_var;
	printf (" la variable a est egale a %d et la
		variable b est egale a %d.", a_var, b_var );
	ft_swap(a, b);
	printf (" la variable a est egale a %d et la
		variable b est egale a %d.", a_var, b_var );
}*/
