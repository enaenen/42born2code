/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 04:35:23 by wchae             #+#    #+#             */
/*   Updated: 2021/12/30 17:01:32 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*buf;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		buf = ft_lstlast(*lst);
		buf->next = new;
	}
}
