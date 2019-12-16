#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* prev;
	struct node* next;
};

struct list {
	node* head;
	node* tail;
	int size=0;
};

void create(list* list)
{
	list->head = (node*)malloc(sizeof(node));
	list->tail = (node*)malloc(sizeof(node));
	list->head->next = list->tail;
	list->tail->prev = list->head;
	list->head->prev = list->tail;
	list->tail->next = list->head;
}

void Finsert(list* list, int data)
{
	node* last = (node*)malloc(sizeof(node));
	last->data = data;
	last->prev = list->head;
	list->head->next = last;
	list->head = last;
	list->size++;
}

void Linsert(list* list, int data)
{
	node* first = (node*)malloc(sizeof(node));
	first->data = data;
	first->prev = list->tail;
	list->tail->prev = first;
	list->tail = first;
	list->size++;
}

void Rprint(list* list)
{
	node* node = list->head;
	int i = 1;
	while (list->size > 0)
	{
		printf("%d node data : %d \n", i++, node->data);
		node = node->prev;
		list->size--;
	}
}

void Lprint(list* list)
{
	node* node = list->head->next->prev;
	int i = 1;
	while (list->size > 0)
	{
		printf("%d node data : %d \n", i++, node->data);
		node = node->prev;
		list->size--;
	}
}

int main()
{
	list list;
	int key;
	create(&list);

		for (int i = 1; i <= 10; i++)
		{
			Linsert(&list, i);
		}
		Lprint(&list);

		for (int i = 35; i <= 45; i++)
		{
			Finsert(&list, i);
		}
		Rprint(&list);

		return 0;
	
}
