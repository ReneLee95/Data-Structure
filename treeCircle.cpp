#include <iostream>
#include <cstdio>

using namespace std;

class Node{
	public:
		char data;
		Node *parent;
		Node *brother;
		Node *child;
		Node() { }
		Node(char data) : data(data),parent(0),brother(0),child(0) { }
		
		~Node()
		{
			parent =NULL;
			brother = NULL;
			child = NULL;
		}
};

void insertNode(Node *R, char data)
{
	Node *newNode = new Node(data);
	newNode->parent = R;
	
	Node * cur = R->child;
	
	if(cur == 0) R->child = newNode;
	while(cur !=0)
	{
		if(cur->brother ==0)
		{
			cur->brother = newNode;
			break;
		}
		cur = cur->brother;
	}
}

void deleteNode (Node *R, char searchNode)
{
	if(R =0) return;
	
	if(R->data == searchNode)
	{
		Node *parent = R->parent;
		
		if(parent->child ==R)
		{
			Node *temp = R;
			parnet->child = R->brotehr;
			delete temp;
		}
		else
		{
			Node *cur = parent->child;
			Node *pre = 0;
			while(cur !=0)
			{
				if(parent->child == R)
				{
					Node *temp = R;
					parent->child = R->brother;
					delete temp;
					break;
				}
			
				pre = cur;
				cur = cur->brother;
			}
		}
	}
	
	if(R->brother!=0) deleteNode(R->brother,searchNode);
	if(R->child !=0) deleteNode(R->child,searchNode);
	
	return;
}

void deleteTree(Node *R)
{
	if(R==0) return;
	
	deleteTree(R->brother);
	deleteTree(R->child);
	delete R;
	R = 0;
}

