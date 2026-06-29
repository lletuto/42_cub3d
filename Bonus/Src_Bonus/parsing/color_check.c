/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:08:58 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/30 18:28:13 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

static void	digit_block(char *rgbline, int *i, t_game *game)
{
	int	flag;

	flag = 0;
	if (!ft_isdigit(rgbline[*i]))
	{
		free(rgbline);
		free_exit("Error\nOh no, you messed up with the colors !\n", game, 1);
	}
	while (rgbline[*i] && ft_isdigit(rgbline[*i]))
	{
		(*i)++;
		flag++;
	}
	if (flag > 3)
	{
		free(rgbline);
		free_exit("Error\nOh no, you messed up with the colors !\n", game, 1);
	}
}

static void	count_numbers(char *rgbline, t_game *game)
{
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	while (rgbline[i])
	{
		if ((rgbline[i + 1] && (ft_isdigit(rgbline[i]) && (rgbline[i + 1] == ' '
						|| rgbline[i + 1] == ','))) || (!rgbline[i + 1]
				&& ft_isdigit(rgbline[i])))
			numbers++;
		i++;
	}
	if (numbers > 3)
	{
		free(rgbline);
		free_exit("Error\nOh no, you messed up with the colors !\n", game, 1);
	}
}

void	valid_color_value(char *rgbline, t_game *game)
{
	int	i;

	i = 0;
	count_numbers(rgbline, game);
	while (rgbline[i])
	{
		while (rgbline[i] && rgbline[i] == ' ')
			i++;
		digit_block(rgbline, &i, game);
		while (rgbline[i] && rgbline[i] == ' ')
			i++;
		if (rgbline[i] == ',')
		{
			i++;
			if (rgbline[i] == '\0')
			{
				free(rgbline);
				free_exit("Error\nOh no, you messed up with the colors !\n",
					game, 1);
			}
		}
	}
}
