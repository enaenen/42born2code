#include <stdio.h>
#include <stdlib.h>

typedef struct s_node
{
	struct	s_node	*llink;
	struct	s_node	*rlink;
	int	data;
}	t_node;


t_node	*make_node(int value)
{
	t_node	*node = (t_node*)malloc(sizeof(t_node));
	node->llink = NULL;
	node->rlink = NULL;
	node->data = value;
	return node;
}

void	init(t_node **head, t_node **tail)
{
	*head = (t_node*)malloc(sizeof(t_node));
	*tail = (t_node*)malloc(sizeof(t_node));
	(*head)->data = 0;
	(*tail)->data = 0;

	(*head)->rlink = *tail;
	(*head)->llink = *head;
	(*tail)->rlink = *tail;
	(*tail)->llink = *head;
}

void	push_back(t_node **tail, int value)
{
	t_node	*new_node = make_node(value);
	t_node	*p;
	p = *tail;
	p->llink->rlink = new_node;
	p->llink = new_node;
	new_node->rlink = p;
}

void	print_node(t_node **head, t_node **tail)
{
	t_node	*p;
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
	t_node	*head;
	t_node	*tail;

	init(&head, &tail);
	push_back(&tail, 1);
	push_back(&tail, 2);
	push_back(&tail, 3);
	push_back(&tail, 4);
	print_node(&head, &tail);

}
