#include <iostream>

using namespace std;

struct node{
	int data;
	struct node *left;
	struct node *right;
};

node *root;

void init(int data)
{
	node *newNode = (node *)malloc(sizeof(node));
	root = newNode;
	root->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
}

node *addchild(node *parent,int data)
{
	if((parent->left!=NULL)&&(parent->right!=NULL))
	{
		printf("it's full\n'");
		return 0;
	}
	node *newNode = (node *)malloc(sizeof(node));
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->data = data;
	
	if(parent->left ==NULL)
	{
		parent->left=newNode;
	}
	else if(parent->right ==NULL)
	{
		parent->right = newNode;
	}
	return newNode;
}

void preOrder(node *r)
{
	if(r!=NULL)
	{
		cout<<r->data<<' ';
		if(r->left) preOrder(r->left);
		if(r->right)preOrder(r->right);
	}
}

void inOrder(node *r)
{
	if(r!=NULL)
	{
		inOrder(r->left);
		cout<<r->data<<' ';
		inOrder(r->right);
	}
}

void postOrder(node *r)
{
	if(r!=NULL)
	{
		postOrder(r->left);
		postOrder(r->right);
		cout<<r->data<<' ';
	}
}

int main()
{
	init(1);
	node *L = addchild(root,2);
	node *R = addchild(root,3);
	
	addchild(L,4);

	addchild(L,5);
	addchild(R,6);
	addchild(R,7);
	preOrder(root);
	cout<<endl;
	inOrder(root);
	cout<<endl;
	postOrder(root);
}
