#include <stdio.h>
#include <stdlib.h>

int oneCheck = 0;
int twoCheck = 0;
int threeCheck = 0;
int index = 0;
int onecount[3];
int twocount[3];
int threecount[3];
int black = 0;

typedef struct node {
	int one;
	int two;
	int three;
	struct node* next;
}node;

typedef struct checknode {
	int total;
	int checkindex;
	int checkThree;
	int checkTwo;
	struct checknode* next;
	struct checknode* prev;
}checknode;

typedef struct List {
	struct node* head;
	struct checknode* tail;
	int count;
	int count2;
}List;


List* init() {
	List* list = (List*)malloc(sizeof(List));
	if (list == NULL) {
		printf("err\n");
	}
	else {
		list->head = NULL;
		list->tail = NULL;
		list->count = 0;
		list->count2 = 0;
		return list;
	}
}

void insert(List *list, int data1, int data2, int data3) {
	node* newNode = (node*)malloc(sizeof(node));
	node* preNode = list->head;
	newNode->one = data1;
	newNode->two = data2;
	newNode->three = data3;

	if (list->count == 0) {
		newNode->next = newNode;
		list->head = newNode;
		list->count++;
	}
	else {
		for (int i = 0; i < list->count; i++) {
			preNode = preNode->next;
		}
		newNode->next = preNode->next;
		preNode->next = newNode;
		list->count++;
	}
}

void checking(List* list,int *check) {
	node* curNode = list->head;
	if (list->count == 0) return;
	else {
		oneCheck += list->head->one;
		twoCheck += list->head->two;
		threeCheck += list->head->three;
		check[0] = oneCheck;
		check[1] = twoCheck;
		check[2] = threeCheck;

		list->head = list->head->next;
		list->count--;
		free(curNode);
		checking(list,check);
	}
}

void insert2(List* list,int *check) {
	checknode* newCheck = (checknode*)malloc(sizeof(checknode));
	checknode* preCheck = list->tail;
	newCheck->checkindex = index + 1;
	newCheck->checkThree = threecount[index];
	newCheck->checkTwo = twocount[index];
	newCheck->total = check[index];
	if (list->count2 == 0) {
		newCheck->next = newCheck;
		newCheck->prev = newCheck;
		list->tail = newCheck;
		list->count2++;
		index++;
	}
	else {
		for (int i = 0; i < list->count2; i++) {
			preCheck = preCheck->next;
		}
		newCheck->next = preCheck->next;
		newCheck->prev = preCheck;
		preCheck->next = newCheck;
		newCheck->next->prev = newCheck;
		list->count2++;
		index++;
	}
}

void print(List* list) {
	int i;
	printf("???? %d\n", list->count2);
	for (i = 0, list->tail; i < list->count2; i++, list->tail = list->tail->prev) {
		printf("index : %d\n", list->tail->checkindex);
		printf("total : %d\n", list->tail->total);
		printf("threecount : %d\n", list->tail->checkThree);
		printf("twocount : %d\n", list->tail->checkTwo);
	}
}

void resultchecking(List* list) {
	checknode* curCheck = list->tail;
	checknode* nextCheck = list->tail->prev;
	if (list->count2 == 0) return;
	else {
		if (curCheck->total < nextCheck->total) {
			list->tail = nextCheck;
		}
		else if (curCheck->total == nextCheck->total) {
			if (curCheck->checkThree > nextCheck->checkThree) {
				list->tail = curCheck;
				black = 0;
			}
			else if (curCheck->checkThree < nextCheck->checkThree) {
				list->tail = nextCheck;
				black = 0;
			}
			else {
				if (curCheck->checkTwo > nextCheck->checkTwo) {
					list->tail = curCheck;
					black = 0;
				}
				else if (curCheck->checkTwo < nextCheck->checkTwo) {
					list->tail = nextCheck;
					black = 0;
				}
				else {
					black++;
					if (list->count2 > 1) list->tail = list->tail->next;
				}
			}
		}
		list->count2--;
		resultchecking(list);
	}
}

int main() {
	int countcheck = 0;
	int one, two, three;
	List* list = init();

	int* check = (int*)malloc(sizeof(int) * 3);

	for (int i = 0; i < 3; i++) {
		onecount[i] = 0;
		twocount[i] = 0;
		threecount[i] = 0;
		check[i] = 0;
	}
	scanf("%d", &countcheck);
	for (int i = 0; i < countcheck; i++) {
		scanf("%d %d %d", &one, &two, &three);

		if (one == 3) threecount[0] = threecount[0]+1;
		else if (one == 2) twocount[0] = twocount[0]+1;
		else onecount[0] = onecount[0] + 1;

		if (two == 3) threecount[1] = threecount[1] + 1;
		else if (two == 2) twocount[1] = twocount[1] + 1;
		else onecount[1] = onecount[1] + 1;

		if (three == 3) threecount[2] = threecount[2] + 1;
		else if (three == 2) twocount[2] = twocount[2] + 1;
		else onecount[2] = onecount[2] + 1;
		
		insert(list, one, two, three);

	}

	checking(list,check);

	for (int i = 0; i < 3; i++) {
		insert2(list, check);
	}

	resultchecking(list);

	if (black != 0) {
		printf("0 %d", list->tail->total);
	}
	else {
		printf("%d %d", list->tail->checkindex, list->tail->total);
	}
	
	for(int i = 0; i<3; i++) {
		checknode *returnNode = list->tail;
		list->tail = list->tail->next;
		free(returnNode);
	}

	free(list);
	return 0;
}
