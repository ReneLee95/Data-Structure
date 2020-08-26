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

			if (root[i].data < root[(i + 1) * 2].data && root[(i + 1) * 2].right != NULL) {

				int temp = root[i].data;
				root[i].data = root[(i + 1) * 2].data;
				root[(i + 1) * 2].data = temp;
			}

			if (root[i].data < root[(i * 2) + 1].data && root[(i * 2) + 1].left != NULL) {
				int temp = root[i].data;
				root[i].data = root[(i * 2) + 1].data;
				root[(i * 2) + 1].data = temp;
			}
		}
		i--;
	} while (i != 0);
}

void heapsort(node* root, int size) {
	int i = size - 1;
	int sizeNum = size - 1;
	do {
		int temp = root[0].data;
		root[0].data = root[i].data;
		root[i].data = temp;

		root[i].left = NULL;
		root[i].right = NULL;

		if(i>1) heapify(root, i);
		i--;
	} while (i >= 0);
	
}

int main() {
	node binary[MAX_SIZE];

	int size = 7;
	printf("input data ( size = 7 )\n");
	for (int i = 1; i <= size; i++) {
		int key = 0;
		scanf("%d", &key);
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
	printf("heapify result\n");
	heapify(&binary[1], size);
	print(&binary[1]);
	printf("\n");
	printf("heap result \n");
	heapsort(&binary[1], size);
	printf("\n");
	for (int i = 1; i <= size; i++) {
		printf("%d ", binary[i].data);
	}
}
