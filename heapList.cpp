#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 256

typedef struct node {
   struct node *left;
   struct node *right;
   int data;
}node;

typedef struct tree {
   struct tree *next;
   int data;
}tree;

tree *root = NULL;
int size = 1;

tree *insert(tree *root, int data) {
   if(root == NULL) {
      root = (tree *)malloc(sizeof(tree));
      root->next = NULL;
      root->data = data;
      size++;
      return root;
   }
   else {
      root->next = insert(root->next,data);
      return root;
   }
}

void print(node *root) {
   if(root) {
      printf("%d ",root->data);
      print(root->left);
      print(root->right);
   }
}

void swap(int *a,int *b) {
   int *temp = a;
   a = b;
   b = temp;
}

void heapify(node *root,int size) {

   int i = size;
   int index = size-1;
   int count = 0;
   do {
   	if(root[size].data > root[0].data) {
   		swap(&root[size].data,&root[0].data);
	   }
	if(root[(size/2)-1+(size%2)].data <root[size].data) {
		swap(&root[(size/2)-1+(size%2)].data, &root[size].data);
	}
	size--;
	count++;
   }while(count != i-3);
   
   if(root[0].data < root[0].left->data) {
   	swap(&root[0].data, &root[0].left->data);
   }
   else if(root[0].data < root[0].right->data) {
   	swap(&root[0].data, &root[0].right->data);
   }
   else {
   	return;
   }
}

int main() {
   node binary[MAX_SIZE];
   
   int size = 7;
   printf("input data\n");
   for(int i = 1; i<=size; i++) {
      int key = 0;
      scanf("%d",&key);
      root = insert(root,key);
      binary[i].data = root->data;
      binary[i].left = NULL;
      binary[i].right = NULL;
      
      root = root->next;
      
      if(i%2 == 0) {
         binary[i/2].left = &binary[i];
      }
      else {
         binary[i/2].right = &binary[i];
      }
   }
   printf("origin\n");
   print(&binary[1]);
   printf("\n");
   heapify(&binary[1],size);
   
   printf("heapify\n");
   print(&binary[1]);
}
