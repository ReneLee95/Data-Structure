#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256

typedef struct node {
	struct node* next;
	int data;
	int size;
}node;

typedef struct Tree {
	node nodes;
	struct nodes* input;
	struct Tree* left;
	struct Tree* right;
	int data;
}Tree;

node* root = NULL;
int size = 0;

node* insert(node* root, int data) {
	if (root == NULL) {
		root = (node*)malloc(sizeof(node));
		root->next = NULL;
		root->data = data;
		size++;
		return root;
	}
	else {
		root->next = insert(root->next, data);
		return root;
	}
}

void print(Tree* tree) {
	if (tree) {
		printf("[ %d ] ", tree->data);
		print(tree->left);
		print(tree->right);
	}
}

int main() {
	int inputNum = 0;
	printf("input data num : ");
	scanf_s("%d", &inputNum);
	Tree binaryTree[MAX_SIZE];
	printf("\n");
	for (int i = 1; i <= inputNum; i++) {
		int key = 0;
		printf("%d key : ", i);
		scanf_s("%d", &key);
		root = insert(root, key);
		binaryTree[i].data = root->data;
		binaryTree[i].left = NULL;
		binaryTree[i].right = NULL;
		root = root->next;

		if (i % 2 == 0) {
			binaryTree[i / 2].left = &binaryTree[i];
		}
		else {
			binaryTree[i / 2].right = &binaryTree[i];
		}
	}

	print(&binaryTree[1]);
}
