#include <iostream>

using namespace std;

struct node{
	int data;
	int front,rear;
};

class cirQ{
	public:
		int len;
		node *node = (node*)malloc(sizeof(node));
		cirQ()
		{
			node->front =len-1;
			node->rear =len-1;
		}
};

int main()
{
	
}
