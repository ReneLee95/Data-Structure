#include <stdio.h>
#include <malloc.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link;
}ListNode;

void display(ListNode *head)
{
	ListNode *p=head;
	while(p!=NULL)
	{
		printf("%d\n",p->data);
		p=p->link;
	}
}

int main()
{
	ListNode *p1 ,*p2;
	p1 = (ListNode *)malloc(sizeof(ListNode));
	p2= (ListNode *)malloc(sizeof(ListNode));
	p1->data = 10;
	p1->link = p2;
	p2->data = 20;
	p2->link = NULL;
	
	display(p1);
	
	return 0;
}
