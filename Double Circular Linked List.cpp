#include <stdio.h>
#include <stdlib.h>

int countlist = 0;

typedef struct node {
	struct node *next;
	struct node *prev;
	int data;
}node;

typedef struct List {
	struct node *head;
	int count;
}List;

node *createnode() {
	node *nullnode = (node *)malloc(sizeof(node));
	
	nullnode = NULL;
}

List *createinit() {
	List *list = (List *)malloc(sizeof(List));
	
	if(list->head == NULL) {
		printf("err\n");
	}
	else {
		list->head = NULL;
		list->count = 0;
	}
	printf("success createinit\n");
	
	return list;
}

void pushdata(List *list,int countlist, int data) {
	node *newNode = (node *)malloc(sizeof(node));
	node *preNode = list->head;
	newNode->data = data;
	
	if(list->count == 0) {
		list->head = newNode;
		list->head->next = newNode;
		newNode->prev = list->head;
		list->count++;
	}
	else {
		for(int i =0; i<countlist; i++) {
			preNode = preNode->prev;
		}
		
		newNode->next = preNode->next;
		newNode->prev = preNode;
		preNode->next = newNode;
		newNode->next->prev = newNode;
		
		list->count++;
	}
	printf("success pushdata\n");
}

void delnode(List *list,int index) {
	printf("count : %d\n",list->count);
	if(list->count <index) {
		printf("del err\n");
		return;
	}
	
	node *delNode = list->head;
	
	if(list->count == 0) {
		printf("none delete node\n");
	}
	else {
		for(int i =list->count; i>1; i--) {
			delNode = delNode->prev;
			printf("[cat : %d ] \n",delNode->data);
		}
		
		delNode->prev->next = delNode->next;
		delNode->next->prev = delNode->prev;
		
		free(delNode);
		
		list->count--;
	}
}

void search(List *list, int num) {
	node *curNode = list->head;
	int cat = 0;
	int i;
	
	for(i = list->count, curNode = list->head; i>0; i--, curNode = curNode->next) {
		if(curNode->data == num) {
			printf("find index : %d \n",i);
			cat++;
		}
	}
	if(cat == 0) {
		printf("not found index\n");
		return;
	}
}

void print(List *list) {
	
	printf("test : %d\n",list->head->data);
	int i;
	node *curNode;
		
	for(i = list->count, curNode = list->head; i > 0; i--,curNode = curNode->prev) {
		printf("[ %d ] ",curNode->data);
	}
}

void reverse(List *list) {
	int i;
	node *curNode;
		
	for(i = list->count, curNode = list->head->next; i > 0; i--,curNode = curNode->next) {
		printf("[ %d ] ",curNode->data);
	}
}

void clear(List *list) {
	printf("count : %d\n",list->count);
	
	node *delNode = list->head;
	
	if(list->count == 0) {
		printf("none delete node\n");
	}
	else {
		for(int i =list->count; i>1; i--) {
			delNode = delNode->prev;
			printf("[cat : %d ] \n",delNode->data);
		}
		delNode->prev->next = delNode->next;
		delNode->next->prev = delNode->prev;
		free(delNode);
		list->count--;
		
		countlist = list->count;
		
		if(list->count >0) return clear(list);
	}
	printf("success? : %d\n",list->count);
}

int main() {
	List *list = createinit();
	
	for(int i =0; i<10; i++) {
		pushdata(list,countlist++,i);
		countlist++;
	}
	printf("0\n");
	list->count = 0;
	print(list);
	printf("100\n");
	list->count = 10;
	print(list);
	printf("\n");
	search(list,4);
	printf("\n\n");
	reverse(list);
	printf("\n\n");
	
	search(list,4);
	printf("\n");
	printf("clear\n");

	clear(list);
	print(list);
	printf("countlist : %d\n",countlist);
	
	for(int i =0; i<10; i++) {
		pushdata(list,countlist++,i);
		countlist++;
	}
	printf("\n\n");
	print(list);
	return 0;
}
