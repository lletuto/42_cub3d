/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:50:44 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:56:27 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*actuel;

	if (!(new))
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	actuel = ft_lstlast(*lst);
	actuel->next = new;
}
