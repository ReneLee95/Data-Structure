#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *next;
};

class list{
	private:
		int data;
		int size;
	public:
		node *tail = (node *)malloc(sizeof(node));
		node *head = (node *)malloc(sizeof(node));
		
		void init()
		{
			head = (node *)malloc(sizeof(node));
			tail = (node *)malloc(sizeof(node));
			head->next = tail;
			tail->next = tail;
			size = 0;
		}
		
		void insert(int data)
		{
			node *newNode = (node *)malloc(sizeof(node));
			newNode->data = data;
			head->next = newNode;
			newNode->next = tail;
			tail = newNode;
			size++;
		}
		
		void print()
		{
			node *node = head->next;
			int i = 1;
			
			while(size!=0)
			{
				printf("%d node data : %d\n",i++,node->data);
				node = node->next;
				size--;
			}
		}
};

int main()
{
	int i;
	list list;
	list.init();
	for(i = 1; i<=10; i++)
	{
		list.insert(i);
	}
	
	list.print();
}
