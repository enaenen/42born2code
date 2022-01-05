/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:43:22 by wchae             #+#    #+#             */
/*   Updated: 2021/12/30 17:01:47 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (!lst || !del)
		return ;
	if (!*lst)
		return ;
	buf = NULL;
	while (*lst)
	{
		buf = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buf;
	}
}
