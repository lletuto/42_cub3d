/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:38:20 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:48:41 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	all_of_it(unsigned int *count, const char s, int *i, va_list *args)
{
	if (s == '%')
		*count = ft_putchar('%', *count);
	else if (s == 's')
		*count = ft_write_line(va_arg(*args, char *), *count);
	else if (s == 'p')
		*count = ptr_start(va_arg(*args, void *), *count);
	else if (s == 'u')
		*count = ft_putnbr_un_int(va_arg(*args, int), *count);
	else if (s == 'c')
		*count = ft_putchar((char)va_arg(*args, int), *count);
	else if (s == 'x')
		*count = ft_putnbr_hex(va_arg(*args, int), *count, 'a');
	else if (s == 'x')
		*count = ft_putnbr_hex(va_arg(*args, int), *count, 'A');
	else if (s == 'd' || s == 'i')
		*count = ft_putnbr(va_arg(*args, int), *count);
	(*i)--;
	return (*count);
}

int	ft_printf(const char *s, ...)
{
	int				i;
	va_list			args;
	unsigned int	count;

	count = 0;
	i = 0;
	if (!s)
		return (-1);
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			all_of_it(&count, s[i], &i, &args);
			i++;
		}
		else
			count = ft_putchar(s[i], count);
		i++;
	}
	va_end(args);
	return (count);
}

/*
#include <stdio.h>
int	main(void)
{
	int a = 956;
	int b = -789;

	printf("%i\n",ft_printf(0));
	printf("%i\n",ft_printf(0));
	
	printf("%i\n",ft_printf("coucou l'evaluateur.ice\n"));
	printf("%i\n",printf("coucou l'evaluateur.ice\n"));

	printf("%i\n",printf("%s", "J'adore l'informatique !\n"));
	printf("%i\n",ft_printf("%s", "J'adore l'informatique !\n"));

	printf("%i\n",printf("%c%c\n", '<', '3'));
	printf("%i\n",ft_printf("%c%c\n", '<', '3'));

	printf("%i\n",printf("%p\n", &a));
	printf("%i\n",ft_printf("%p\n", &a));

	printf("%i\n",printf("%u  %u\n", a, b));
	printf("%i\n",ft_printf("%u  %u\n", a, b));

	printf("%i\n",printf("%x  %x\n", a, b));
	printf("%i\n",ft_printf("%x  %x\n", a, b));

	printf("%i\n",printf("%d  %i\n", a, b));
	printf("%i\n",ft_printf("%d  %i\n", a, b));
}*/
