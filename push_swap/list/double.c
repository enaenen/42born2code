#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	struct	_node	*llink;
	struct	_node	*rlink;
	int	data;
} s_node;


s_node	*make_node(int value)
{
	s_node	*node = (s_node*)malloc(sizeof(s_node));
	node->llink = NULL;
	node->rlink = NULL;
	node->data = value;
	return node;
}

void	init(s_node **head, s_node **tail)
{
	*head = (s_node*)malloc(sizeof(s_node));
	*tail = (s_node*)malloc(sizeof(s_node));
	(*head)->data = 0;
	(*tail)->data = 0;

	(*head)->rlink = *tail;
	(*head)->llink = *head;
	(*tail)->rlink = *tail;
	(*tail)->llink = *head;
}

void	push_back(s_node **tail, int value)
{
	s_node	*new_node = make_node(value);
	s_node	*p;
	p = *tail;
	p->llink->rlink = new_node;
	p->llink = new_node;
	new_node->rlink = p;
}

void	print_node(s_node **head, s_node **tail)
{
	s_node	*p;
	p = *head;
	while (p->rlink != (*tail))
	{
		printf("%d-->", p->data);
		p = p->rlink;
	}
	printf("%d\n", p->data);
}

int	main(int argc, char **argv)
{
	s_node	*head;
	s_node	*tail;


	init(&head, &tail);
	push_back(&tail, 1);
	push_back(&tail, 2);
	push_back(&tail, 3);
	push_back(&tail, 4);
	print_node(&head, &tail);
	return 0;
}
