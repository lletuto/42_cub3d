/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_01.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:41:34 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:48:41 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_base(char *base, char letter)
{
	char	c;
	int		i;

	c = '0';
	i = 0;
	while (i < 16)
	{
		base[i] = c;
		c++;
		if (c == ':')
			c = letter;
		i++;
	}
	base[i] = '\0';
	return (base);
}

int	ft_putnbr_hex(unsigned int nbr, int count, char letter)
{
	int		n1;
	char	base[17];

	n1 = 0;
	make_base(base, letter);
	if (nbr >= 16)
	{
		n1 = nbr / 16;
		count = ft_putnbr_hex(n1, count, letter);
		n1 = 0;
		n1 = nbr % 16;
		count = ft_putnbr_hex(n1, count, letter);
	}
	else if (nbr < 16)
		count = ft_putchar(base[nbr], count);
	return (count);
}

static int	ft_putnbr_ptr(void *ptr, int count)
{
	unsigned long	n1;
	char			base[17];
	unsigned long	nbr;

	nbr = (unsigned long)ptr;
	n1 = 0;
	make_base(base, 'a');
	if (nbr >= 16)
	{
		n1 = nbr / 16;
		count = ft_putnbr_ptr((void *)n1, count);
		n1 = 0;
		n1 = nbr % 16;
		count = ft_putnbr_ptr((void *)n1, count);
	}
	else if (nbr < 16)
		count = ft_putchar(base[nbr], count);
	return (count);
}

int	ptr_start(void *ptr, int count)
{
	if (!ptr)
		return (ft_write_line("(nil)", count));
	write(1, "0x", 2);
	count = ft_putnbr_ptr(ptr, count) + 2;
	return (count);
}
