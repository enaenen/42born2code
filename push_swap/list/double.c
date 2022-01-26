#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
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

bool	ft_isspace(int c)
{
	return (c == ' ' || c == '\n' || c == '\r'
			|| c =='\v' || c == '\f' || c == '\t');
}
bool	ft_isdigit(int c)
{
	return ('0' <= c || '9' <= c);	
}

bool	ft_atoi(char **str, int *num)
{
	int	sign;
	long long	tmp;
	
	//space 띄기
	//+- 구분
	//숫자아니면 false
	//digit 일동안, 
	//overflow check

	while (ft_isspace(**str))
		++(*str);
	sign = 1;
	if (**str == '+' || **str == '-')
		if (*((*str)++) == '-')
			sign = -1;
	if (!ft_isdigit(**str))
		return (false);
	while (ft_isdigit(**str))
	{
		tmp = (*((*str)++) - '0');
		if (sign < 0)
			tmp = ~(tmp) + 1;
		tmp = *num * 10 + tmp;
		if (INT_MAX < tmp || tmp < INT_MIN)
			return (false);
		*num = (int) tmp;
	}
	return (true);
	
}
int	main(int argc, char **argv)
{
	t_node	*head;
	t_node	*tail;
	int	*inputs;
	int	num;
	size_t	index;

	index = 0;
	if (argc <= 1)
		return -1;
	inputs = malloc(argc * sizeof(int));
	init(&head, &tail);
	while (index <= argc)
	{
		ft_atoi(argv,&inputs[index]);
		push_back(&tail, inputs[index]);
		index++;
	}
	//push_back(&tail, 4);
	print_node(&head, &tail);

}
