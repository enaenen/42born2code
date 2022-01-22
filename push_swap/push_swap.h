/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchae <wchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 21:51:08 by wchae             #+#    #+#             */
/*   Updated: 2022/01/07 22:24:21 by wchae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct stack_node {
	int data;
	struct stack_node *next;
	struct stack_node *prev;
} stack_node;

typedef struct linkedlist_type {
	int count;
	struct head;
} linkedlist_type;

int	add_element(int data, int index);
int	remove_element(int index);
bool	is_empty();

#endif
