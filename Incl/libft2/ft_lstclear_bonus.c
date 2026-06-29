/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-tuto <lle-tuto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:14:59 by lle-tuto          #+#    #+#             */
/*   Updated: 2025/09/24 16:56:31 by lle-tuto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*actuel;
	t_list	*temp;

	actuel = *lst;
	if (!actuel)
		return ;
	while (actuel)
	{
		temp = actuel;
		actuel = actuel->next;
		ft_lstdelone(temp, del);
	}
	*lst = NULL;
}
