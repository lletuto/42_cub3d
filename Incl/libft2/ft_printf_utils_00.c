/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_00.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:20:50 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:48:41 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int count)
{
	write(1, &c, 1);
	count++;
	return (count);
}

int	ft_write_line(char *s, int count)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		count = ft_putchar(s[i], count);
		i++;
	}
	return (count);
}

int	ft_putnbr(int nb, int count)
{
	int	n1;

	if (nb == -2147483648)
	{
		count = ft_putchar('-', count);
		count = ft_putchar('2', count);
		count = ft_write_line("147483648", count);
	}
	else if (nb < 0)
	{
		count = ft_putchar('-', count);
		nb = -nb;
		count = ft_putnbr(nb, count);
	}
	else if (nb < 10)
		count = ft_putchar(nb + '0', count);
	else if (nb >= 10)
	{
		n1 = nb / 10;
		count = ft_putnbr(n1, count);
		n1 = nb % 10;
		count = ft_putnbr(n1, count);
	}
	return (count);
}

int	ft_putnbr_un_int(unsigned int nb, int count)
{
	int	n1;

	if (nb < 10)
	{
		count = ft_putchar(nb + '0', count);
	}
	else if (nb >= 10)
	{
		n1 = nb / 10;
		count = ft_putnbr_un_int(n1, count);
		n1 = nb % 10;
		count = ft_putnbr_un_int(n1, count);
	}
	return (count);
}
