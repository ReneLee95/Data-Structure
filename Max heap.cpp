#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256

typedef struct node {
	struct node* left;
	struct node* right;
	int data;
}node;

typedef struct tree {
	struct tree* next;
	int data;
}tree;

tree* root = NULL;
int size = 1;

tree* insert(tree* root, int data) {
	if (root == NULL) {
		root = (tree*)malloc(sizeof(tree));
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

void print(node* root) {
	if (root) {
		printf("%d ", root->data);
		print(root->left);
		print(root->right);
	}
}

void swap(int *a, int *b) {
	int *temp = a;
	a = b;
	b = temp;
}

void heapify(node* root, int size) {
	int i = size - 1;
	do {
		if (root[0].data < root[i].data) {
			int temp = root[0].data;
			root[0].data = root[i].data;
			root[i].data = temp;
		}
		if (root[i].data > root[(i - 1) / 2].data) {	
			int temp = root[i].data;
			root[i].data = root[(i - 1) / 2].data;
			root[(i - 1) / 2].data = temp;
		}
		if (i <= (size - 1) / 2) {

			if (root[i].data < root[(i + 1) * 2].data) {

				int temp = root[i].data;
				root[i].data = root[(i + 1) * 2].data;
				root[(i + 1) * 2].data = temp;
			}

			if (root[i].data < root[(i * 2) + 1].data) {
				int temp = root[i].data;
				root[i].data = root[(i * 2) + 1].data;
				root[(i * 2) + 1].data = temp;
			}
		}
		i--;
	} while (i != 0);
	print(&root[0]);
}

int main() {
	node binary[MAX_SIZE];
	printf("size input : ");
	int size = 0;
    scanf_s("%d",&size);
	printf("input data\n");
	for (int i = 1; i <= size; i++) {
		int key = 0;
		scanf_s("%d", &key);
		root = insert(root, key);
		binary[i].data = root->data;
		binary[i].left = NULL;
		binary[i].right = NULL;

		root = root->next;

		if (i % 2 == 0) {
			binary[i / 2].left = &binary[i];
		}
		else {
			binary[i / 2].right = &binary[i];
		}
	}
	printf("origin\n");
	print(&binary[1]);
	printf("\n");
	heapify(&binary[1], size);

	//printf("heapify\n");
	//print(&binary[1]);
}
