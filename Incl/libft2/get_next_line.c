/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:35:01 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:58:37 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_her(char *s)
{
	free(s);
	s = NULL;
	return (s);
}

static char	*cut_line(char *line)
{
	ssize_t	i;
	char	*left;

	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (!line[i] || !line[i + 1])
		return (NULL);
	left = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!*left)
		left = free_her(left);
	line[i + 1] = '\0';
	return (left);
}

static char	*fill_line(int fd, char *left, char *buf)
{
	char	*temp;
	ssize_t	size;

	size = 1;
	while (size != 0)
	{
		size = read(fd, buf, BUFFER_SIZE);
		if (size == -1)
			return (left = free_her(left));
		else if (size == 0)
			break ;
		buf[size] = '\0';
		if (!left)
			left = ft_strdup("");
		temp = left;
		left = ft_strjoin(temp, buf);
		temp = free_her(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (left);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*left[FD_MAX];
	char		*line;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (BUFFER_SIZE <= 0 || fd < 0 || read(fd, 0, 0) < 0 || fd > 1024)
	{
		left[fd] = free_her(left[fd]);
		buf = free_her(buf);
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line = fill_line(fd, left[fd], buf);
	buf = free_her(buf);
	if (!line)
		return (NULL);
	left[fd] = cut_line(line);
	return (line);
}
// #include <fcntl.h>
// #include <stdio.h>

// int    main(void)
// {
//     int        fd;
//     char    *res;

//     res = " ";
//     fd = open("texte_test.txt", O_RDONLy);
//     while (res != NULL)
//     {
//         res = get_next_line(fd);
//         printf("resultat = %s\n", res);
//         free(res);
//     }
// 	free(res);
//     close(fd);

//     return (0);
// }