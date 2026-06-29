/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:27:06 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:56:59 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (fd > 0)
		write(fd, &c, 1);
}
/*
#include <fcntl.h>
int	main()
{
	int	fd;
	char	c  = 'c';
	fd = open("fichier.txt", O_WRONLy | O_TRUNc | O_cREAT, 0640);
	ft_putchar_fd(c, fd);
	close(fd);
	return(0);
}*/
